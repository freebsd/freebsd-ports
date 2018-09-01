--- errmac.h.orig	2016-02-29 00:16:50 UTC
+++ errmac.h
@@ -483,9 +483,17 @@ extern FILE* errmac_debug_log;    /* Def
 #define DD_XML_BLOB(cf, lk, len, xml) /* Documentative */
 
 int hexdmp(const char* msg, const void* p, int len, int max);
+#if __FreeBSD__
+int hexdump_zxid(const char* msg, const void* p, const void* lim, int max);
+#else 
 int hexdump(const char* msg, const void* p, const void* lim, int max);
+#endif
 
+#if __FreeBSD__
+#define HEXDUMP(msg, p, lim, max) if ((errmac_debug&ERRMAC_DEBUG_MASK) > 1) hexdump_zxid((msg), (p), (lim), (max))
+#else 
 #define HEXDUMP(msg, p, lim, max) if ((errmac_debug&ERRMAC_DEBUG_MASK) > 1) hexdump((msg), (p), (lim), (max))
+#endif
 #define DHEXDUMP(msg, p, lim, max) /* Disabled hex dump */
 
 #define DUMP_CORE() ASSERT(0)

