--- amap.h.orig	Tue Jul 22 13:54:37 2003
+++ amap.h	Tue Jul 29 14:06:27 2003
@@ -24,7 +24,7 @@
 #define AMAP_EMAIL     "amap-dev@thc.org"
 #define AMAP_RESOURCE  "www.thc.org"
 
-#define AMAP_APPDEF_PATH	"/usr/local/bin"
+#define AMAP_APPDEF_PATH	"PREFIX/bin"
 #define AMAP_BUFSIZE		1024	// standard buffer size
 #define AMAP_BUFSIZE_BIG	16348   // big standard buffer size
 #define AMAP_REGEX_OPTIONS	( PCRE_MULTILINE | PCRE_CASELESS )
