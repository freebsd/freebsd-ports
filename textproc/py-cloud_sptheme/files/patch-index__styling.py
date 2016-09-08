--- cloud_sptheme/ext/index_styling.py.orig	2016-09-08 20:32:45 UTC
+++ cloud_sptheme/ext/index_styling.py
@@ -49,8 +49,9 @@ def mangle_index(app, pagename, template
     fmt = format_index_name
     for key, entries in ctx['genindexentries']:
         for idx, entry in enumerate(entries):
-            name, (links, subitems) = entry
-            entries[idx] = fmt(name), (links, subitems)
+            name, data = entry
+            entries[idx] = fmt(name), data
+            subitems = data[1]
             for idx, entry in enumerate(subitems):
                 name, links = entry
                 subitems[idx] = fmt(name), links
