--- UptimeMeter.c.orig	2010-01-26 04:26:23.000000000 +0800
+++ UptimeMeter.c	2010-01-26 04:27:01.000000000 +0800
@@ -19,7 +19,7 @@
 };
 
 static void UptimeMeter_setValues(Meter* this, char* buffer, int len) {
-   double uptime;
+   double uptime = 0;
    FILE* fd = fopen(PROCDIR "/uptime", "r");
    fscanf(fd, "%lf", &uptime);
    fclose(fd);
