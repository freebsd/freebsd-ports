--- personality.h.orig	2007-05-28 08:12:52.000000000 +0200
+++ personality.h	2020-09-22 15:57:29.215618000 +0200
@@ -179,7 +179,8 @@
 void print_perstree(void);
 
 /* Splay stuff here so other modules can use it */
-SPLAY_HEAD(perstree, personality) personalities;
+typedef SPLAY_HEAD(perstree, personality) personalities_t;
+extern personalities_t personalities;
 static int
 perscompare(struct personality *a, struct personality *b)
 {
@@ -187,7 +187,8 @@
 }
 SPLAY_PROTOTYPE(perstree, personality, node, perscompare);
 
-SPLAY_HEAD(xp_fprint_tree, xp_fingerprint) xp_fprints;
+typedef SPLAY_HEAD(xp_fprint_tree, xp_fingerprint) xp_fprints_t;
+extern xp_fprints_t xp_fprints;
 static int 
 xp_fprint_compare(struct xp_fingerprint *a, struct xp_fingerprint *b)
 {
