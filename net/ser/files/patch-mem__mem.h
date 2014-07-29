
$FreeBSD$

--- mem/mem.h.orig
+++ mem/mem.h
@@ -122,9 +122,13 @@
 #else
 #	include <stdlib.h>
 #	define pkg_malloc(s) \
-	(  { void *v; v=malloc((s)); \
-	   DBG("malloc %p size %d end %p\n", v, s, (char*)v+(s));\
-	   v; } )
+	(  { void *____v123; ____v123=malloc((s)); \
+	   DBG("malloc %p size %lu end %p\n", ____v123, (unsigned long)(s), (char*)____v123+(s));\
+	   ____v123; } )
+#	define pkg_realloc(p, s) \
+	(  { void *____v123; ____v123=realloc(p, s); \
+	   DBG("realloc %p size %lu end %p\n", ____v123, (unsigned long)(s), (char*)____v123+(s));\
+	    ____v123; } )
 #	define pkg_free(p)  do{ DBG("free %p\n", (p)); free((p)); }while(0);
 #	define pkg_status()
 #endif
