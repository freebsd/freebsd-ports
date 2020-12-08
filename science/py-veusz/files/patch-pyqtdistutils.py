Patch from https://github.com/veusz/veusz/pull/433

--- pyqtdistutils.py.orig	2020-10-11 07:18:07 UTC
+++ pyqtdistutils.py
@@ -10,9 +10,8 @@ import sys
 import sysconfig
 import subprocess
 
-from distutils.sysconfig import customize_compiler
+from distutils.sysconfig import customize_compiler, get_python_lib
 import distutils.command.build_ext
-from distutils.dep_util import newer, newer_group
 
 import PyQt5.QtCore
 
@@ -97,20 +96,6 @@ class build_ext(distutils.command.build_ext.build_ext)
         self.qt_library_dir = None
         self.qt_libinfix = None
 
-    def _get_sip_output_list(self, sbf):
-        '''
-        Parse the sbf file specified to extract the name of the generated source
-        files. Make them absolute assuming they reside in the temp directory.
-        '''
-        for line in open(sbf):
-            key, value = line.split('=', 1)
-            if key.strip() == 'sources':
-                out = []
-                for o in value.split():
-                    out.append(os.path.join(self.build_temp, o))
-                return out
-        raise RuntimeError('cannot parse SIP-generated "%s"' % sbf)
-
     def _get_sip_exe(self, build_cmd):
         """Get exe for sip. Sources are:
         --sip-exe option, environment, DEF_SIP_BIN, search on path."""
@@ -289,26 +274,35 @@ class build_ext(distutils.command.build_ext.build_ext)
         generated_sources = []
 
         for sip in sip_sources:
-            # Use the sbf file as dependency check
-            sipbasename = os.path.basename(sip)
-            sbf = os.path.join(self.build_temp,
-                               replace_suffix(sipbasename, '.sbf'))
-            if newer_group([sip]+depends, sbf) or self.force:
-                self._sip_compile(sip_exe, sip_dir, sip, sbf)
-            out = self._get_sip_output_list(sbf)
+            sip_basename = os.path.basename(sip)[:-4]
+            sip_builddir = os.path.join(self.build_temp, 'sip-' + sip_basename)
+            if not os.path.exists(sip_builddir) or self.force:
+                os.makedirs(sip_builddir, exist_ok=True)
+                self._sip_compile(sip_exe, sip_dir, sip, sip_builddir)
+            out = [
+                os.path.join(sip_builddir, fn)
+                for fn in os.listdir(sip_builddir)
+                if fn.endswith(".cpp")
+            ]
             generated_sources.extend(out)
 
         return generated_sources + other_sources
 
-    def _sip_compile(self, sip_exe, sip_dir, source, sbf):
+    def _sip_compile(self, sip_exe, sip_dir, source, sip_builddir):
         """Compile sip file to sources."""
+        if 'sip5' in sip_exe:
+            pyqt5_include_dir = os.path.join(get_python_lib(plat_specific=1),
+                                             'PyQt5', 'bindings')
+            self.spawn(['sip-module', '--target-dir', sip_builddir,
+                        '--sip-h', 'PyQt5.sip'])
+        else:
+            pyqt5_include_dir = os.path.join(sip_dir, 'PyQt5')
         self.spawn(
             [
                 sip_exe,
-                '-c', self.build_temp
+                '-c', sip_builddir
             ] + SIP_FLAGS.split() + [
-                '-I', os.path.join(sip_dir, 'PyQt5'),
-                '-b', sbf,
+                '-I', pyqt5_include_dir,
                 source
             ]
         )
