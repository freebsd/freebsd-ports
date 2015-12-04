--- src/share/poudriere/include/fs.sh.orig	2015-11-30 17:26:08 UTC
+++ src/share/poudriere/include/fs.sh
@@ -181,6 +181,6 @@ destroyfs() {
 		rmdir ${mnt}
 	else
 		chflags -R noschg ${mnt}
-		rm -rfx ${mnt}
+		rm -rf ${mnt}
 	fi
 }
