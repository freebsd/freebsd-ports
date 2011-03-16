--- setup.py.orig	2009-01-09 16:05:11.000000000 +0200
+++ setup.py	2009-01-10 16:06:40.000000000 +0200
@@ -12,6 +12,10 @@
 
 incdir_list = libdir_list = None
 
+LOCALBASE = os.environ.get("LOCALBASE", "/usr/local")
+incdir_list = ['%s/include' % LOCALBASE]
+libdir_list = ['%s/lib/' % LOCALBASE]
+
 if os.name == 'posix':
     LIBRSYNC_DIR = os.environ.get('LIBRSYNC_DIR', '')
     args = sys.argv[:]
@@ -23,16 +27,9 @@
         incdir_list = [os.path.join(LIBRSYNC_DIR, 'include')]
         libdir_list = [os.path.join(LIBRSYNC_DIR, 'lib')]
 
-data_files = [('share/man/man1',
+data_files = [('man/man1',
                ['duplicity.1',
                 'rdiffdir.1']),
-              ('share/doc/duplicity-%s' % version_string,
-               ['COPYING',
-                'REPO-README',
-                'LOG-README',
-                'README',
-                'tarfile-LICENSE',
-                'CHANGELOG']),
               ]
 
 assert os.path.exists("po"), "Missing 'po' directory."
