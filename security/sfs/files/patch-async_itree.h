--- async/itree.h.orig	Sun Jul  9 00:14:16 2006
+++ async/itree.h	Sun Jul  9 00:15:07 2006
@@ -86,7 +86,7 @@
   itree_core (const itree_core &);
   itree_core &operator = (const itree_core &);
 
-#define eos ((int) &(((T *) 0)->*field).p)
+#define eos ((ptrdiff_t) &(((T *) 0)->*field).p)
 #define cmpfn scmp, (void *) this
 
 public:
