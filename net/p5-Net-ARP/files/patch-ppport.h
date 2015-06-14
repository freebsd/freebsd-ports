--- ppport.h.orig	2009-06-20 19:10:51 UTC
+++ ppport.h
@@ -211,6 +211,7 @@ __DATA__
 /* Replace: 0 */
 #endif
 
+#undef PERL_UNUSED_DECL
 #ifdef HASATTRIBUTE
 #  if (defined(__GNUC__) && defined(__cplusplus)) || defined(__INTEL_COMPILER)
 #    define PERL_UNUSED_DECL
