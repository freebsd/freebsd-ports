--- amap.h.orig	Sun Sep 14 11:25:16 2003
+++ amap.h	Sun Sep 14 11:25:29 2003
@@ -33,7 +33,7 @@
  #endif
 #endif
 
-#define AMAP_APPDEF_PATH	AMAP_PREFIX"/bin"
+#define AMAP_APPDEF_PATH	AMAP_PREFIX"/share/amap"
 #define AMAP_BUFSIZE		1024	// standard buffer size
 #define AMAP_BUFSIZE_BIG	65536   // big standard buffer size
 #define AMAP_REGEX_OPTIONS	( PCRE_MULTILINE | PCRE_CASELESS | PCRE_DOTALL )
