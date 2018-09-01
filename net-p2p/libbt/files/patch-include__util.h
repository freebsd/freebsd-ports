--- include/util.h.orig	2018-08-30 18:48:15 UTC
+++ include/util.h
@@ -53,11 +53,15 @@
 	typedef void (*exitfn_ptr) (int,void*);
 	int on_exit( exitfn_ptr exitfn, void* data) ;
 #endif
-#define malloc(s) use_btmalloc_instead
-#define calloc(n,s) use_btcalloc_instead
-#define realloc(p,s) use_btrealloc_instead
+/*
+ #define malloc(s) use_btmalloc_instead
+ #define calloc(n,s) use_btcalloc_instead
+ #define realloc(p,s) use_btrealloc_instead
+/*
 #undef free
+/*
 #define free(p) use_btfree_instead
+*/
 
 void hexdump( void *buf, int buflen);
 
