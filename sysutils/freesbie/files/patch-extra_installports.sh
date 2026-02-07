--- extra/installports.sh.orig	2007-01-04 18:28:56 UTC
+++ extra/installports.sh
@@ -35,7 +35,7 @@ if [ ! -z "${INSTALL_PORTS}" ]; then
 	mkdir -p ${BASEDIR}/usr/ports ${BASEDIR}/usr/src
 	mount_nullfs ${PORTSDIR:-/usr/ports} ${BASEDIR}/usr/ports
 	mount_nullfs ${SRCDIR:-/usr/src} ${BASEDIR}/usr/src
-	mount_devfs none ${BASEDIR}/dev
+	mount -t devfs none ${BASEDIR}/dev
 
 	print_error_umount() {
 		echo "Something went wrong, check errors!" >&2
