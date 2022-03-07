--- setup.py.orig	2021-11-25 15:57:49 UTC
+++ setup.py
@@ -107,6 +107,9 @@ elif platform.system() == "Darwin":
 elif platform.system() == "Windows":
     plat = "win"
     compiler = "visualstudio"
+elif platform.system() == "FreeBSD":
+    plat = "freebsd"
+    compiler = "cc"
 else:
     raise NotImplementedError(platform.system())
 
@@ -136,7 +139,6 @@ setup(
     package_dir={"": "src"},
     packages=find_packages("src"),
     entry_points={"console_scripts": ["cffsubr = cffsubr.__main__:main"]},
-    ext_modules=[tx],
     zip_safe=False,
     cmdclass=cmdclass,
     install_requires=[
@@ -146,7 +148,6 @@ setup(
     setup_requires=[
         "setuptools_scm",
         # finds all git tracked files including submodules when making sdist MANIFEST
-        "setuptools-git-ls-files",
     ],
     extras_require={"testing": ["pytest"]},
     python_requires=">=3.6",
