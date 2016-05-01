# Unbundle sleuthkit and talloc

--- setup.py.orig	2016-03-25 08:41:14 UTC
+++ setup.py
@@ -169,9 +169,9 @@ class BuildExtCommand(build_ext):
 
     def run(self):
         compiler = new_compiler(compiler=self.compiler)
-        self.define = self.configure_source_tree(compiler)
+        self.define = [("HAVE_TSK_LIBTSK_H", "")]
 
-        libtsk_path = "sleuthkit/tsk"
+        libtsk_path = "%%LOCALBASE%%/include/tsk"
 
         if not os.access("pytsk3.c", os.R_OK):
             # Generate the Python binding code (pytsk3.c).
@@ -322,7 +322,7 @@ class ProjectBuilder(object):
         self._argv = argv
 
         # The path to the "tsk" directory.
-        self._libtsk_path = "sleuthkit/tsk"
+        self._libtsk_path = "%%LOCALBASE%%/include/tsk"
 
         # paths under the tsk/ directory which contain files we need to compile.
         self._sub_library_names = "auto  base  docs  fs  hashdb  img vs".split()
@@ -330,14 +330,14 @@ class ProjectBuilder(object):
         # The args for the extension builder.
         self.extension_args = dict(
             define_macros=[],
-            include_dirs=["talloc", "sleuthkit/tsk", "sleuthkit", "."],
-            library_dirs=[],
-            libraries=[],
+            include_dirs=[".", "%%LOCALBASE%%/include"],
+            library_dirs=["%%LOCALBASE%%/lib"],
+            libraries=["tsk", "talloc"],
         )
 
         # The sources to build.
         self._source_files = ["class.c", "error.c", "tsk3.c",
-                              "pytsk3.c", "talloc/talloc.c"]
+                              "pytsk3.c"]
 
         # Path to the top of the unpacked sleuthkit sources.
         self._sleuthkit_path = "sleuthkit"
