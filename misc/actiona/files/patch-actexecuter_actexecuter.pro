--- actexecuter/actexecuter.pro.orig	2018-12-02 16:33:24 UTC
+++ actexecuter/actexecuter.pro
@@ -54,7 +54,7 @@ unix {
         locales.files = ../locale/actexecuter_fr_FR.qm
 	locales.CONFIG = no_check_exist
 
-	manfile.path = $${PREFIX}/share/man/man1
+	manfile.path = $${PREFIX}/man/man1
 	manfile.files = ../docs/actexec.1
 
 	INSTALLS += target locales manfile
