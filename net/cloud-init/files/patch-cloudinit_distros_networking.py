--- cloudinit/distros/networking.py.orig	2022-12-11 19:43:15 UTC
+++ cloudinit/distros/networking.py
@@ -190,6 +190,7 @@ class BSDNetworking(Networking):
         self.ifc = ifconfig.Ifconfig()
         self.ifs = {}
         self._update_ifs()
+        super().__init__()
 
     def _update_ifs(self):
         ifconf = subp.subp(["ifconfig", "-a"])
