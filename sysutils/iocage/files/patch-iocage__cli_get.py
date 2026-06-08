--- iocage_cli/get.py.orig	2026-06-08 13:53:44 UTC
+++ iocage_cli/get.py
@@ -33,8 +33,8 @@ import iocage_lib.iocage as ioc
     max_content_width=400, ), name='get', help='Gets the specified property.')
 @click.argument('prop', required=True, default='')
 @click.argument('jail', required=True, default='')
-@click.option('--header', '-h', '-H', is_flag=True, default=True,
-              help='For scripting, use tabs for separators.')
+@click.option('--header', '-h', '-H', is_flag=True, default=not ioc.CLICK_WORKAROUND,
+              help='For scripting, no headers and tabs as separators.')
 @click.option('--recursive', '-r', help='Get the specified property for all '
                                         'jails.', flag_value='recursive')
 @click.option('--plugin', '-P',
@@ -58,6 +58,8 @@ def cli(prop, _type, _pool, jail, recursive, header, p
 )
 def cli(prop, _type, _pool, jail, recursive, header, plugin, force):
     """Get a list of jails and print the property."""
+    if ioc.CLICK_WORKAROUND:
+        header = not header
     table = texttable.Texttable(max_width=0)
 
     if _type:
