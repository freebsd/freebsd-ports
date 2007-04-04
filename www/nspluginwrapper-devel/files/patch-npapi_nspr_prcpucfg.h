--- ./npapi/nspr/prcpucfg.h.orig	Wed Apr  4 20:26:11 2007
+++ ./npapi/nspr/prcpucfg.h	Wed Apr  4 20:27:40 2007
@@ -229,7 +229,7 @@
 #define PR_BYTES_PER_WORD_LOG2  3
 #define PR_BYTES_PER_DWORD_LOG2 3
 
-#elif defined(__x86_64__)
+#elif defined(__x86_64__) || defined(__amd64__)
 
 #define IS_LITTLE_ENDIAN 1
 #undef  IS_BIG_ENDIAN
