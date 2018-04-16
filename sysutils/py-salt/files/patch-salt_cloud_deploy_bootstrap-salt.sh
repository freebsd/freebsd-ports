--- salt/cloud/deploy/bootstrap-salt.sh.orig	2018-03-21 17:37:20 UTC
+++ salt/cloud/deploy/bootstrap-salt.sh
@@ -4885,9 +4885,9 @@ install_freebsd_9_stable_deps() {
         __configure_freebsd_pkg_details || return 1
     fi
 
-    # Now install swig
+    # Now install swig30
     # shellcheck disable=SC2086
-    /usr/local/sbin/pkg install ${FROM_FREEBSD} -y swig || return 1
+    /usr/local/sbin/pkg install ${FROM_FREEBSD} -y swig30 || return 1
 
     # YAML module is used for generating custom master/minion configs
     # shellcheck disable=SC2086
