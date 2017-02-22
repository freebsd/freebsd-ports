--- src/share/poudriere/include/fs.sh.orig	2017-02-22 20:34:08 UTC
+++ src/share/poudriere/include/fs.sh
@@ -98,7 +98,7 @@ umountfs() {
 
 	[ -d "${mnt}" ] || return 0
 	mnt=$(realpath ${mnt})
-	if ! findmounts "${mnt}" "${pattern}" | xargs umount -n; then
+	if ! findmounts "${mnt}" "${pattern}" | xargs umount -f; then
 		findmounts "${mnt}" "${pattern}" | xargs umount -fv || :
 	fi
 
@@ -198,7 +198,7 @@ destroyfs() {
 	umountfs ${mnt} 1
 	if [ ${TMPFS_ALL} -eq 1 ]; then
 		if [ -d "${mnt}" ]; then
-			if ! umount -n "${mnt}" 2>/dev/null; then
+			if ! umount -f "${mnt}" 2>/dev/null; then
 				umount -f "${mnt}" 2>/dev/null || :
 			fi
 		fi
