--- gui/gui.pro.orig	2018-12-02 16:33:46 UTC
+++ gui/gui.pro
@@ -138,7 +138,7 @@ unix {
 	desktopfile.path = $${PREFIX}/share/applications
         desktopfile.files = ../actiona.desktop
 
-	manfile.path = $${PREFIX}/share/man/man1
+	manfile.path = $${PREFIX}/man/man1
         manfile.files = ../docs/actiona.1
 
 	mimefile.path = $${PREFIX}/share/mime/packages/
