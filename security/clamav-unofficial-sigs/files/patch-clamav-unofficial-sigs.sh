--- clamav-unofficial-sigs.sh	2010-06-06 18:43:07.000000000 +0200
+++ clamav-unofficial-sigs.sh.patched	2010-06-07 18:42:17.000000000 +0200
@@ -19,7 +19,7 @@
 #                                                                              #
 ################################################################################
 
-default_config="/etc/clamav-unofficial-sigs.conf"
+default_config="%%PREFIX%%/etc/clamav-unofficial-sigs.conf"
 
 version="v3.7.1 (updated 2010-06-06)"
 output_ver="
@@ -407,6 +407,8 @@
           exit
           ;;
       r)  no_default_config
+          pkg_mgr="FreeBSD ports"
+          pkg_rm="pkg_delete"
           if [ -n "$pkg_mgr" -a -n "$pkg_rm" ]
              then
                 echo "  This script (clamav-unofficial-sigs) was installed on the system"
