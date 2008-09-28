--- setup.py.orig	2008-09-21 17:21:44.000000000 +0300
+++ setup.py	2008-09-28 22:24:48.000000000 +0300
@@ -21,6 +21,10 @@
 
 incdir_list = libdir_list = None 
 
+LOCALBASE = os.environ.get("LOCALBASE", "/usr/local")
+incdir_list = ['%s/include' % LOCALBASE]
+libdir_list = ['%s/lib/' % LOCALBASE]
+
 if os.name == 'posix':
     LIBRSYNC_DIR = os.environ.get('LIBRSYNC_DIR', '')
     args = sys.argv[:]
@@ -48,9 +52,6 @@
                                include_dirs=incdir_list,
                                library_dirs=libdir_list,
                                libraries=["rsync"])],
-      scripts = ['rdiffdir', 'duplicity'],
-      data_files = [('share/man/man1', ['duplicity.1', 'rdiffdir.1']),
-                    ('share/doc/duplicity-%s' % version_string,
-                     ['COPYING', 'README', 'CHANGELOG'])])
+      scripts = ['rdiffdir', 'duplicity'])
 
 
