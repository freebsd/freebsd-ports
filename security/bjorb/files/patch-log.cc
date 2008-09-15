--- log.cc.orig	2008-09-15 18:41:31.000000000 +0000
+++ log.cc	2008-09-15 18:43:17.000000000 +0000
@@ -183,7 +183,7 @@
   va_start(ap, fmt);
 
 #ifndef NO_SYSLOG
-  if ((int)fp == -1) {
+  if (fp == (FILE *)-1) {
     char buf[512];
     int level;
     vsprintf(buf, fmt, ap);
@@ -241,7 +241,7 @@
 {
   if (fp && fp != stderr
 #ifndef NO_SYSLOG
-      && (int)fp != -1
+      && fp != (FILE *)-1
 #endif
       ) {
     put("Close log file\n");
