--- setup.py.orig	2017-02-17 17:38:50 UTC
+++ setup.py
@@ -27,7 +27,6 @@ setup(
     author_email='miyako.dev@gmail.com',
     url='https://github.com/miyakogi/m2r',
     py_modules=['m2r'],
-    packages=['tests'],
     entry_points={'console_scripts': 'm2r = m2r:main'},
     include_package_data=True,
     license="MIT",
