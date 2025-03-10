--- cloudinit/distros/freebsd.py.orig	2024-10-30 12:25:07 UTC
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
