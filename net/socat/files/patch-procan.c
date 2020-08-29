--- procan.c.orig	2017-01-06 20:58:40 UTC
+++ procan.c
@@ -21,7 +21,7 @@
 
 /* dirty workaround so we dont get an error on AIX when getting linked with
    libwrap */
-int allow_severity, deny_severity;
+//int allow_severity, deny_severity;
 
 
 int procan(FILE *outfile) {
