--- setup.py.orig	2009-03-16 14:45:54 UTC
+++ setup.py
@@ -58,6 +58,10 @@ if os.name == 'nt':
 				'zipfile': None
 			})
 
+LOCALBASE = os.getenv("LOCALBASE", "/usr/local")
+include_dirs = ["%s/include" % LOCALBASE]
+library_dirs = ["%s/lib" % LOCALBASE]
+
 setup(name="rdiff-backup",
 	  version=version_string,
 	  description="Local/remote mirroring+incremental backup",
@@ -68,14 +72,8 @@ setup(name="rdiff-backup",
 	  ext_modules = [Extension("rdiff_backup.C", ["cmodule.c"]),
 					 Extension("rdiff_backup._librsync",
 							   ["_librsyncmodule.c"],
-							   include_dirs=incdir_list,
-							   library_dirs=libdir_list,
+							   include_dirs=include_dirs,
+							   library_dirs=library_dirs,
 							   libraries=libname,
 							   extra_link_args=lflags_arg)],
-	  scripts = ['rdiff-backup', 'rdiff-backup-statistics'],
-	  data_files = [('share/man/man1', ['rdiff-backup.1',
-										'rdiff-backup-statistics.1']),
-					('share/doc/rdiff-backup-%s' % (version_string,),
-					 ['CHANGELOG', 'COPYING', 'README', 'FAQ.html'])],
-					**extra_options)
-
+	  scripts = ['rdiff-backup', 'rdiff-backup-statistics'])
