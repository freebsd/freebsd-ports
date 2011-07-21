$FreeBSD$

--- libzenoss/Products/ZenModel/ZenossInfo.py.orig	2011-02-08 08:07:45.000000000 -0800
+++ libzenoss/Products/ZenModel/ZenossInfo.py	2011-04-21 09:50:39.000000000 -0700
@@ -255,13 +255,7 @@
         @return: version number or ''
         @rtype: string
         """
-        try:
-            products = zenPath("Products")
-            cmd = "svn info '%s' 2>/dev/null | awk '/Revision/ {print $2}'" % products
-            fd = os.popen(cmd)
-            return fd.readlines()[0].strip()
-        except:
-            return ''
+        return ''
 
 
     def getNetSnmpVersion(self):
