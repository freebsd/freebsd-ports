--- ipaplatform/base/tasks.py.orig	2026-01-16 09:23:31 UTC
+++ ipaplatform/base/tasks.py
@@ -303,7 +303,7 @@ class BaseTaskNamespace:
         :param version: textual version
         :return: object implementing proper __cmp__ method for version compare
         """
-        return IPAAbstractVersion(parse_version(version))
+        return parse_version(version)
 
     def set_hostname(self, hostname):
         """
