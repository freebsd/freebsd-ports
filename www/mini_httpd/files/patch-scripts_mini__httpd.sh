--- scripts/mini_httpd.sh.orig	2016-06-18 20:06:02 UTC
+++ scripts/mini_httpd.sh
@@ -22,6 +22,7 @@
 name='mini_httpd'
 rcvar='mini_httpd_enable'
 start_precmd='mini_httpd_precmd'
+stop_postcmd='mini_httpd_poststop'
 mini_httpd_enable_defval='NO'
 
 load_rc_config "$name"
@@ -35,6 +36,13 @@ mini_httpd_precmd ()
 		mount -t devfs devfs "$mini_httpd_devfs"
 		devfs -m "$mini_httpd_devfs" rule -s 1 applyset
 		devfs -m "$mini_httpd_devfs" rule -s 2 applyset
+	fi
+}
+
+mini_httpd_poststop ()
+{
+	if [ -n "$mini_httpd_devfs" -a "$mini_httpd_devfs" != "/dev" ]; then
+		umount "$mini_httpd_devfs"
 	fi
 }
 
