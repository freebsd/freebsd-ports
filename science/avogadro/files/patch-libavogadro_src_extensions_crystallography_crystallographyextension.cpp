--- libavogadro/src/extensions/crystallography/crystallographyextension.cpp.orig	2016-06-08 14:19:45 UTC
+++ libavogadro/src/extensions/crystallography/crystallographyextension.cpp
@@ -53,6 +53,11 @@
 #include <openbabel/generic.h>
 #include <openbabel/mol.h>
 
+// fix for lang/gcc5
+#if __GNUC__ == 5 && __GNUC_MINOR__ == 4
+#undef minor
+#endif
+
 #include <Eigen/LU>
 
 #include <QtGui/QClipboard>
