--- tools/codegen/gentable.py.orig	2015-05-05 00:16:41 UTC
+++ tools/codegen/gentable.py
@@ -30,9 +30,15 @@ TEMPLATES = {}
 # Temporary reserved column names
 RESERVED = ["n", "index"]
 
-# Supported SQL types for spec
-
+# Set the platform in osquery-language
+if sys.platform.find("freebsd") == 0:
+    PLATFORM = "freebsd"
+elif sys.platform in ["linux", "linux2"]:
+    PLATFORM = "linux"
+else:
+    PLATFORM = sys.platform
 
+# Supported SQL types for spec
 class DataType(object):
 
     def __init__(self, affinity, cpp_type="std::string"):
@@ -79,6 +85,8 @@ def is_blacklisted(table_name, path=None
     """Allow blacklisting by tablename."""
     if blacklist is None:
         specs_path = os.path.dirname(os.path.dirname(path))
+        if os.path.basename(specs_path) == "tables":
+            specs_path += "/specs"
         blacklist_path = os.path.join(specs_path, "blacklist")
         if not os.path.exists(blacklist_path):
             return False
@@ -91,9 +99,19 @@ def is_blacklisted(table_name, path=None
         except:
             # Blacklist is not readable.
             return False
-    # table_name based blacklisting!
-    return table_name in blacklist if blacklist else False
+    if not blacklist:
+        return False
 
+    # table_name based blacklisting!
+    for item in blacklist:
+        item = item.split(":")
+        # If this item is restricted to a platform and the platform
+        # and table name match
+        if len(item) > 1 and PLATFORM == item[0] and table_name == item[1]:
+            return True
+        elif len(item) == 1 and table_name == item[0]:
+            return True
+    return False
 
 def setup_templates(path):
     tables_path = os.path.dirname(os.path.dirname(path))
