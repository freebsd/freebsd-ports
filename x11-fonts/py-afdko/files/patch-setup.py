--- setup.py.orig	2022-02-24 19:28:27 UTC
+++ setup.py
@@ -8,31 +8,10 @@ from distutils.dep_util import newer
 from distutils.util import convert_path
 from distutils.util import get_platform
 
+from setuptools import setup
 import setuptools.command.install
 
-from skbuild import setup
 
-try:
-    from wheel.bdist_wheel import bdist_wheel
-
-    class CustomBDistWheel(bdist_wheel):
-        """Mark the wheel as python 3, yet platform-specific,
-        since it contains native C executables.
-        """
-
-        def finalize_options(self):
-            bdist_wheel.finalize_options(self)
-            self.root_is_pure = False
-
-        def get_tag(self):
-            return ('py3', 'none',) + bdist_wheel.get_tag(self)[2:]
-
-except ImportError:
-    print("afdko: setup.py requires that the Python package 'wheel' be "
-          "installed. Try the command 'pip install wheel'.")
-    sys.exit(1)
-
-
 class InstallPlatlib(setuptools.command.install.install):
     """This is to force installing all the modules to the non-pure, platform-
     specific lib directory, even though we haven't defined any 'ext_modules'.
@@ -194,24 +173,17 @@ def main():
           zip_safe=False,
           python_requires='>=3.7',
           setup_requires=[
-              'wheel',
               'setuptools_scm',
-              'scikit-build',
-              'cmake',
-              'ninja'
           ],
           tests_require=[
               'pytest',
           ],
           install_requires=_get_requirements(),
-          scripts=_get_scripts(),
           entry_points={
               'console_scripts': _get_console_scripts(),
           },
           cmdclass={
               'build_scripts': CustomBuildScripts,
-              'bdist_wheel': CustomBDistWheel,
-              'install': InstallPlatlib,
           },
           )
 
