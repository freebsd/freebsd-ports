--- mupdf-1.27.2-source/scripts/wrap/state.py.orig	2026-02-18 08:24:19.000000000 -0800
+++ mupdf-1.27.2-source/scripts/wrap/state.py	2026-03-31 15:58:09.900956000 -0700
@@ -14,6 +14,9 @@
 
 try:
     import clang.cindex
+    _clang_library_file = os.environ.get('CLANG_LIBRARY_FILE')
+    if _clang_library_file:
+        clang.cindex.Config.set_library_file(_clang_library_file)
 except Exception as e:
     if '--venv' not in sys.argv:
         jlib.log('Warning: failed to import clang.cindex: {e=}\n'
@@ -70,6 +73,7 @@
         self.windows = (self.os_name == 'Windows' or self.os_name.startswith('CYGWIN'))
         self.cygwin = self.os_name.startswith('CYGWIN')
         self.openbsd = self.os_name == 'OpenBSD'
+        self.freebsd = self.os_name == 'FreeBSD'
         self.linux = self.os_name == 'Linux'
         self.macos = self.os_name == 'Darwin'
         self.pyodide = os.environ.get('OS') == 'pyodide'
