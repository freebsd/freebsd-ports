--- xdrawchem.pro.orig	2021-01-06 18:45:48 UTC
+++ xdrawchem.pro
@@ -2,17 +2,17 @@ TEMPLATE = app
 TARGET = xdrawchem
 
 # edit to match your OB install
-exists(/usr/include/openbabel3/openbabel/mol.h) {
-INCLUDEPATH += /usr/include/openbabel3
+exists(%%LOCALBASE%%/include/openbabel3/openbabel/mol.h) {
+INCLUDEPATH += %%LOCALBASE%%/include/openbabel3
 LIBS += -lopenbabel
 }
-exists(/usr/local/include/openbabel-3.0/openbabel/mol.h) {
-INCLUDEPATH += /usr/local/include/openbabel-3.0
+exists(%%LOCALBASE%%/include/openbabel3/openbabel/mol.h) {
+INCLUDEPATH += %%LOCALBASE%%/include/openbabel3
 LIBS += -lopenbabel
 }
-exists(/Developer/openbabel-3.0/include/openbabel/mol.h) {
-INCLUDEPATH += /Developer/openbabel-3.0/include
-LIBS += -L/Developer/openbabel-3.0/lib/Debug -lopenbabel
+exists(%%LOCALBASE%%/openbabel3/include/openbabel/mol.h) {
+INCLUDEPATH += /Developer/openbabel3/include
+LIBS += -L/Developer/openbabel3/lib/Debug -lopenbabel
 }
 # exit if openbabel wasn't found
 contains( LIBS, -lopenbabel ) {
@@ -20,12 +20,12 @@ contains( LIBS, -lopenbabel ) {
 error(OpenBabel was not found.  Edit xdrawchem.pro and add valid include and lib values)
 # if you get this error, comment the above with #, uncomment the variables below, and set
 # the paths to match your OpenBabel install
-#INCLUDEPATH += /usr/local/include/openbabel-3.0
+#INCLUDEPATH += %%LOCALBASE%%/include/openbabel-3.0
 #LIBS += -lopenbabel
 }
 # set PREFIX if not set (it is set when building RPM)
 isEmpty(PREFIX) {
-PREFIX = /usr/local
+PREFIX = %%LOCALBASE%%
 }
 
 DESTDIR = bin
