--- iocage_lib/ioc_fetch.py.orig	2024-09-20 06:45:27 UTC
+++ iocage_lib/ioc_fetch.py
@@ -47,7 +47,10 @@ import iocage_lib.ioc_start
 from iocage_lib.pools import Pool
 from iocage_lib.dataset import Dataset
 
+# deliberately crash if tarfile doesn't have required filter
+tarfile.tar_filter
 
+
 class IOCFetch:
 
     """Fetch a RELEASE for use as a jail base."""
@@ -817,7 +820,7 @@ class IOCFetch:
             # removing them first.
             member = self.__fetch_extract_remove__(f)
             member = self.__fetch_check_members__(member)
-            f.extractall(dest, members=member)
+            f.extractall(dest, members=member, filter='tar')
 
     def fetch_update(self, cli=False, uuid=None):
         """This calls 'freebsd-update' to update the fetched RELEASE."""
