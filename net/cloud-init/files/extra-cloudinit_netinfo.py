--- cloudinit/netinfo.py.orig	2025-09-01 15:44:21 UTC
+++ cloudinit/netinfo.py
@@ -558,7 +558,7 @@ def route_info():
     elif subp.which("netstat"):
         # Fall back to net-tools if iproute2 is not present
         (route_out, _err) = subp.subp(
-            ["netstat", "--route", "--numeric", "--extend"], rcs=[0, 1]
+            ["netstat", "--route", "--numeric", "--extend"], rcs=[0, 1, 64]
         )
         routes = _netdev_route_info_netstat(route_out)
     else:
