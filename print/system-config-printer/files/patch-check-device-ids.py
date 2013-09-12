--- check-device-ids.py.orig	2013-08-29 15:52:05.000000000 +0200
+++ check-device-ids.py	2013-08-29 15:53:34.000000000 +0200
@@ -205,11 +205,11 @@
         elif uri.startswith ("lsb/local/"):
             return "/usr/local/share/ppd/" + uri[10:]
 
-        return "/usr/share/cups/model/" + uri
+        return "%%PREFIX%%/share/cups/model/" + uri
 
     scheme = schemeparts[0]
     if scheme != "drv":
-        return "/usr/lib/cups/driver/" + scheme
+        return "%%PREFIX%%/libexec/cups/driver/" + scheme
 
     rest = schemeparts[1]
     rest = rest.lstrip ('/')
@@ -217,7 +217,7 @@
     if len (parts) > 1:
         parts = parts[:len (parts) - 1]
 
-    return "/usr/share/cups/drv/" + reduce (lambda x, y: x + "/" + y, parts)
+    return "%%PREFIX%%/share/cups/drv/" + reduce (lambda x, y: x + "/" + y, parts)
 
 def driver_uri_to_pkg (uri):
     filename = driver_uri_to_filename (uri)
