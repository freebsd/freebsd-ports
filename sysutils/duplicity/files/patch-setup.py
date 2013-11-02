--- setup.py.orig	2013-08-22 15:30:09.000000000 +0200
+++ setup.py	2013-10-06 19:43:39.000000000 +0200
@@ -26,11 +26,15 @@
 version_string = "0.6.22"
 
 if sys.version_info[:2] < (2,4):
-    print "Sorry, duplicity requires version 2.4 or later of python"
+    print("Sorry, duplicity requires version 2.4 or later of python")
     sys.exit(1)
 
 incdir_list = libdir_list = None
 
+LOCALBASE = os.environ.get("LOCALBASE", "/usr/local")
+incdir_list = ['%s/include' % LOCALBASE]
+libdir_list = ['%s/lib/' % LOCALBASE]
+
 if os.name == 'posix':
     LIBRSYNC_DIR = os.environ.get('LIBRSYNC_DIR', '')
     args = sys.argv[:]
@@ -42,17 +46,9 @@
         incdir_list = [os.path.join(LIBRSYNC_DIR, 'include')]
         libdir_list = [os.path.join(LIBRSYNC_DIR, 'lib')]
 
-data_files = [('share/man/man1',
+data_files = [('man/man1',
                ['bin/duplicity.1',
                 'bin/rdiffdir.1']),
-              ('share/doc/duplicity-%s' % version_string,
-               ['COPYING',
-                'README',
-                'README-REPO',
-                'README-LOG',
-                'tarfile-LICENSE',
-                'tarfile-CHANGES',
-                'CHANGELOG']),
               ]
 
 assert os.path.exists("po"), "Missing 'po' directory."
