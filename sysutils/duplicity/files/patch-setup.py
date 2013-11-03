--- setup.py.orig	2011-11-25 23:58:57.147597966 +0000
+++ setup.py	2011-11-26 00:00:43.169721395 +0000
@@ -31,6 +31,10 @@
 
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
