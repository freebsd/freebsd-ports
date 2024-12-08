--- iocage_lib/ioc_fetch.py.orig	2024-09-20 06:45:27 UTC
+++ iocage_lib/ioc_fetch.py
@@ -47,6 +47,29 @@ import iocage_lib.ioc_start
 from iocage_lib.pools import Pool
 from iocage_lib.dataset import Dataset
 
+# taken from tarfile.tar_filter (and _get_filtered_attrs)
+# basically the same, but **without**:
+# - Clear high mode bits (setuid, setgid, sticky) and
+#   group/other write bits (S_IWGRP | S_IWOTH).
+def untar_release_filter(member, dest_path):
+    new_attrs = {}
+    name = member.name
+    dest_path = os.path.realpath(dest_path)
+    # Strip leading / (tar's directory separator) from filenames.
+    # Include os.sep (target OS directory separator) as well.
+    if name.startswith(('/', os.sep)):
+        name = new_attrs['name'] = member.path.lstrip('/' + os.sep)
+    if os.path.isabs(name):
+        # Path is absolute even after stripping.
+        # For example, 'C:/foo' on Windows.
+        raise tarfile.AbsolutePathError(member)
+    # Ensure we stay in the destination
+    target_path = os.path.realpath(os.path.join(dest_path, name))
+    if os.path.commonpath([target_path, dest_path]) != dest_path:
+        raise tarfile.OutsideDestinationError(member, target_path)
+    if new_attrs:
+        return member.replace(**new_attrs, deep=False)
+    return member
 
 class IOCFetch:
 
@@ -817,7 +840,7 @@ class IOCFetch:
             # removing them first.
             member = self.__fetch_extract_remove__(f)
             member = self.__fetch_check_members__(member)
-            f.extractall(dest, members=member)
+            f.extractall(dest, members=member, filter=untar_release_filter)
 
     def fetch_update(self, cli=False, uuid=None):
         """This calls 'freebsd-update' to update the fetched RELEASE."""
