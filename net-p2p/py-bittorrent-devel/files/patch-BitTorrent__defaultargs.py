--- ./BitTorrent/defaultargs.py.orig	Mon Jun 12 22:45:58 2006
+++ ./BitTorrent/defaultargs.py	Wed Jun 21 23:57:08 2006
@@ -20,6 +20,8 @@
 if os.name == 'posix':
     if os.uname()[0] in ['Darwin']:
         BAD_LIBC_WORKAROUND_DEFAULT = True
+    if os.uname()[0] in ['FreeBSD']:
+        BAD_LIBC_WORKAROUND_DEFAULT = True
 
 MAX_INCOMPLETE = 100
 MAX_FILES_OPEN = 50
@@ -372,6 +374,10 @@
                "name determined by --saveas_style. If this is left empty "
                "each torrent will be saved under the directory of the "
                "corresponding .torrent file")),
+            ('save_incomplete_in', '',
+             _("local directory where the incomplete torrent downloads will be "
+               "stored until completion.  Upon completion, downloads will be "
+               "moved to the directory specified by --save_in.")),
             ('parse_dir_interval', 60,
               _("how often to rescan the torrent directory, in seconds") ),
             ('launch_delay', 0,
