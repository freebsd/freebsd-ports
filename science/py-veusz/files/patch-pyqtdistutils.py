Obtained from AUR https://aur.archlinux.org/cgit/aur.git/plain/veusz-3.4-sip.patch?h=veusz

--- pyqtdistutils.py.orig	2021-10-17 08:26:22 UTC
+++ pyqtdistutils.py
@@ -5,18 +5,13 @@
 # Based on Pyrex.Distutils, written by Graham Fawcett and Darrel Gallion.
 
 import os
+import shutil
 import subprocess
+import toml
 
 from distutils.sysconfig import customize_compiler, get_python_lib
 import distutils.command.build_ext
 
-import toml
-
-from sipbuild.code_generator import set_globals, parse, generateCode
-from sipbuild.exceptions import UserException
-from sipbuild.module import copy_sip_h, resolve_abi_version
-from sipbuild.version import SIP_VERSION, SIP_VERSION_STR
-
 ##################################################################
 
 def replace_suffix(path, new_suffix):
@@ -30,10 +25,9 @@ def find_on_path(names, mainname):
     path = os.getenv('PATH', os.path.defpath)
     pathparts = path.split(os.path.pathsep)
     for cmd in names:
-        for dirname in pathparts:
-            cmdtry = os.path.join(dirname.strip('"'), cmd)
-            if os.path.isfile(cmdtry) and os.access(cmdtry, os.X_OK):
-                return cmdtry
+        resolved = shutil.which(cmd)
+        if resolved:
+            return resolved
     raise RuntimeError('Could not find %s executable' % mainname)
 
 def read_command_output(cmd):
@@ -206,8 +200,8 @@ class build_ext(distutils.command.build_ext.build_ext)
         # Collect the names of the source (.sip) files
         sip_sources = []
         sip_sources = [source for source in sources if source.endswith('.sip')]
-        other_sources = [source for source in sources
-                         if not source.endswith('.sip')]
+        other_sources = [
+            source for source in sources if not source.endswith('.sip')]
         generated_sources = []
 
         for sip in sip_sources:
@@ -216,64 +210,79 @@ class build_ext(distutils.command.build_ext.build_ext)
             if not os.path.exists(sip_builddir) or self.force:
                 os.makedirs(sip_builddir, exist_ok=True)
                 self._sip_compile(sip, sip_builddir)
-            out = [
-                os.path.join(sip_builddir, fn)
-                for fn in sorted(os.listdir(sip_builddir))
-                if fn.endswith(".cpp")
+
+            # files get put in sip_builddir + modulename
+            modulename = os.path.splitext(os.path.basename(sip))[0]
+            dirname = os.path.join(sip_builddir, 'output', modulename)
+
+            source_files = [
+                os.path.join(dirname, fn)
+                for fn in sorted(os.listdir(dirname))
+                if fn.endswith(".cpp") or fn.endswith(".c")
             ]
-            generated_sources.extend(out)
 
+            generated_sources.extend(source_files)
+
         return generated_sources + other_sources
 
     def _sip_compile(self, source, sip_builddir):
         """Compile sip file to sources."""
-        sip_module = 'PyQt5.sip'
-        pyqt5_include_dir = os.path.join(get_python_lib(plat_specific=1),
-                                         'PyQt5', 'bindings')
+
+        pyqt5_include_dir = os.path.join(
+            get_python_lib(plat_specific=1), 'PyQt5', 'bindings')
         pyqt5_toml = os.path.join(pyqt5_include_dir, 'QtCore', 'QtCore.toml')
         pyqt5_cfg = toml.load(pyqt5_toml)
         abi_version = pyqt5_cfg.get('sip-abi-version')
-        abi_major, abi_minor = abi_version.split('.')
 
-        # header file location changed to major version in sip-6.2.0
-        if SIP_VERSION >= 0x60200:
-            hdr_version = abi_major
-        else:
-            hdr_version = abi_version
-        copy_sip_h(hdr_version, sip_builddir, sip_module)
+        modulename = os.path.splitext(os.path.basename(source))[0]
+        srcdir = os.path.abspath(os.path.dirname(source))
 
-        sip_major_version = SIP_VERSION >> 16
-        common_args = [SIP_VERSION, SIP_VERSION_STR, int(abi_major), int(abi_minor)]
-        if sip_major_version >= 6:
-            set_globals(*common_args, sip_module, UserException, [pyqt5_include_dir])
-        else:
-            set_globals(*common_args, UserException, [pyqt5_include_dir])
+        # location of sip output files
+        output_dir = os.path.abspath(os.path.join(sip_builddir, 'output'))
+        os.makedirs(output_dir)
 
-        pt, _fq_name, _uses_limited_api, _sip_files, tags, disabled_features = parse(
-            source,
-            True,   # strict mode
-            [],     # list of additional version/platform tags
-            [],     # list of timeline backstops
-            [],     # list of disabled features
-            False,  # protected is public
-        )
+        # generate a pyproject.toml to generate the sip source
+        pyproject_data = {
+            'build-system': {
+                'requires': ['sip >=5.5.0, <7'],
+                'build-backend': 'sipbuild.api',
+            },
+            'tool': {
+                'sip': {
+                    'metadata': {
+                        'name': modulename,
+                    },
+                    'bindings': {
+                        modulename: {
+                            'pep484-pyi': False,
+                            'protected-is-public': False
+                        }
+                    },
+                    'project': {
+                        'sip-include-dirs': [pyqt5_include_dir],
+                        'abi-version': abi_version,
+                        'build-dir': output_dir,
+                        'sip-module': 'PyQt5.sip',
+                        'sip-files-dir': srcdir,
+                    }
+                }
+            }
+        }
+        pyproject_fname = os.path.join(sip_builddir, 'pyproject.toml')
+        with open(pyproject_fname, 'w') as fout:
+            toml.dump(pyproject_data, fout)
 
-        generate_args = [
-            pt,
-            sip_builddir,
-            None,   # source files suffix (default .c, .cpp)
-            False,  # whether to enable support for exceptions
-            False,  # whether to generate code with tracing enabled
-            False,  # whether to always release and reacquire the GIL
-            0,      # number of files to split the generated code into
-            tags,
-            disabled_features,
-            False,  # whether to enable the automatic generation of docstrings
-            False,  # whether to generate code for a debug build of Python
-        ]
-        if sip_major_version < 6:
-            generate_args.append(sip_module)
-        generateCode(*generate_args)
+        # generate the source files for the bindings
+        build_cmd = shutil.which('sip-build')
+        if not build_cmd:
+            raise RuntimeError('Could not find sip-build command on PATH')
+        subprocess.check_call([build_cmd, '--no-compile'], cwd=sip_builddir)
+
+        # put sip header in correct location
+        shutil.copyfile(
+            os.path.join(output_dir, 'sip.h'),
+            os.path.join(output_dir, modulename, 'sip.h')
+        )
 
     def build_extensions(self):
         # remove annoying flag which causes warning for c++ sources
