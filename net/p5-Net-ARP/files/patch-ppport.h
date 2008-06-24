--- ppport.h.orig       2008-06-24 12:35:16.000000000 +0000
+++ ppport.h    2008-06-24 12:35:40.000000000 +0000
@@ -220,6 +220,7 @@
 /* Replace: 0 */
 #endif
 
+#undef PERL_UNUSED_DECL
 #ifdef HASATTRIBUTE
 #  if (defined(__GNUC__) && defined(__cplusplus)) || defined(__INTEL_COMPILER)
 #    define PERL_UNUSED_DECL
