--- src/datasource/tid.c.orig	2021-04-20 15:35:54 UTC
+++ src/datasource/tid.c
@@ -49,7 +49,7 @@
  */
 int snoopy_datasource_tid (char * const result, char const * const arg)
 {
-    long unsigned int tid = pthread_self();
+    long unsigned int tid = (long unsigned int) pthread_self();
 
     // This happens if -lpthread is not given to compiler
     if (0 == tid) {
