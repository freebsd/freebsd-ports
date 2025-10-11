--- numpy/core/setup.py.orig	2024-02-05 21:17:48 UTC
+++ numpy/core/setup.py
@@ -9,7 +9,6 @@ from numpy.distutils import log
 from os.path import join
 
 from numpy.distutils import log
-from numpy.distutils.msvccompiler import lib_opts_if_msvc
 from distutils.dep_util import newer
 from sysconfig import get_config_var
 from numpy.compat import npy_load_module
@@ -688,7 +687,7 @@ def configuration(parent_package='',top_path=None):
             install_dir='lib',
             build_info={
                 'include_dirs' : [],  # empty list required for creating npy_math_internal.h
-                'extra_compiler_args': [lib_opts_if_msvc],
+                'extra_compiler_args': [],
             })
     config.add_npy_pkg_config("npymath.ini.in", "lib/npy-pkg-config",
             subst_dict)
