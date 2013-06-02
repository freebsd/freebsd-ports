--- ../generic/regc_nfa.c	2013-06-01 17:57:46.483457654 +0100
+++ ../generic/regc_nfa.c	2013-06-01 17:57:59.049271978 +0100
@@ -759,7 +759,7 @@
      * Arbitrary depth limit. Needs tuning, but this value is sufficient to
      * make all normal tests (not reg-33.14) pass.
      */
-#define DUPTRAVERSE_MAX_DEPTH 500
+#define DUPTRAVERSE_MAX_DEPTH 1000
 
     if (depth++ > DUPTRAVERSE_MAX_DEPTH) {
 	NERR(REG_ESPACE);
