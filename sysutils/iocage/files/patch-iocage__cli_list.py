--- iocage_cli/list.py.orig	2025-12-12 22:04:57 UTC
+++ iocage_cli/list.py
@@ -26,7 +26,6 @@ import iocage_lib.iocage as ioc
 import iocage_lib.ioc_common as ioc_common
 import iocage_lib.iocage as ioc
 
-
 @click.command(
     name="list",
     help="List a specified dataset type, by default lists all jails.")
@@ -36,15 +35,15 @@ import iocage_lib.iocage as ioc
               flag_value="basejail", help="List all basejails.")
 @click.option("--template", "-t", "dataset_type", flag_value="template",
               help="List all templates.")
-@click.option("--header", "-h", "-H", is_flag=True, default=True,
-              help="For scripting, use tabs for separators.")
+@click.option("--header", "-h", "-H", is_flag=True, default=not ioc.CLICK_WORKAROUND,
+              help="For scripting, no headers and tabs as separators.")
 @click.option("--long", "-l", "_long", is_flag=True, default=False,
               help="Show the full uuid and ip4 address.")
 @click.option("--remote", "-R", is_flag=True,
               help="Show remote's available RELEASEs.")
 @click.option("--plugins", "-P", is_flag=True, help="Show available plugins.")
-@click.option("--http", default=True, help="Have --remote use HTTP instead.",
-              is_flag=True)
+@click.option("--http", is_flag=True, default=not ioc.CLICK_WORKAROUND,
+              help="Have --remote not use HTTP.")
 @click.option("--sort", "-s", "_sort", default="name", nargs=1,
               help="Sorts the list by the given type")
 @click.option("--quick", "-q", is_flag=True, default=False,
@@ -54,6 +53,10 @@ def cli(dataset_type, header, _long, remote, http, plu
 def cli(dataset_type, header, _long, remote, http, plugins, _sort, quick,
         official):
     """This passes the arg and calls the jail_datasets function."""
+
+    if ioc.CLICK_WORKAROUND:
+        header = not header
+        http = not http
     freebsd_version = ioc_common.checkoutput(["freebsd-version"])
     iocage = ioc.IOCage(skip_jails=True)
 
