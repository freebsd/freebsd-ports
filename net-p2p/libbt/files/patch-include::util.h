--- include/util.h	Fri Apr 16 08:41:48 2004
+++ include/util.h.new	Sun May 30 14:17:54 2004
@@ -28,9 +28,4 @@
 	typedef void (*exitfn_ptr) (int,void*);
 	int on_exit( exitfn_ptr exitfn, void* data) ;
 #endif
-#define malloc(s) use_btmalloc_instead
-#define calloc(n,s) use_btcalloc_instead
-#define realloc(p,s) use_btrealloc_instead
-#define free(p) use_btfree_instead
-
 #endif
