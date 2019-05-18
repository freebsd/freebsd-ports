# Make pocket actually optional
# https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=220312

--- setup.py.orig	2018-08-30 11:36:46 UTC
+++ setup.py
@@ -15,14 +15,17 @@ version = '1.4.0'
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
 user = os.environ.get('SUDO_USER', os.environ.get('USER', None))
 
@@ -41,7 +44,7 @@ if not os.path.isfile(default):
 setup(name='rainbowstream',
       version=version,
       description="A smart and nice Twitter client on terminal.",
-      long_description=open("./README.rst", "r").read(),
+      long_description=open("./README.rst", "rb").read().decode("utf-8"),
       classifiers=[
           "Development Status :: 5 - Production/Stable",
           "Environment :: Console",
@@ -68,6 +71,7 @@ setup(name='rainbowstream',
       include_package_data=True,
       zip_safe=True,
       install_requires=install_requires,
+      extras_require=extras_require,
       entry_points="""
       # -*- Entry points: -*-
       [console_scripts]
