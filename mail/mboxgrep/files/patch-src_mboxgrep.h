--- src/mboxgrep.h.orig	2003-04-06 21:01:49 UTC
+++ src/mboxgrep.h
@@ -28,6 +28,7 @@
 #define HOST_NAME_SIZE 256
 
 #include <config.h>
+#include <stdint.h>
 
 #include <time.h>  /* for tm structure */
 
@@ -99,10 +100,15 @@ typedef struct
 }
 folder_t;
 
+typedef union {
+	uint64_t halves[2];
+	unsigned char bytes[16];
+} md5_t;
+
 typedef struct
 {
-  char **md5;
   int n;
+  md5_t md5s[];
 }
 checksum_t;
 
@@ -129,6 +135,6 @@ typedef struct
 }
 option_t;
 
-option_t config;
+extern option_t config;
 
 #endif /* MBOXGREP_H */
