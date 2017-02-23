--- src/share/poudriere/common.sh.orig	2017-02-22 20:34:08 UTC
+++ src/share/poudriere/common.sh
@@ -3216,7 +3216,7 @@ build_pkg() {
 
 	if [ ${TMPFS_LOCALBASE} -eq 1 -o ${TMPFS_ALL} -eq 1 ]; then
 		if [ -f "${mnt}/${LOCALBASE:-/usr/local}/.mounted" ]; then
-			umount -n ${mnt}/${LOCALBASE:-/usr/local}
+			umount -f ${mnt}/${LOCALBASE:-/usr/local}
 		fi
 		mnt_tmpfs localbase ${mnt}/${LOCALBASE:-/usr/local}
 		do_clone "${MASTERMNT}/${LOCALBASE:-/usr/local}" \
@@ -3322,7 +3322,7 @@ stop_build() {
 		_my_path mnt
 
 		if [ -f "${mnt}/.npkg_mounted" ]; then
-			umount -n "${mnt}/.npkg"
+			umount -f "${mnt}/.npkg"
 			rm -f "${mnt}/.npkg_mounted"
 		fi
 		rm -rf "${PACKAGES}/.npkg/${PKGNAME}"
@@ -4693,12 +4693,12 @@ clean_restricted() {
 	bset status "clean_restricted:"
 	# Remount rw
 	# mount_nullfs does not support mount -u
-	umount -n ${MASTERMNT}/packages
+	umount -f ${MASTERMNT}/packages
 	mount_packages
 	injail /usr/bin/make -s -C /usr/ports -j ${PARALLEL_JOBS} \
 	    RM="/bin/rm -fv" ECHO_MSG="true" clean-restricted
 	# Remount ro
-	umount -n ${MASTERMNT}/packages
+	umount -f ${MASTERMNT}/packages
 	mount_packages -o ro
 }
 
