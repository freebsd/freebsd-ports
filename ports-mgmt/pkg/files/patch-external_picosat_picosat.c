--- external/picosat/picosat.c.orig	2021-10-01 11:55:01 UTC
+++ external/picosat/picosat.c
@@ -145,7 +145,7 @@ IN THE SOFTWARE.
 typedef uintptr_t Wrd;
 #define ISLITREASON(C) (1&(Wrd)C)
 #define LIT2REASON(L) \
-  (assert (L->val==TRUE), ((Cls*)(1 + (2*(L - ps->lits)))))
+  (assert (L->val==TRUE), ((Cls*)(1 + (2*((intptr_t)L - (intptr_t)ps->lits)))))
 #define REASON2LIT(C) ((Lit*)(ps->lits + ((Wrd)C)/2))
 #endif
 
