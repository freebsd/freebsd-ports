--- extra/varmfs.sh.orig	2006-04-24 11:14:33 UTC
+++ extra/varmfs.sh
@@ -28,4 +28,4 @@ mtree -Pcp ${BASEDIR}/var > ${TMPFILE}
 mv ${TMPFILE} ${BASEDIR}/etc/mtree/var.dist
 
 echo "Generating pkg_info.txt"
-chroot ${BASEDIR} pkg_info > ${BASEDIR}/pkg_info.txt
+chroot ${BASEDIR} pkg info > ${BASEDIR}/pkg_info.txt
