--- scripts/mk_util.py.orig	2015-04-29 14:40:46 UTC
+++ scripts/mk_util.py
@@ -41,7 +41,7 @@ CXX_COMPILERS=['g++', 'clang++']
 C_COMPILERS=['gcc', 'clang']
 JAVAC=None
 JAR=None
-PYTHON_PACKAGE_DIR=distutils.sysconfig.get_python_lib()
+PYTHON_PACKAGE_DIR=distutils.sysconfig.get_python_lib(prefix=getenv("PREFIX", None))
 BUILD_DIR='build'
 REV_BUILD_DIR='..'
 SRC_DIR='src'
@@ -948,7 +948,7 @@ class LibComponent(Component):
 
     def mk_install(self, out):
         for include in self.includes2install:
-            out.write('\t@cp %s %s\n' % (os.path.join(self.to_src_dir, include), os.path.join('$(PREFIX)', 'include', include)))
+            out.write('\t@cp %s %s\n' % (os.path.join(self.to_src_dir, include), os.path.join('$(DESTDIR)/$(PREFIX)', 'include', include)))
 
     def mk_uninstall(self, out):
         for include in self.includes2install:
@@ -1034,7 +1034,7 @@ class ExeComponent(Component):
     def mk_install(self, out):
         if self.install:
             exefile = '%s$(EXE_EXT)' % self.exe_name
-            out.write('\t@cp %s %s\n' % (exefile, os.path.join('$(PREFIX)', 'bin', exefile)))
+            out.write('\t@cp %s %s\n' % (exefile, os.path.join('$(DESTDIR)/$(PREFIX)', 'bin', exefile)))
 
     def mk_uninstall(self, out):
         exefile = '%s$(EXE_EXT)' % self.exe_name
@@ -1180,11 +1180,11 @@ class DLLComponent(Component):
     def mk_install(self, out):
         if self.install:
             dllfile = '%s$(SO_EXT)' % self.dll_name
-            out.write('\t@cp %s %s\n' % (dllfile, os.path.join('$(PREFIX)', 'lib', dllfile)))
-            out.write('\t@cp %s %s\n' % (dllfile, os.path.join(PYTHON_PACKAGE_DIR, dllfile)))
+            out.write('\t@cp %s %s\n' % (dllfile, os.path.join('$(DESTDIR)/$(PREFIX)', 'lib', dllfile)))
+            out.write('\t@cp %s %s\n' % (dllfile, os.path.join('$(DESTDIR)' + PYTHON_PACKAGE_DIR, dllfile)))
             if self.static:
                 libfile = '%s$(LIB_EXT)' % self.dll_name
-                out.write('\t@cp %s %s\n' % (libfile, os.path.join('$(PREFIX)', 'lib', libfile)))
+                out.write('\t@cp %s %s\n' % (libfile, os.path.join('$(DESTDIR)/$(PREFIX)', 'lib', libfile)))
 
 
     def mk_uninstall(self, out):
@@ -1359,8 +1359,8 @@ class JavaDLLComponent(Component):
     def mk_install(self, out):
         if is_java_enabled() and self.install:
             dllfile = '%s$(SO_EXT)' % self.dll_name
-            out.write('\t@cp %s %s\n' % (dllfile, os.path.join('$(PREFIX)', 'lib', dllfile)))
-            out.write('\t@cp %s.jar %s.jar\n' % (self.package_name, os.path.join('$(PREFIX)', 'lib', self.package_name)))
+            out.write('\t@cp %s %s\n' % (dllfile, os.path.join('$(DESTDIR)/$(PREFIX)', 'lib', dllfile)))
+            out.write('\t@cp %s.jar %s.jar\n' % (self.package_name, os.path.join('$(DESTDIR)/$(PREFIX)', 'lib', self.package_name)))
 
     def mk_uninstall(self, out):
         if is_java_enabled() and self.install:
@@ -1873,6 +1873,7 @@ def mk_config():
             CPPFLAGS     = '%s -D_TRACE' % CPPFLAGS
         CXXFLAGS         = '%s -msse -msse2' % CXXFLAGS
         config.write('PREFIX=%s\n' % PREFIX)
+        config.write('DESTDIR?=\n')
         config.write('CC=%s\n' % CC)
         config.write('CXX=%s\n' % CXX)
         config.write('CXXFLAGS=%s %s\n' % (CPPFLAGS, CXXFLAGS))
@@ -1926,12 +1927,12 @@ def mk_install(out):
     out.write('\t@mkdir -p %s\n' % os.path.join('$(PREFIX)', 'lib'))
     for c in get_components():
         c.mk_install(out)
-    out.write('\t@cp z3*.py %s\n' % PYTHON_PACKAGE_DIR)
+    out.write('\t@cp z3*.py %s\n' % ('$(DESTDIR)/' + PYTHON_PACKAGE_DIR))
     if sys.version >= "3":
         out.write('\t@cp %s*.pyc %s\n' % (os.path.join('__pycache__', 'z3'),
-                                          os.path.join(PYTHON_PACKAGE_DIR, '__pycache__')))
+                                          os.path.join('$(DESTDIR)/' + PYTHON_PACKAGE_DIR, '__pycache__')))
     else:
-        out.write('\t@cp z3*.pyc %s\n' % PYTHON_PACKAGE_DIR)
+        out.write('\t@cp z3*.pyc %s\n' % ('$(DESTDIR)/' + PYTHON_PACKAGE_DIR))
     out.write('\t@echo Z3 was successfully installed.\n')
     if PYTHON_PACKAGE_DIR != distutils.sysconfig.get_python_lib():
         if os.uname()[0] == 'Darwin':
