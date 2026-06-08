--- iocage_cli/snaplist.py.orig	2025-12-12 22:04:57 UTC
+++ iocage_cli/snaplist.py
@@ -30,8 +30,8 @@ import iocage_lib.iocage as ioc
 
 
 @click.command(name="snaplist", help="Show snapshots of a specified jail.")
-@click.option("--header", "-h", "-H", is_flag=True, default=True,
-              help="For scripting, use tabs for separators.")
+@click.option("--header", "-h", "-H", is_flag=True, default=not ioc.CLICK_WORKAROUND,
+              help="For scripting, no headers and tabs as separators.")
 @click.option("--long", "-l", "_long", is_flag=True, default=False,
               help="Show the full dataset path for snapshot name.")
 @click.option("--sort", "-s", "_sort", default="created", nargs=1,
@@ -39,6 +39,9 @@ def cli(header, jail, _long, _sort):
 @click.argument("jail")
 def cli(header, jail, _long, _sort):
     """Allows a user to show resource usage of all jails."""
+
+    if ioc.CLICK_WORKAROUND:
+        header = not header
     table = texttable.Texttable(max_width=0)
     snap_list = ioc.IOCage(jail=jail).snap_list(_long, _sort)
 
