--- src/file_buffer.h.orig	Mon Aug 25 17:17:41 2003
+++ src/file_buffer.h	Tue Apr  6 19:32:32 2004
@@ -51,6 +51,7 @@
 #endif
 
 #include <stdio.h> /* fopen, fread, fseek*, fclose */
+#include <sys/types.h>
 
 /* figure out which fseek/ftell we need */
 #undef FSEEK
@@ -70,6 +71,10 @@
 /* figure out off_t formatting */
 #undef OFF_T_FORMAT
 #undef ATOL
+#if defined(__FreeBSD__)
+# define OFF_T_FORMAT  "llu"
+# define ATOL(arg)     strtoll(arg, NULL, 10)
+#else
 #if _FILE_OFFSET_BITS==64
 # define OFF_T_FORMAT  "llu"
 # define ATOL(arg)     atoll(arg)
@@ -77,6 +82,7 @@
 # warning "Not compiling for large file (>2G) support!"
 # define OFF_T_FORMAT  "lu"
 # define ATOL(arg)     atol(arg)
+#endif
 #endif
 
 #define DEFAULT_FILE_BUFFER_SIZE    	(1024*512)
