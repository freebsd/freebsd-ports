--- external/picosat/picosat.c.orig	2021-11-12 08:57:25 UTC
+++ external/picosat/picosat.c
@@ -145,7 +145,7 @@ typedef uintptr_t Wrd;
 typedef uintptr_t Wrd;
 #define ISLITREASON(C) (1&(Wrd)C)
 #define LIT2REASON(L) \
-  (assert (L->val==TRUE), ((Cls*)(1 + (2*(L - ps->lits)))))
+  (assert (L->val==TRUE), ((Cls*)(Wrd)(1 + (2*(L - ps->lits)))))
 #define REASON2LIT(C) ((Lit*)(ps->lits + ((Wrd)C)/2))
 #endif
 
@@ -184,10 +184,11 @@ typedef uintptr_t Wrd;
 #define RNK2VAR(r) (ps->vars + ((r) - ps->rnks))
 
 #define BLK_FILL_BYTES 8
+#define BLK_OFFSET_BYTES (offsetof(Blk, data))
 #define SIZE_OF_BLK (sizeof (Blk) - BLK_FILL_BYTES)
 
 #define PTR2BLK(void_ptr) \
-  ((void_ptr) ? (Blk*)(((char*)(void_ptr)) - SIZE_OF_BLK) : 0)
+  ((void_ptr) ? (Blk*)(((char*)(void_ptr)) - BLK_OFFSET_BYTES) : 0)
 
 #define AVERAGE(a,b) ((b) ? (((double)a) / (double)(b)) : 0.0)
 #define PERCENT(a,b) (100.0 * AVERAGE(a,b))
