--- opt/victorops/nagios_plugin/bin/support_collect.sh.orig	2014-06-11 11:24:28.858964094 -0500
+++ opt/victorops/nagios_plugin/bin/support_collect.sh	2014-06-11 11:25:03.784958472 -0500
@@ -11,8 +11,8 @@
 TARBALL=$($DATE +%Y%m%d-%H%M)-victorops.tgz
 SUPPORT=support@victorops.com
 
-echo $TAR -cz -f $TARBALL /var/log/victorops /var/nagios
-$TAR -cz -f $TARBALL /var/log/victorops /var/nagios
+echo $TAR -cz -f $TARBALL /var/log/victorops /var/spool/nagios/victorops/alerts
+$TAR -cz -f $TARBALL /var/log/victorops /var/spool/nagios/victorops/alerts
 
 if [ -e "$MUTT" ]; then
     echo
