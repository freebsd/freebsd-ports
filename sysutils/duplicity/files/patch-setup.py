--- setup.py.orig	2007-12-07 17:28:51.000000000 +0200
+++ setup.py	2007-12-12 14:51:55.000000000 +0200
@@ -21,6 +21,10 @@
 
 incdir_list = libdir_list = None 
 
+LOCALBASE = os.environ.get("LOCALBASE", "/usr/local")
+incdir_list = ['%s/include' % LOCALBASE]
+libdir_list = ['%s/lib/' % LOCALBASE]
+
 if os.name == 'posix':
 	LIBRSYNC_DIR = os.environ.get('LIBRSYNC_DIR', '')
 	args = sys.argv[:]
@@ -47,9 +51,6 @@
 							   include_dirs=incdir_list,
 							   library_dirs=libdir_list,
 							   libraries=["rsync"])],
-	  scripts = ['rdiffdir', 'duplicity'],
-	  data_files = [('share/man/man1', ['duplicity.1', 'rdiffdir.1']),
-					('share/doc/duplicity-%s' % version_string,
-					 ['COPYING', 'README', 'CHANGELOG'])])
+	  scripts = ['rdiffdir', 'duplicity'])
 
 
