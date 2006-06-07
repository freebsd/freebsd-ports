--- bindings/perl/Prelude.c.orig	Tue Jun  6 10:46:03 2006
+++ bindings/perl/Prelude.c	Tue Jun  6 10:46:46 2006
@@ -14,6 +14,10 @@
  *  declarations/attributes, and other compiler dependent labels.
  *
  ************************************************************************/
+/* workaround to build with perl-5.005 */
+#ifndef INT2PTR
+#  define INT2PTR(type, pointer) (type)(pointer)
+#endif
 
 /* template workaround for compilers that cannot correctly implement the C++ standard */
 #ifndef SWIGTEMPLATEDISAMBIGUATOR
