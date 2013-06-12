--- ./setup.py.orig	2013-05-25 10:38:02.218078478 +1000
+++ ./setup.py	2013-05-25 10:38:10.792279089 +1000
@@ -33,7 +33,7 @@
       license='MIT License',
       packages=find_packages(exclude=['ez_setup', 'examples', 'tests']),
       include_package_data=True,
-      zip_safe=True,
+      zip_safe=False,
       install_requires=install_requires,
       entry_points="""
       # -*- Entry points: -*-
