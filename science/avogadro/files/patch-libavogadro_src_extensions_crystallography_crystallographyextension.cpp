--- libavogadro/src/extensions/crystallography/crystallographyextension.cpp.orig	2013-12-06 15:50:04 UTC
+++ libavogadro/src/extensions/crystallography/crystallographyextension.cpp
@@ -51,6 +51,11 @@
 #include <openbabel/generic.h>
 #include <openbabel/mol.h>
 
+// fix for lang/gcc5
+#if __GNUC__ == 5 && __GNUC_MINOR__ == 4
+#undef minor
+#endif
+
 #include <Eigen/LU>
 
 #include <QtGui/QClipboard>
