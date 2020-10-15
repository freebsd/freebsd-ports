--- ttp/match/ip.py.orig	2020-08-16 22:06:01 UTC
+++ ttp/match/ip.py
@@ -5,9 +5,9 @@ log = logging.getLogger(__name__)
 
 def to_ip(data, *args):
     # for py2 support need to convert data to unicode:
-    if _ttp_["python_major_version"] is 2:
+    if _ttp_["python_major_version"] == 2:
         ipaddr_data = unicode(data)
-    elif _ttp_["python_major_version"] is 3:
+    elif _ttp_["python_major_version"] == 3:
         ipaddr_data = data
     if "ipv4" in args:
         if "/" in ipaddr_data or " " in ipaddr_data:
@@ -33,9 +33,9 @@ def is_ip(data, *args):
 		
 def to_net(data, *args):
     # for py2 support need to convert data to unicode:
-    if _ttp_["python_major_version"] is 2:
+    if _ttp_["python_major_version"] == 2:
         ipaddr_data = unicode(data)
-    elif _ttp_["python_major_version"] is 3:
+    elif _ttp_["python_major_version"] == 3:
         ipaddr_data = data
     if "ipv4" in args:
         return ipaddress.IPv4Network(ipaddr_data), None
@@ -124,21 +124,21 @@ def cidr_match(data, prefix):
         check = ip_obj.network.overlaps(ip_net)
     elif isinstance(ip_obj, ipaddress.IPv4Address) or isinstance(ip_obj, ipaddress.IPv6Address):
         # if object is ipaddress, need to convert it into ipinterface with /32 mask:
-        if ip_obj.version is 4:
+        if ip_obj.version == 4:
             # for py2 support need to convert data to unicode:
-            if _ttp_["python_major_version"] is 2:
+            if _ttp_["python_major_version"] == 2:
                 ipaddr_data = unicode("{}/32".format(str(ip_obj)))
-            elif _ttp_["python_major_version"] is 3:
+            elif _ttp_["python_major_version"] == 3:
                 ipaddr_data = "{}/32".format(str(ip_obj))
             ip_obj = ipaddress.IPv4Interface(ipaddr_data)
-        elif ip_obj.version is 6:
+        elif ip_obj.version == 6:
             # for py2 support need to convert data to unicode:
-            if _ttp_["python_major_version"] is 2:
+            if _ttp_["python_major_version"] == 2:
                 ipaddr_data = unicode("{}/128".format(str(ip_obj)))
-            elif _ttp_["python_major_version"] is 3:
+            elif _ttp_["python_major_version"] == 3:
                 ipaddr_data = "{}/128".format(str(ip_obj))
             ip_obj = ipaddress.IPv6Interface(ipaddr_data)
         check = ip_obj.network.overlaps(ip_net)
     else:
         check = None
-    return data, check
\ No newline at end of file
+    return data, check
