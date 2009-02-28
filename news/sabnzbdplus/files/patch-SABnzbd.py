--- SABnzbd.py.bak	2009-02-23 18:06:07.000000000 -0800
+++ SABnzbd.py	2009-02-23 18:07:18.000000000 -0800
@@ -165,7 +165,7 @@
         print "fork() failed"
         sys.exit(1)
 
-    os.chdir(sabnzbd.DIR_PROG)
+    os.chdir(%%PREFIX%%)
     os.setsid()
     # Make sure I can read my own files and shut out others
     prev= os.umask(0)
@@ -303,7 +303,7 @@
     sabnzbd.MY_FULLNAME = os.path.normpath(os.path.abspath(sys.argv[0]))
     sabnzbd.MY_NAME = os.path.basename(sabnzbd.MY_FULLNAME)
     sabnzbd.DIR_PROG = os.path.dirname(sabnzbd.MY_FULLNAME)
-    sabnzbd.DIR_INTERFACES = real_path(sabnzbd.DIR_PROG, DEF_INTERFACES)
+    sabnzbd.DIR_INTERFACES = real_path(%%PREFIX%%, DEF_INTERFACES)
     
     #OSX correct path if frozen with py2app
     if getattr(sys, 'frozen', None) in ('macosx_app',):
@@ -713,7 +713,7 @@
 
     log_dir = dir_setup(cfg, 'log_dir', sabnzbd.DIR_LCLDATA, DEF_LOG_DIR)
 
-    os.chdir(sabnzbd.DIR_PROG)
+    os.chdir(%%PREFIX%%)
 
     web_dir  = Web_Template('web_dir',  DEF_STDINTF,  web_dir)
     web_dir2 = Web_Template('web_dir2', '', web_dir2)
