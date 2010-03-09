--- clamav-unofficial-sigs.sh	2010-01-24 02:38:29.000000000 +0100
+++ clamav-unofficial-sigs.sh.patched	2010-03-06 08:52:32.000000000 +0100
@@ -19,7 +19,7 @@
 #                                                                              #
 ################################################################################
 
-default_config="/etc/clamav-unofficial-sigs.conf"
+default_config="%%PREFIX%%/etc/clamav-unofficial-sigs.conf"
 
 version="v3.7 (updated 2010-01-23)"
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
