--- cloudinit/distros/freebsd.py.orig	2025-08-12 19:00:58 UTC
+++ cloudinit/distros/freebsd.py
@@ -35,7 +35,7 @@ class Distro(cloudinit.distros.bsd.BSD):
     pkg_cmd_update_prefix = ["pkg", "update"]
     pkg_cmd_upgrade_prefix = ["pkg", "upgrade"]
     prefer_fqdn = True  # See rc.conf(5) in FreeBSD
-    home_dir = "/usr/home"
+    home_dir = "/home"
     # FreeBSD has the following dhclient lease path:
     # /var/db/dhclient.leases.<iface_name>
     dhclient_lease_directory = "/var/db"
