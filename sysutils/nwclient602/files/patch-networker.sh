--- networker.sh.orig	Sun Apr 23 07:58:18 2000
+++ networker.sh	Wed Apr 16 00:25:47 2003
@@ -3,6 +3,7 @@
 # Copyright (c) 2000, by Feral Software
 # All Rights Reserved
 #
+ulimit -n 5000
 ROOTDIR=
 NSRDIR=${ROOTDIR}/nsr
 if [ -x ${NSRDIR}/bin/nsrexecd ];
