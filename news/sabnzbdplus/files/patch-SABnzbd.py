--- SABnzbd.py.bak	2008-01-05 11:52:46.000000000 -0800
+++ SABnzbd.py	2008-01-05 11:57:12.000000000 -0800
@@ -492,7 +492,7 @@
         web_dir = DEF_STDINTF
     cfg['misc']['web_dir'] = web_dir
 
-    sabnzbd.DIR_INTERFACES = real_path(sabnzbd.DIR_PROG, DEF_INTERFACES)
+    sabnzbd.DIR_INTERFACES = real_path(%%PREFIX%%, DEF_INTERFACES)
     web_dir = real_path(sabnzbd.DIR_INTERFACES, web_dir)
     web_main = real_path(web_dir, DEF_MAIN_TMPL)
     logging.info("Web dir is %s", web_dir)
