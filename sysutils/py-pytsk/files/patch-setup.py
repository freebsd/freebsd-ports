# Unbundle sleuthkit and talloc

--- setup.py.orig	2017-11-06 20:59:12 UTC
+++ setup.py
@@ -178,9 +178,9 @@ class BuildExtCommand(build_ext):
   def run(self):
     compiler = new_compiler(compiler=self.compiler)
     # pylint: disable=attribute-defined-outside-init
-    self.define = self.configure_source_tree(compiler)
+    self.define = [("HAVE_TSK_LIBTSK_H", "")]
 
-    libtsk_path = os.path.join("sleuthkit", "tsk")
+    libtsk_path = os.path.join("%%LOCALBASE%%", "include", "tsk")
 
     if not os.access("pytsk3.c", os.R_OK):
       # Generate the Python binding code (pytsk3.c).
@@ -330,7 +330,7 @@ class ProjectBuilder(object):
     self._argv = argv
 
     # The path to the sleuthkit/tsk directory.
-    self._libtsk_path = os.path.join("sleuthkit", "tsk")
+    self._libtsk_path = os.path.join("%%LOCALBASE%%", "include", "tsk")
 
     # Paths under the sleuthkit/tsk directory which contain files we need
     # to compile.
@@ -340,13 +340,13 @@ class ProjectBuilder(object):
     # The args for the extension builder.
     self.extension_args = {
         "define_macros": [],
-        "include_dirs": ["talloc", self._libtsk_path, "sleuthkit", "."],
-        "library_dirs": [],
-        "libraries": []}
+        "include_dirs": [".", os.path.join("%%LOCALBASE%%", "include")],
+        "library_dirs": [os.path.join("%%LOCALBASE%%","lib")],
+        "libraries": ["tsk", "talloc"]}
 
     # The sources to build.
     self._source_files = [
-        "class.c", "error.c", "tsk3.c", "pytsk3.c", "talloc/talloc.c"]
+        "class.c", "error.c", "tsk3.c", "pytsk3.c"]
 
     # Path to the top of the unpacked sleuthkit sources.
     self._sleuthkit_path = "sleuthkit"
