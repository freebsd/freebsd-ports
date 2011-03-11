--- SABnzbd.py.orig	2010-06-26 13:24:26.000000000 -0400
+++ SABnzbd.py	2010-08-17 23:46:04.347483234 -0400
@@ -214,7 +214,7 @@
         print "fork() failed"
         sys.exit(1)
 
-    os.chdir(sabnzbd.DIR_PROG)
+    os.chdir(%%PREFIX%%)
     os.setsid()
     # Make sure I can read my own files and shut out others
     prev= os.umask(0)
@@ -657,8 +657,8 @@
     sabnzbd.MY_FULLNAME = os.path.normpath(os.path.abspath(sys.argv[0]))
     sabnzbd.MY_NAME = os.path.basename(sabnzbd.MY_FULLNAME)
     sabnzbd.DIR_PROG = os.path.dirname(sabnzbd.MY_FULLNAME)
-    sabnzbd.DIR_INTERFACES = real_path(sabnzbd.DIR_PROG, DEF_INTERFACES)
-    sabnzbd.DIR_LANGUAGE = real_path(sabnzbd.DIR_PROG, DEF_LANGUAGE)
+    sabnzbd.DIR_INTERFACES = real_path(%%PREFIX%%, DEF_INTERFACES)
+    sabnzbd.DIR_LANGUAGE = real_path(%%PREFIX%%, DEF_LANGUAGE)
     org_dir = os.getcwd()
 
     if getattr(sys, 'frozen', None) == 'macosx_app':
@@ -995,7 +995,7 @@
                       sabnzbd.MY_NAME, sabnzbd.__version__)
         exit_sab(2)
 
-    os.chdir(sabnzbd.DIR_PROG)
+    os.chdir(%%PREFIX%%)
 
     web_dir  = Web_Template(sabnzbd.cfg.WEB_DIR,  DEF_STDINTF,  fix_webname(web_dir))
     web_dir2 = Web_Template(sabnzbd.cfg.WEB_DIR2, '', fix_webname(web_dir2))
