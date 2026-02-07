--- setup.py.orig	2024-01-18 11:25:11 UTC
+++ setup.py
@@ -104,7 +104,6 @@ setup(
     package_dir={"": "src"},
     packages=find_packages("src"),
     entry_points={"console_scripts": ["cffsubr = cffsubr.__main__:main"]},
-    ext_modules=[tx],
     zip_safe=False,
     cmdclass=cmdclass,
     install_requires=[
