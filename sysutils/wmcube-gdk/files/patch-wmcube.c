--- wmcube.c.orig	2001-12-18 07:06:21.000000000 -0200
+++ wmcube.c	2010-01-20 13:19:32.000000000 -0200
@@ -50,7 +50,6 @@
 #include <sys/ioctl.h>
 #include <sys/socket.h>
 
-#include <utmp.h>
 #include <dirent.h>
 
 #include <gdk/gdk.h>
@@ -174,6 +173,7 @@
 #ifdef FREEBSD
 static kvm_t *kd;
 static struct nlist nlst[] = { {"_cp_time"}, {0} };
+static int cp_time_mib[2];
 #endif
 
 void prep_digits(void)
@@ -226,7 +226,7 @@
     XWMHints wmhints;
     /* for mask */
     GdkBitmap *mask;
-    unsigned char mask_data[8 * 64];
+    gchar mask_data[8 * 64];
     int i;
     GdkColor bright;
     /* for that stupid shadow line */
@@ -778,7 +778,7 @@
 	newx -= CHAR_WIDTH;
     }
 
-    sprintf(buf, "%02i%%", num);
+    snprintf(buf, 5, "%02i%%", num);
     for (i = 0; (c = buf[i]); i++) {
 	if (c == '%')
 	    copy_xpm_area(60, 0, 7, 9, newx, y);
@@ -899,7 +899,8 @@
 
 	while ((i > -1) && (temparr[i] > key)) {
 	    temparr[i + 1] = temparr[i];
-	    zorder[i + 1] = zorder[i--];
+	    zorder[i + 1] = zorder[i];
+	    i--;
 	}
 
 	zorder[i + 1] = k;
@@ -1250,7 +1251,7 @@
 	exit(0);
     }
 
-    fscanf(fp, "%s", tmp);
+    fscanf(fp, "%63s", tmp);
 
     if (strcmp(tmp, "WMCUBE_COORDINATES") != 0) {
 	printf
@@ -1259,7 +1260,7 @@
 	exit(0);
     }
 
-    fscanf(fp, "%s", tmp);
+    fscanf(fp, "%63s", tmp);
     counter = atoi(tmp);
 
     while ((strcmp(tmp, "WMCUBE_LINES") != 0)
@@ -1280,7 +1281,7 @@
 	    fclose(fp);
 	    exit(0);
 	}
-	fscanf(fp, "%s", tmp);
+	fscanf(fp, "%63s", tmp);
 
 	if (feof(fp)) {
 	    printf
@@ -1297,23 +1298,23 @@
 
 	planesORlines = 0;
 	while (1) {
-
 	    cline = (int *) realloc(cline, (i + 2) * sizeof(int));
 	    mem_alloc_error(cline);
-	    fscanf(fp, "%d %d", &cline[i++], &cline[i++]);
-	    /* printf("\n%d %d",cline[i-2],cline[i-1]); */
+	    fscanf(fp, "%d %d", &cline[i], &cline[i+1]);
+	    /* printf("\n%d %d",cline[i],cline[i+1]); */
 	    if (feof(fp))
 		break;
 
-	    if (cline[i - 2] > nofcoords || cline[i - 1] > nofcoords) {
+	    if (cline[i] > nofcoords || cline[i+1] > nofcoords) {
 		printf("\nError in objectfile (WMCUBE_LINES section):\n"
 		       "coordinates %d or/and %d doesnt exist\n\n",
-		       cline[i - 2], cline[i - 1]);
+		       cline[i], cline[i+1]);
 		fclose(fp);
 		exit(0);
 	    }
+	    i = i + 2;
 	}
-	noflines = i - 2;
+	noflines = i;
     } else if (strcmp(tmp, "WMCUBE_PLANES") == 0) {
 
 	planesORlines = 1;
@@ -1398,7 +1399,7 @@
     char cpuid[6];
     char check_cpu[6];
 
-    sprintf(check_cpu, "cpu%d", which_cpu);
+    snprintf(check_cpu, 6, "cpu%d", which_cpu);
 
     if ((fp = fopen("/proc/stat", "rb")) == NULL) {
 	perror("/proc/stat required for this system");
@@ -1409,7 +1410,7 @@
 	return 0;
 
     for (i = -2; i < which_cpu; i++) {
-	fscanf(fp, "%s", cpuid);
+	fscanf(fp, "%5s", cpuid);
     }
 
     if (strcmp(check_cpu, cpuid) != 0) {
@@ -1431,7 +1432,7 @@
     fp = fopen("/proc/stat", "rt");
 
     for (i = -2; i < which_cpu; i++) {
-	fscanf(fp, "%s %d %d %d %d", cpuid, &cpu, &nice, &system, &idle);
+	fscanf(fp, "%5s %d %d %d %d", cpuid, &cpu, &nice, &system, &idle);
     }
 
     fclose(fp);
@@ -1582,18 +1583,23 @@
 #include <nlist.h>
 #include <fcntl.h>
 #include <sys/dkstat.h>
+#include <sys/sysctl.h>
 
 int init_calc_cpu()
 {
+    size_t len = 2;
+    if (sysctlnametomib("kern.cp_time", cp_time_mib, &len) < 0) {
+    	printf("\nWarning: unable to sysctl kern.cp_time\n\n");
 
-    if ((kd = kvm_open(NULL, NULL, NULL, O_RDONLY, "kvm_open")) == NULL) {
-	printf("\nError: unable to open kvm\n\n");
-	exit(0);
-    }
-    kvm_nlist(kd, nlst);
-    if (nlst[0].n_type == 0) {
-	printf("\nError: unable to get nlist\n\n");
-	exit(1);
+    	if ((kd = kvm_open(NULL, NULL, NULL, O_RDONLY, "kvm_open")) == NULL) {
+	    printf("\nError: unable to open kvm\n\n");
+	    exit(0);
+	}
+	kvm_nlist(kd, nlst);
+	if (nlst[0].n_type == 0) {
+	    printf("\nError: unable to get nlist\n\n");
+	    exit(1);
+	}
     }
 
     /* drop setgid & setuid (hi GOBBLES, who the fuck are you? */
@@ -1615,6 +1621,13 @@
     int cpu, nice, system, idle;
     unsigned long int cpu_time[CPUSTATES];
 
+    if (cp_time_mib[0] != 0) {
+        size_t cpu_time_len = sizeof (cpu_time);
+        if (sysctl(cp_time_mib, 2, cpu_time, &cpu_time_len, NULL, 0) < 0) {
+            printf("\nError sysctl\n\n");
+            exit(0);
+        }
+    } else
     if (kvm_read(kd, nlst[0].n_value, &cpu_time, sizeof(cpu_time))
 	!= sizeof(cpu_time)) {
 	printf("\nError reading kvm\n\n");
