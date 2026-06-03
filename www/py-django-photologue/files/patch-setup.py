Prevent installation of the "scripts" directory into the top-level of
the Python site-lib directory.

--- setup.py.orig	2026-02-11 16:50:04 UTC
+++ setup.py
@@ -17,7 +17,7 @@ setup(
     author="Justin Driscoll, Marcos Daniel Petry, Richard Barran",
     author_email="justin@driscolldev.com, marcospetry@gmail.com, richard@arbee-design.co.uk",
     url="https://github.com/richardbarran/django-photologue",
-    packages=find_packages(),
+    packages=find_packages(exclude=['scripts']),
     include_package_data=True,
     zip_safe=False,
     classifiers=['Development Status :: 5 - Production/Stable',
