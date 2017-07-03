# Make pocket actually optional
# https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=220312

--- setup.py.orig	2016-08-16 14:49:45 UTC
+++ setup.py
@@ -15,14 +15,17 @@ version = '1.3.5'
 install_requires = [
     "python-dateutil",
     "arrow",
-    "requests==2.5.3",
+    "requests>=2.5.3",
     "pyfiglet",
     "twitter",
     "Pillow",
     "PySocks",
-    "pocket"
 ]
 
+extras_require = {
+    'pocket': ["pocket"],
+}
+
 # Default user (considers non virtualenv method)
 user = os.environ.get('SUDO_USER', os.environ['USER'])
 
@@ -65,6 +68,7 @@ setup(name='rainbowstream',
       include_package_data=True,
       zip_safe=True,
       install_requires=install_requires,
+      extras_require=extras_require,
       entry_points="""
       # -*- Entry points: -*-
       [console_scripts]
