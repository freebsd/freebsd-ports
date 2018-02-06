--- src/share/poudriere/image.sh.orig	2018-02-06 16:22:49.894625000 +0000
+++ src/share/poudriere/image.sh	2018-02-06 16:25:14.320814000 +0000
@@ -314,7 +314,7 @@
 if [ -n "${HOSTNAME}" ]; then
 	mkdir -p ${WRKDIR}/world/etc/rc.conf.d
 	echo "hostname=${HOSTNAME}" > ${WRKDIR}/world/etc/rc.conf.d/hostname
-else
+fi
 
 [ ! -d "${EXTRADIR}" ] || cp -fRLp ${EXTRADIR}/ ${WRKDIR}/world/
 mv ${WRKDIR}/world/etc/login.conf.orig ${WRKDIR}/world/etc/login.conf
