--- setup.py.orig	Thu Jun 26 15:27:30 2003
+++ setup.py	Thu Jul  3 15:09:19 2003
@@ -41,6 +41,10 @@
 		if '-lrsync' in LIBS:
 			libname = []
 
+LOCALBASE = os.getenv("LOCALBASE", "/usr/local")
+include_dirs = ["%s/include" % LOCALBASE]
+library_dirs = ["%s/lib" % LOCALBASE]
+
 setup(name="rdiff-backup",
 	  version=version_string,
 	  description="Local/remote mirroring+incremental backup",
@@ -51,12 +55,9 @@
 	  ext_modules = [Extension("rdiff_backup.C", ["cmodule.c"]),
 					 Extension("rdiff_backup._librsync",
 							   ["_librsyncmodule.c"],
-							   include_dirs=incdir_list,
-							   library_dirs=libdir_list,
-							   libraries=libname,
-							   extra_link_args=lflags_arg)],
+							   libraries=["rsync"],
+                                                           include_dirs=include_dirs,
+                                                           library_dirs=library_dirs)],
 	  scripts = ['rdiff-backup'],
-	  data_files = [('share/man/man1', ['rdiff-backup.1']),
-					('share/doc/rdiff-backup-%s' % (version_string,),
-					 ['CHANGELOG', 'COPYING', 'README', 'FAQ.html'])])
+)
 
