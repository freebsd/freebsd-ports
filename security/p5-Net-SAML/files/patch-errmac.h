--- ../errmac.h.orig	2013-02-10 20:04:39.000000000 +0800
+++ ../errmac.h	2013-02-10 20:05:04.000000000 +0800
@@ -445,9 +445,9 @@
 #define DD_XML_BLOB(cf, lk, len, xml) /* Documentative */
 
 int hexdmp(const char* msg, const char* p, int len, int max);
-int hexdump(const char* msg, const char* p, const char* lim, int max);
+int myhexdump(const char* msg, const char* p, const char* lim, int max);
 
-#define HEXDUMP(msg, p, lim, max) if (zx_debug > 1) hexdump((msg), (p), (lim), (max))
+#define HEXDUMP(msg, p, lim, max) if (zx_debug > 1) myhexdump((msg), (p), (lim), (max))
 #define DHEXDUMP(msg, p, lim, max) /* Disabled hex dump */
 
 #define DUMP_CORE() ASSERT(0)
