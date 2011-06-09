--- SABnzbd.py	2011-06-07 18:02:35.000000000 -0400
+++ SABnzbd-port.py	2011-06-08 07:20:14.948254196 -0400
@@ -916,7 +916,7 @@
 
     sabnzbd.MY_FULLNAME = os.path.normpath(os.path.abspath(sabnzbd.MY_FULLNAME))
     sabnzbd.MY_NAME = os.path.basename(sabnzbd.MY_FULLNAME)
-    sabnzbd.DIR_PROG = os.path.dirname(sabnzbd.MY_FULLNAME)
+    sabnzbd.DIR_PROG = %%PREFIX%%
     sabnzbd.DIR_INTERFACES = real_path(sabnzbd.DIR_PROG, DEF_INTERFACES)
     sabnzbd.DIR_LANGUAGE = real_path(sabnzbd.DIR_PROG, DEF_LANGUAGE)
     org_dir = os.getcwd()
