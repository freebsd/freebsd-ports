--- setup.py.orig	2019-04-10 15:00:42 UTC
+++ setup.py
@@ -11,17 +11,6 @@ from io import open
 
 
 cmdclass = {}
-try:
-    from wheel.bdist_wheel import bdist_wheel
-except ImportError:
-    print("warning: wheel package is not installed", file=sys.stderr)
-else:
-    class UniversalBdistWheel(bdist_wheel):
-
-        def get_tag(self):
-            return ('py2.py3', 'none',) + bdist_wheel.get_tag(self)[2:]
-
-    cmdclass['bdist_wheel'] = UniversalBdistWheel
 
 
 class SharedLibrary(Extension):
@@ -74,7 +63,6 @@ class SharedLibBuildExt(build_ext):
                   verbose=self.verbose, dry_run=self.dry_run)
 
 
-cmdclass['build_ext'] = SharedLibBuildExt
 
 env = dict(os.environ)
 if sys.platform == "win32":
@@ -109,7 +97,7 @@ with open("README.rst", "r", encoding="u
 
 setup(
     name="ttfautohint-py",
-    use_scm_version=True,
+    use_scm_version={"fallback_version": "%%PORTVERSION%%"},
     description=("Python wrapper for ttfautohint, "
                  "a free auto-hinter for TrueType fonts"),
     long_description=long_description,
@@ -120,7 +108,6 @@ setup(
     platforms=["posix", "nt"],
     package_dir={"": "src/python"},
     packages=find_packages("src/python"),
-    ext_modules=[libttfautohint],
     zip_safe=False,
     cmdclass=cmdclass,
     setup_requires=['setuptools_scm'],
