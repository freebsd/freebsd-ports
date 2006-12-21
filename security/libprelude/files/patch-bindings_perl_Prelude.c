--- bindings/perl/Prelude.c.orig	Sat Dec 16 10:04:05 2006
+++ bindings/perl/Prelude.c	Thu Dec 21 11:02:42 2006
@@ -15,6 +15,11 @@
  *  declarations/attributes, and other compiler dependent labels.
  * ----------------------------------------------------------------------------- */
 
+/* workaround to build with perl-5.005 */
+#ifndef INT2PTR
+#  define INT2PTR(type, pointer) (type)(pointer)
+#endif
+
 /* template workaround for compilers that cannot correctly implement the C++ standard */
 #ifndef SWIGTEMPLATEDISAMBIGUATOR
 # if defined(__SUNPRO_CC)
