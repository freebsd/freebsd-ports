--- numpy/random/setup.py.orig	2024-02-05 21:17:48 UTC
+++ numpy/random/setup.py
@@ -3,7 +3,6 @@ from numpy.distutils.system_info import platform_bits
 from os.path import join
 
 from numpy.distutils.system_info import platform_bits
-from numpy.distutils.msvccompiler import lib_opts_if_msvc
 
 
 def configuration(parent_package='', top_path=None):
@@ -70,11 +69,7 @@ def configuration(parent_package='', top_path=None):
         not initialized the distutils build command, so use this deferred
         calculation to run when we are building the library.
         """
-        opts = lib_opts_if_msvc(build_cmd)
-        if build_cmd.compiler.compiler_type != 'msvc':
-            # Some bit generators require c99
-            opts.append('-std=c99')
-        return opts
+        return ['-std=c99']
 
     config.add_installed_library('npyrandom',
         sources=npyrandom_sources,
