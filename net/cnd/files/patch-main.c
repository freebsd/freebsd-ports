--- main.c.orig	2005-04-22 16:13:05 UTC
+++ main.c
@@ -41,14 +41,13 @@
 #include <sys/time.h>
 #include <stdarg.h>
 #include <errno.h>
+#include <ifaddrs.h>
 
 #include <sys/socket.h>
 #include <net/if.h>
-#include <net/if_var.h>
 #include <net/if_types.h>
 
 #include <fcntl.h>
-#include <kvm.h>
 
 #include <curses.h>
 
@@ -59,21 +58,10 @@
 #define DISP_BYTE 1
 int disp_format = DISP_BYTE;
 
-struct nlist netl[] = { {"_ifnet"}, {""} };
-kvm_t *kvmd;
-char *nlistf = NULL;
-char *memf = NULL;
-#if __FreeBSD_version >= 501113
-char name[IFNAMSIZ];
-#else
-char name[32];
-char tname[16];
-#endif
-unsigned long ifnetaddr = 0;
-
 unsigned long long in_total = 0;
 unsigned long long out_total = 0;
 char *in_dev = NULL;
+char name[IFNAMSIZ];
 
 int winw,winh;
 WINDOW *mainw;
@@ -173,7 +161,6 @@ void screen_init() {
 	getmaxyx(stdscr,winh,winw);
 	if(winh < 20 || winw < 20) {
 		endwin();
-		kvm_close(kvmd);
 		fprintf(stderr,"Screen size is too small, sorry\n");
 		exit(1);
 	}
@@ -241,35 +228,37 @@ void screen_check() {
 	return;
 }
 
-/* read kernel memory, based off of netstat */
-int kread(u_long addr,char *buf,int size) {
-	if(kvmd != NULL) {
-		if(kvm_nlist(kvmd,netl) < 0) {
-			if(nlistf)
-				fprintf(stderr,"error, kvm_nlist(%s): %s\n",nlistf,kvm_geterr(kvmd));
-			else
-				fprintf(stderr,"error, kvm_nlist: %s\n",kvm_geterr(kvmd));
-			exit(1);
-		}
-		
-		if(netl[0].n_type == 0) {
-			if(nlistf)
-				fprintf(stderr,"error, no namelist: %s\n",nlistf);
-			else
-				fprintf(stderr,"error, no namelist\n");
-			exit(1);
-		}
-	} else {
-		fprintf(stderr,"error, kvm not available\n");
+void readstat(u_long *ibytes, u_long *obytes)
+{
+	struct ifaddrs *ifap, *ifa;
+
+	if (getifaddrs(&ifap) != 0) {
+		fprintf(stderr,"getifaddrs()\n");
 		exit(1);
 	}
-	if(!buf)
-		return 0;
-	if(kvm_read(kvmd,addr,buf,size) != size) {
-		fprintf(stderr,"error, %s\n",kvm_geterr(kvmd));
+
+	for (ifa = ifap; ifa; ifa = ifa->ifa_next) {
+		if (ifa->ifa_addr->sa_family != AF_LINK)
+			continue;
+		if (in_dev != NULL) {
+			if (strcmp(ifa->ifa_name, in_dev) == 0)
+				break;
+		} else
+			break;
+	}
+	if (ifa == NULL) {
+		fprintf(stderr,"error, interface not found\n");
 		exit(1);
 	}
-	return 0;
+
+	strncpy(name, ifa->ifa_name, IFNAMSIZ);
+
+#define	IFA_STAT(s)	(((struct if_data *)ifa->ifa_data)->ifi_ ## s)
+	*ibytes = IFA_STAT(ibytes);
+	*obytes = IFA_STAT(obytes);
+#undef IFA_STAT
+
+	freeifaddrs(ifap);
 }
 
 int main(int argc, char *argv[]) {
@@ -280,9 +269,6 @@ int main(int argc, char *argv[]) {
 	unsigned long curo = 0;
 #define CURIS curi / timea.tv_sec
 #define CUROS curo / timea.tv_sec
-	/* all goods are defined in net/if.h and net/if_var.h */
-	struct ifnet foonet;
-	struct ifnethead ifnethead;
 	int i = 0;
 	int x = 0;
 	int j = 0;
@@ -393,48 +379,10 @@ int main(int argc, char *argv[]) {
 	argc -= optind;
 	argv += optind;
 	
-	for(i=0;i<sizeof(name);i++) {
-		name[i] = '\0';
-	}
-
-	kvmd = kvm_openfiles(nlistf,memf,NULL,O_RDONLY,0);	
 	setgid(getgid());
-	kread(0,0,0);
-	ifnetaddr = netl[0].n_value;
-	
-	if(kread(ifnetaddr,(char *)&ifnethead,sizeof ifnethead))
-		return 1;
-	
-	ifnetaddr = (u_long)TAILQ_FIRST(&ifnethead);
-	if(kread(ifnetaddr,(char *)&foonet,sizeof foonet))
-		return 1;
-
-#if __FreeBSD_version >= 501113
-	strncpy(name,foonet.if_xname,sizeof(name));
-#else
-	if(kread((u_long)foonet.if_name, tname, 16))
-		return 1;
-	snprintf(name,32,"%s%d",tname,foonet.if_unit);
-#endif
-
-	while(in_dev != NULL && strncmp(in_dev,name,strlen(in_dev)) != 0) {
-		ifnetaddr = (u_long)TAILQ_NEXT(&foonet,if_link);
-		if(ifnetaddr < 1) {
-			fprintf(stderr,"error, interface not found\n");
-			exit(1);
-		}
-		if(kread(ifnetaddr,(char *)&foonet,sizeof foonet))
-			return 1;
 
-#if __FreeBSD_version >= 501113
-		strncpy(name,foonet.if_xname,sizeof(name));
-#else
-		if(kread((u_long)foonet.if_name, tname, 16))
-			return 1;
-		snprintf(name,32,"%s%d",tname,foonet.if_unit);
-#endif
-			
-	}
+	readstat(&lasti, &lasto);
+	gettimeofday(&last,NULL);
 
 	/* start curses */
 	initscr();
@@ -486,37 +434,32 @@ int main(int argc, char *argv[]) {
 	}
 	/* screen init.. */
 	screen_init();
-	
-	lasti = foonet.if_ibytes;
-	lasto = foonet.if_obytes;
-	gettimeofday(&last,NULL);
-	
+
 	for(i=0;i<MAX_G;i++) {
 		logi[i] = NULL;
 		logo[i] = NULL;
 	}
 	
 	for(;;) {
+		u_long ibytes, obytes;
+
 		screen_check();
 		ch = wgetch(mainw);
 		/* quit when we get 'q' */
 		if(ch == (int)'q' || ch == (int)' ') {
 			
 			endwin();
-			kvm_close(kvmd);		
 
 			exit(0);
 		}
 		/* clear screen */
 		if(ch == (int)'c') {
-            free_logs();
+			free_logs();
 		}
-		
-		if(kread(ifnetaddr,(char *)&foonet,sizeof foonet))
-			return 1;
-		
-		curi = foonet.if_ibytes - lasti;
-		curo = foonet.if_obytes - lasto;
+
+		readstat(&ibytes, &obytes);
+		curi = ibytes - lasti;
+		curo = obytes - lasto;
 		in_total += curi;
 		out_total += curo;
 		
@@ -569,7 +512,6 @@ int main(int argc, char *argv[]) {
 				logi[i] = (unsigned int *)malloc(sizeof(unsigned int));
 				if(logi[i] == NULL) {
 					fprintf(stderr,"error,allocating memory\n");
-					kvm_close(kvmd);
 					endwin();
 					exit(1);
 				}
@@ -583,7 +525,6 @@ int main(int argc, char *argv[]) {
 				logo[i] = (unsigned int *)malloc(sizeof(unsigned int));
 				if(logo[i] == NULL) {
 					fprintf(stderr,"error,allocating memory\n");
-					kvm_close(kvmd);
 					endwin();
 					exit(1);
 				}
@@ -648,9 +589,8 @@ int main(int argc, char *argv[]) {
 		
 		gettimeofday(&last,NULL);
 		select(0,NULL,NULL,NULL,&timea);
-		lasti = foonet.if_ibytes;
-		lasto = foonet.if_obytes;
-		
+		lasti = ibytes;
+		lasto = obytes;
 	}
 }
 
