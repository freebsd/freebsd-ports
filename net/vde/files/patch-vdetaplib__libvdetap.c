--- vdetaplib/libvdetap.c	Sat Jan 29 15:02:08 2005
+++ vdetaplib/libvdetap.c	Sun Jan 30 13:29:07 2005
@@ -5,26 +5,39 @@
 #include <sys/socket.h>
 #include <sys/syscall.h>
 #include <sys/stat.h>
+#include <limits.h>
+#include <dlfcn.h>
 #include <stdarg.h>
 #include <string.h>
 #include <unistd.h>
 #include <stdlib.h>
-#define __USE_LARGEFILE64
 #include <fcntl.h>
 #include <errno.h>
 #include <signal.h>
-#include <linux/ioctl.h>
-#include <linux/if.h>
-#include <linux/if_tun.h>
+#include <stdio.h>
+#include <sys/ioctl.h>
+#include <net/if.h>
+#include <net/if_tun.h>
 
-#define TUNTAPPATH "/dev/net/tun"
+#define TUNTAPPATH "/dev/tap"
 #define VDETAPEXEC "vdetap"
 #define VDEALLTAP "VDEALLTAP"
 #define MAX 10
 
+#if defined(RTLD_NEXT)
+#define REAL_LIBC RTLD_NEXT
+#else
+#define REAL_LIBC ((void *) -1L)
+#endif
+
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__bsdi__)
+typedef unsigned long request_t;
+#else
+typedef int request_t;
+#endif
+
 int tapfd[2] = {-1,-1};
 static int tapcount=0;
-static int tuncount=0;
 
 static struct pidlist {
 	pid_t pid;
@@ -39,11 +52,6 @@
 	return rv;
 }
 
-static void plfree (struct pidlist *el) {
-	el->next=flh;
-	flh=el;
-}
-
 static int addpid(int pid) {
 	struct pidlist *plp;
 	if ((plp=plmalloc ()) != NULL) {
@@ -74,105 +82,41 @@
 	}
 }
 
