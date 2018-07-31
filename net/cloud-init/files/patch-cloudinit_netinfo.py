--- cloudinit/netinfo.py.orig	2018-07-31 21:06:07 UTC
+++ cloudinit/netinfo.py
@@ -138,9 +138,10 @@ def _netdev_info_ifconfig(ifconfig_data)
             elif toks[i].startswith("scope:"):
                 devs[curdev]['ipv6'][-1]['scope6'] = toks[i].lstrip("scope:")
             elif toks[i] == "scopeid":
-                res = re.match(r'.*<(\S+)>', toks[i + 1])
-                if res:
-                    devs[curdev]['ipv6'][-1]['scope6'] = res.group(1)
+                if toks[i + 1] == "0x1":
+                    devs[curdev]['ipv6']['scope6'] = "Global"
+                elif toks[i + 1] == "0x2":
+                    devs[curdev]['ipv6']['scope6'] = "Link"
     return devs
 
 
