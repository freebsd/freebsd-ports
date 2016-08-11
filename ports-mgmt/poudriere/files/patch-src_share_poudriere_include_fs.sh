--- src/share/poudriere/include/fs.sh.orig	2016-05-18 22:58:28 UTC
+++ src/share/poudriere/include/fs.sh
@@ -191,10 +191,10 @@ destroyfs() {
 		zfs destroy -rf ${fs}
 		rmdir ${mnt}
 	else
-		rm -rfx ${mnt} 2>/dev/null || :
+		rm -rf ${mnt} 2>/dev/null || :
 		if [ -d "${mnt}" ]; then
 			chflags -R 0 ${mnt}
-			rm -rfx ${mnt}
+			rm -rf ${mnt}
 		fi
 	fi
 }
