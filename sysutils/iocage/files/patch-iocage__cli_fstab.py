--- iocage_cli/fstab.py.orig	2026-06-08 13:53:38 UTC
+++ iocage_cli/fstab.py
@@ -45,13 +45,15 @@ __rootcmd__ = True
               help="Replace an entry by index number", nargs=1)
 @click.option("--list", "-l", "action",
               help="Lists the jails fstab.", flag_value="list")
-@click.option("--header", "-h", "-H", is_flag=True, default=True,
-              help="For scripting, use tabs for separators.")
+@click.option("--header", "-h", "-H", is_flag=True, default=not ioc.CLICK_WORKAROUND,
+              help="For scripting, no headers and tabs as separators.")
 def cli(action, fstab_string, jail, header, replace):
     """
     Looks for the jail supplied and passes the uuid, path and configuration
     location to manipulate the fstab.
     """
+    if ioc.CLICK_WORKAROUND:
+        header = not header
     index = None if not replace else replace
     _index = False
     add_path = False
