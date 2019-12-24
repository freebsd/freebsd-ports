--- setup.py.orig	2019-12-24 07:50:35 UTC
+++ setup.py
@@ -53,7 +53,7 @@ setup(
               'flask_mongoengine.wtf'],
     include_package_data=True,
     tests_require=test_requirements,
-    setup_requires=test_requirements,  # Allow proper nose usage with setuptools and tox
+    # setup_requires=test_requirements,  # Allow proper nose usage with setuptools and tox
     description=description,
     long_description=long_description,
     classifiers=[
