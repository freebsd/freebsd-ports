--- ./src/share/poudriere/testport.sh.orig	2013-09-23 08:16:41.841131967 -0500
+++ ./src/share/poudriere/testport.sh	2013-09-23 08:16:54.533133490 -0500
@@ -185,7 +185,7 @@
 
 if [ -f ${MASTERMNT}/tmp/pkgs/${PKGNAME}.${PKG_EXT} ]; then
 	msg "Installing from package"
-	injail ${PKG_ADD} /tmp/pkgs/${PKGNAME}.${PKG_EXT}
+	injail ${PKG_ADD} /tmp/pkgs/${PKGNAME}.${PKG_EXT} || :
 fi
 
 # Interactive test mode
