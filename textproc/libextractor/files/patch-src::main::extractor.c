--- src/main/extractor.c.orig	Fri Nov 11 04:54:19 2005
+++ src/main/extractor.c	Fri Nov 11 04:55:27 2005
@@ -246,8 +246,10 @@
 
 void __attribute__ ((destructor)) le_ltdl_fini(void) {
   lt_dlsetsearchpath(old_dlsearchpath);
-  if (old_dlsearchpath != NULL)
+  if (old_dlsearchpath != NULL) {
     free(old_dlsearchpath);
+    old_dlsearchpath = NULL;
+  }
 #ifdef MINGW
   ShutdownWinEnv();
 #endif
