--- qnapi.pro.orig	2017-05-19 16:50:58 UTC
+++ qnapi.pro
@@ -12,14 +12,7 @@ unix {
     target.files += qnapi
     target.path = $${INSTALL_PREFIX}/bin
     doc.path = $${INSTALL_PREFIX}/share/doc/qnapi
-    doc.files = doc/ChangeLog \
-        doc/LICENSE \
-        doc/LICENSE-pl \
-        doc/COPYRIGHT \
-        doc/qnapi-download.desktop \
-        doc/qnapi-scan.desktop \
-        doc/qnapi-download.schemas \
-        doc/qnapi-scan.schemas
+    doc.files = doc/ChangeLog
     man.path = $${INSTALL_PREFIX}/share/man/man1/
     man.files = doc/man/qnapi.1.gz
     man_it.path = $${INSTALL_PREFIX}/share/man/it/man1/
