--- wmcube.c.orig	Tue Aug 28 12:08:13 2001
+++ wmcube.c	Tue Dec 18 14:37:25 2001
@@ -778,7 +777,7 @@
 	newx -= CHAR_WIDTH;
     }
 
-    sprintf(buf, "%02i%%", num);
+    snprintf(buf, 5, "%02i%%", num);
     for (i = 0; (c = buf[i]); i++) {
 	if (c == '%')
 	    copy_xpm_area(60, 0, 7, 9, newx, y);
@@ -1250,7 +1249,7 @@
 	exit(0);
     }
 
-    fscanf(fp, "%s", tmp);
+    fscanf(fp, "%63s", tmp);
 
     if (strcmp(tmp, "WMCUBE_COORDINATES") != 0) {
 	printf
@@ -1259,7 +1258,7 @@
 	exit(0);
     }
 
-    fscanf(fp, "%s", tmp);
+    fscanf(fp, "%63s", tmp);
     counter = atoi(tmp);
 
     while ((strcmp(tmp, "WMCUBE_LINES") != 0)
@@ -1280,7 +1279,7 @@
 	    fclose(fp);
 	    exit(0);
 	}
-	fscanf(fp, "%s", tmp);
+	fscanf(fp, "%63s", tmp);
 
 	if (feof(fp)) {
 	    printf
@@ -1398,7 +1397,7 @@
     char cpuid[6];
     char check_cpu[6];
 
-    sprintf(check_cpu, "cpu%d", which_cpu);
+    snprintf(check_cpu, 6, "cpu%d", which_cpu);
 
     if ((fp = fopen("/proc/stat", "rb")) == NULL) {
 	perror("/proc/stat required for this system");
@@ -1409,7 +1408,7 @@
 	return 0;
 
     for (i = -2; i < which_cpu; i++) {
-	fscanf(fp, "%s", cpuid);
+	fscanf(fp, "%5s", cpuid);
     }
 
     if (strcmp(check_cpu, cpuid) != 0) {
@@ -1431,7 +1430,7 @@
     fp = fopen("/proc/stat", "rt");
 
     for (i = -2; i < which_cpu; i++) {
-	fscanf(fp, "%s %d %d %d %d", cpuid, &cpu, &nice, &system, &idle);
+	fscanf(fp, "%5s %d %d %d %d", cpuid, &cpu, &nice, &system, &idle);
     }
 
     fclose(fp);
