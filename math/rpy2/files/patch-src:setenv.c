--- src/setenv.c.orig	Wed Oct 29 14:47:12 2003
+++ src/setenv.c	Wed Oct 29 14:47:19 2003
@@ -26,8 +26,6 @@
 
 int setenv(const char *name, const char *value, int clobber)
 {
-  char *malloc();
-  char *getenv();
   char *cp;
 
   if (clobber == 0 && getenv(name) != 0)
