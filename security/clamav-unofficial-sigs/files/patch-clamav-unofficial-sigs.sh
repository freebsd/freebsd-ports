--- clamav-unofficial-sigs.sh	2013-08-27 18:08:25.000000000 +0200
+++ clamav-unofficial-sigs.sh.patched	2014-12-06 23:55:50.000000000 +0100
@@ -16,7 +16,7 @@
 #                                                                              #
 ################################################################################
 
-default_config="/etc/clamav-unofficial-sigs.conf"
+default_config="%%PREFIX%%/etc/clamav-unofficial-sigs.conf"
 
 version="v3.7.2 (updated 2013-08-25)"
 output_ver="
@@ -418,6 +418,8 @@
           exit
           ;;
       r)  no_default_config
+          pkg_mgr="FreeBSD ports"
+          pkg_rm="pkg_delete"
           if [ -n "$pkg_mgr" -a -n "$pkg_rm" ]
              then
                 echo "  This script (clamav-unofficial-sigs) was installed on the system"
@@ -1016,9 +1018,9 @@
    comment "======================================================================"
    comment "Sanesecurity Database & GPG Signature File Updates"
    comment "======================================================================"
-   ss_mirror_ips=`dig +ignore +short $ss_url`
+   ss_mirror_ips=`host $ss_url | sed 's/.*\s//'`
    for ss_mirror_ip in $ss_mirror_ips ; do
-      ss_mirror_name=`dig +short -x $ss_mirror_ip | sed 's/\.$//'`
+      ss_mirror_name=`host $ss_mirror_ip | sed 's/.*\s//' | sed 's/\.$//'`
       ss_mirror_site_info="$ss_mirror_name $ss_mirror_ip"
       comment ""
       comment "Sanesecurity mirror site used: $ss_mirror_site_info"
