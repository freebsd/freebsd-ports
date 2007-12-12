--- setup.py.orig	Wed Nov 28 19:09:07 2007
+++ setup.py	Thu Nov 29 20:00:05 2007
@@ -21,6 +21,10 @@
 
 incdir_list = libdir_list = None 
 
+LOCALBASE = os.environ.get("LOCALBASE", "/usr/local")
+incdir_list = ['%s/include' % LOCALBASE]
+libdir_list = ['%s/lib/' % LOCALBASE]
+
 if os.name == 'posix':
 	LIBRSYNC_DIR = os.environ.get('LIBRSYNC_DIR', '')
 	args = sys.argv[:]
@@ -49,7 +53,7 @@
 							   libraries=["rsync"])],
 	  scripts = ['rdiffdir', 'duplicity'],
 	  data_files = [('share/man/man1', ['duplicity.1', 'rdiffdir.1']),
-					('share/doc/duplicity-%s' % version_string,
+					('share/doc/duplicity',
 					 ['COPYING', 'README', 'CHANGELOG'])])
 
 
