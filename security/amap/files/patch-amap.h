--- amap.h.orig	Tue Feb  1 20:07:14 2005
+++ amap.h	Sun Feb 13 14:28:05 2005
@@ -33,7 +33,7 @@
  #endif
 #endif
 
-#define AMAP_APPDEF_PATH	AMAP_PREFIX"/etc"
+#define AMAP_APPDEF_PATH	AMAP_PREFIX"/share/amap"
 #define AMAP_BUFSIZE		1024	// standard buffer size
 #define AMAP_BUFSIZE_BIG	65536   // big standard buffer size
 #define AMAP_REGEX_OPTIONS	( PCRE_MULTILINE | PCRE_CASELESS | PCRE_DOTALL )
