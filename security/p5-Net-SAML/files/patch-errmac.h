--- ../errmac.h.orig	2009-10-16 19:37:47.000000000 +0400
+++ ../errmac.h	2009-10-30 00:39:36.000000000 +0300
@@ -406,9 +406,9 @@
 #define DD(format,...)  /* Documentative */
 
 int hexdmp(char* msg, char* p, int len, int max);
-int hexdump(char* msg, char* p, char* lim, int max);
+int myhexdump(char* msg, char* p, char* lim, int max);
 
-#define HEXDUMP(msg, p, lim, max) (zx_debug > 1 && hexdump((msg), (p), (lim), (max)))
+#define HEXDUMP(msg, p, lim, max) (zx_debug > 1 && myhexdump((msg), (p), (lim), (max)))
 #define DHEXDUMP(msg, p, lim, max) /* Disabled hex dump */
 
 #define ERR(format,...) (fprintf(stderr, "t %10s:%-3d %-16s %s E " format "\n", __FILE__, __LINE__, __FUNCTION__, ERRMAC_INSTANCE, __VA_ARGS__), fflush(stderr))
