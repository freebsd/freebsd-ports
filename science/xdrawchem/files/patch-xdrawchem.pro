--- xdrawchem.pro.orig	2017-01-09 12:25:32 UTC
+++ xdrawchem.pro
@@ -6,8 +6,8 @@ exists(/usr/include/openbabel-2.0/openbabel/mol.h) {
 INCLUDEPATH += /usr/include/openbabel-2.0
 LIBS += -lopenbabel
 }
-exists(/usr/local/include/openbabel-2.0/openbabel/mol.h) {
-INCLUDEPATH += /usr/local/include/openbabel-2.0
+exists(%%LOCALBASE%%/include/openbabel3/openbabel/mol.h) {
+INCLUDEPATH += %%LOCALBASE%%/include/openbabel3
 LIBS += -lopenbabel
 }
 exists(/Developer/openbabel-2.4.1/include/openbabel/mol.h) {
