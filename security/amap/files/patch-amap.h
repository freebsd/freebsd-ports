--- amap.h.orig	Tue Aug  5 21:18:29 2003
+++ amap.h	Wed Aug 13 11:48:47 2003
@@ -24,7 +24,7 @@
 #define AMAP_EMAIL     "amap-dev@thc.org"
 #define AMAP_RESOURCE  "www.thc.org"
 
-#define AMAP_APPDEF_PATH	"/usr/local/bin"
+#define AMAP_APPDEF_PATH	"PREFIX/bin"
 #define AMAP_BUFSIZE		1024	// standard buffer size
 #define AMAP_BUFSIZE_BIG	65536   // big standard buffer size
 #define AMAP_REGEX_OPTIONS	( PCRE_MULTILINE | PCRE_CASELESS )
