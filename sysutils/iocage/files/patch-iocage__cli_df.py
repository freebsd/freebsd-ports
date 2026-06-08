--- iocage_cli/df.py.orig	2025-12-12 22:04:57 UTC
+++ iocage_cli/df.py
@@ -35,8 +35,8 @@ import texttable
     "-h",
     "-H",
     is_flag=True,
-    default=True,
-    help="For scripting, use tabs for separators.")
+    default=not ioc.CLICK_WORKAROUND,
+    help="For scripting, no headers and tabs as separators.")
 @click.option(
     "--long",
     "-l",
@@ -53,6 +53,8 @@ def cli(header, _long, _sort):
     help="Sorts the list by the given type")
 def cli(header, _long, _sort):
     """Allows a user to show resource usage of all jails."""
+    if ioc.CLICK_WORKAROUND:
+        header = not header
     table = texttable.Texttable(max_width=0)
     jail_list = ioc.IOCage().df()
 
