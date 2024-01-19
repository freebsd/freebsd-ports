Add backwards compatibility for textproc/py-markdown < 3.4.

Previous releases of py-markdown cannot access the "use_align_attribute"
configuration option, which was introduced with py-markdown 3.4.

--- netbox/utilities/templatetags/builtins/filters.py.orig	2023-12-29 15:02:38 UTC
+++ netbox/utilities/templatetags/builtins/filters.py
@@ -163,12 +163,20 @@ def render_markdown(value):
     if not value:
         return ''
 
+    TE_Shim = None
+
+    try:
+        TE_Shim = TableExtension(use_align_attribute=True)
+    except KeyError:
+        TE_Shim = TableExtension()
+        pass
+
     # Render Markdown
     html = markdown(value, extensions=[
         'def_list',
         'fenced_code',
         StrikethroughExtension(),
-        TableExtension(use_align_attribute=True),
+        TE_Shim,
     ])
 
     # If the string is not empty wrap it in rendered-markdown to style tables