-	int
-native_open(const char *pathname, int flags, mode_t data)
-{
-	return (syscall(SYS_open, pathname, flags, data));
-}
-
-	int
-native_ioctl(int fd, unsigned long int command, char *data)
-{
-	return (syscall(SYS_ioctl, fd, command, data));
-}
-
-
 int open(const char *path, int flags, ...)
 {
-	static char buf[PATH_MAX];
+	static int (*func) (const char *, int, mode_t) = NULL;
+	char *vdesock;
+	int pid;
 	va_list ap;
 	mode_t data;
 
-	va_start(ap, flags);
-	data = va_arg(ap, mode_t);
-	va_end(ap);
-
-	if (strcmp(path,TUNTAPPATH)==0 && tapfd[0] == -1) {
-		if (socketpair(PF_UNIX, SOCK_DGRAM, 0,tapfd) == 0) {
-			return tapfd[0];
-		}
-		else
-			return -1;
-
-	} else
-		return native_open(path, flags, data);
-}
-
-int open64(const char *path, int flags, ...)
-{
-	static char buf[PATH_MAX];
-	va_list ap;
-	mode_t data;
+	if (!func)
+		func = (int (*) (const char *, int, mode_t))
+		       dlsym (REAL_LIBC, "open");
 
 	va_start(ap, flags);
-	data = va_arg(ap, mode_t);
+	data = va_arg(ap, int);
 	va_end(ap);
 
 	if (strcmp(path,TUNTAPPATH)==0 && tapfd[0] == -1) {
 		if (socketpair(PF_UNIX, SOCK_DGRAM, 0,tapfd) == 0) {
-			return tapfd[0];
-		}
-		else
-			return -1;
-
-	} else
-		return native_open(path, flags | O_LARGEFILE, data);
-}
-
-int ioctl(int fd, unsigned long int command, ...)
-{
-	va_list ap;
-	char *data;
-	char *vdesock;
-	int pid;
-
-	va_start(ap, command);
-	data = va_arg(ap, char *);
-	va_end(ap);
-
-	if (fd == tapfd[0]) {
-		if (command == TUNSETIFF) {
-			struct ifreq *ifr = (struct ifreq *) data;
 			char num[5];
 			char name[10];
-
-			ifr->ifr_name[IFNAMSIZ-1] = '\0';
-			if (ifr->ifr_name[0] == 0) {
-				if (ifr->ifr_flags & IFF_TAP) 
-					sprintf(name,"tap%d",tapcount++);
-				else
-					sprintf(name,"tun%d",tuncount++);
-				strncpy(ifr->ifr_name,name,IFNAMSIZ);
-			}
-			else if (strchr(ifr->ifr_name, '%') != NULL) {
-				sprintf(name,ifr->ifr_name,tapcount++);
-				strncpy(ifr->ifr_name,name,IFNAMSIZ);
-			}
-			if (ifr->ifr_flags & IFF_TAP &&
-					((vdesock=getenv(ifr->ifr_name)) != NULL)
-					||(vdesock=getenv(VDEALLTAP)) != NULL){
+			sprintf(name,"tap%d",tapcount++);
+			if (((vdesock=getenv(name)) != NULL)
+				||(vdesock=getenv(VDEALLTAP)) != NULL){
 				if ((pid=fork()) < 0) { 
 					close(tapfd[1]);
 					errno=EINVAL;
 					return -1;
 				} else if (pid > 0) { /*father*/
-					if(pid=addpid(pid) < 0) {
+					if((pid=addpid(pid)) < 0) {
 						close(tapfd[0]);
 						close(tapfd[1]);
 						return -1;
 					} else {
 						close(tapfd[1]);
-						return 0;
+						return tapfd[0];
 					}
 				} else { /*son*/
 					plh=NULL;
@@ -181,34 +125,53 @@
 					execlp(VDETAPEXEC,"-",num,vdesock,(char *) 0);
 				}
 			}
-			else /*roll back to the native tuntap*/
-			{
-				int newfd;
-				int saverrno;
-				int resultioctl;
-				close(tapfd[1]);
-				if ((newfd=native_open(TUNTAPPATH,  O_RDWR, 0)) < 0) {
-					saverrno=errno;
-					close(tapfd[0]);
-					errno=saverrno;
-					return -1;
-				} else
-				{
-					resultioctl=native_ioctl(fd, command, data);
-					if (resultioctl < 0) {
-						saverrno=errno;
-						close(tapfd[0]);
-						errno=saverrno;
-						return -1;
-					} else {
-						dup2(newfd,tapfd[0]);
-						return resultioctl;
-					}
-				}
-			}
-		}			else 
-			return 0;
+			return tapfd[0];
+		}
+		else
+			return -1;
+
 	} else
-		return (native_ioctl(fd, command, data));
+		return (*func)(path, flags, data);
+}
+
+int ioctl(int fd, unsigned long int command, ...)
+{
+	static int (*func) (int, request_t, void *) = NULL;
+	int dummy;
+	va_list ap;
+	char *data;
+	struct ifstat *ifs;
+
+	if (!func)
+		func = (int (*) (int, request_t, void *))
+			dlsym (REAL_LIBC, "ioctl");
+
+	va_start(ap, command);
+	data = va_arg(ap, char *);
+	va_end(ap);
+
+	if (fd == tapfd[0]) {
+		switch(command) {
+			case SIOCSIFFLAGS:
+			case SIOCADDMULTI:
+			case SIOCDELMULTI:
+				break;
+
+			case SIOCGIFSTATUS:
+				ifs = (struct ifstat *)data;
+				dummy = strlen(ifs->ascii);
+				if(plh && dummy < sizeof(ifs->ascii))
+					snprintf(ifs->ascii + dummy,
+						sizeof(ifs->ascii) - dummy,
+						"\tOpened by PID %d\n",
+						plh[0].pid);
+				break;
+
+			default:
+				return (*func) (fd, command, data);
+		}
+	}
+
+	return (*func) (fd, command, data);
 }
 
