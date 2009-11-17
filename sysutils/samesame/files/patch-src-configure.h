--- src/configure.h	Sun Nov 15 02:23:34 2009
+++ src/configure.h	Mon Nov 16 02:34:14 2009
@@ -9,7 +9,7 @@
 /* If READ_ONLY_ONCES is defined the code will read each file only ones.
  * If READ_ONLY_ONCES is not defined the code will use less memory.
  */
-#ifdef LOW_MEMORY_PROFILE
+#ifndef LOW_MEMORY_PROFILE
 #define READ_ONLY_ONCES
 #endif // LOW_MEMORY_PROFILE
 
