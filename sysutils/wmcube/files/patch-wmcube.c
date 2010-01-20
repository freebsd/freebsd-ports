--- wmcube.c.orig	2000-10-23 18:11:47.000000000 -0200
+++ wmcube.c	2010-01-20 13:20:56.000000000 -0200
@@ -42,7 +42,6 @@
 #include <sys/ioctl.h>
 #include <sys/socket.h>
 
-#include <utmp.h>
 #include <dirent.h>
 
 #include <X11/Xlib.h>
@@ -125,6 +124,7 @@
 #ifdef FREEBSD
 static kvm_t            *kd;
 static struct nlist     nlst[] = { {"_cp_time"}, {0} };
+static int		cp_time_mib[2];
 #endif
 
 int main(int argc, char **argv)
@@ -913,7 +913,7 @@
 		exit(0);
 	}
 
-	fscanf(fp,"%s",tmp);
+	fscanf(fp,"%63s",tmp);
 	
 	if (strcmp(tmp,"WMCUBE_COORDINATES") != 0) { 
 		printf("\nError in objectfile: it must start with WMCUBE_COORDINATES\n\n");
@@ -921,7 +921,7 @@
 		exit(0);
 	}
 
-	fscanf(fp,"%s",tmp);
+	fscanf(fp,"%63s",tmp);
 	counter = atoi(tmp);
 
 	while ((strcmp(tmp,"WMCUBE_LINES") != 0) && (strcmp(tmp,"WMCUBE_PLANES") != 0)) {		
@@ -938,7 +938,7 @@
 			fclose(fp);
 			exit(0);
 		}
-		fscanf(fp,"%s",tmp);
+		fscanf(fp,"%63s",tmp);
 
 		if (feof(fp)) {
 			printf("\nError in objectfile: you must have a section WMCUBE_LINES or WMCUBE_PLANES\n\n");
@@ -1224,9 +1224,14 @@
 #include <nlist.h>
 #include <fcntl.h>
 #include <sys/dkstat.h>
+#include <sys/sysctl.h>
 
 int init_calc_cpu()
 {
+	size_t len = 2; 
+	if (sysctlnametomib("kern.cp_time", cp_time_mib, &len) == 0) 
+		return 0;
+	printf("\nWarning: unable to sysctl kern.cp_time\n\n");
 
         if ((kd = kvm_open(NULL, NULL, NULL, O_RDONLY, "kvm_open")) == NULL)
         {
@@ -1249,6 +1254,13 @@
         int cpu,nice,system,idle;
         unsigned long int cpu_time[CPUSTATES];
 
+	if (cp_time_mib[0] != 0) {
+		size_t cpu_time_len = sizeof (cpu_time);
+		if (sysctl(cp_time_mib, 2, cpu_time, &cpu_time_len, NULL, 0) < 0) {
+			printf("\nError sysctl\n\n");
+			exit(0);
+		}
+	} else
         if (kvm_read(kd, nlst[0].n_value, &cpu_time, sizeof(cpu_time))
                 != sizeof(cpu_time))
         {
