--- clamav-unofficial-sigs.sh	2013-08-27 18:08:25.000000000 +0200
+++ clamav-unofficial-sigs.sh.patched	2013-09-04 16:10:35.000000000 +0200
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
