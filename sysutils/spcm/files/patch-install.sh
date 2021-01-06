--- install.sh.orig	2021-01-06 01:45:59 UTC
+++ install.sh
@@ -47,7 +47,7 @@ fi
 chmod o-rwx ${DESTDIR}${PREFIX}/sbin/*
 
 install -c cluster-passwd ${DESTDIR}${PREFIX}/bin
-chmod 6555 ${DESTDIR}${PREFIX}/bin/cluster-passwd
+#chmod 6555 ${DESTDIR}${PREFIX}/bin/cluster-passwd
 
 # FIXME: Create and install man pages
 
