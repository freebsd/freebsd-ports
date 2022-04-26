--- setup.py.orig      2022-03-25 16:28:33 UTC
+++ setup.py
@@ -30,7 +30,7 @@ setup(
     author_email='macropin@gmail.com',
     url='https://github.com/macropin/django-registration',
     package_dir={'registration': 'registration'},
-    packages=find_packages(exclude='test_app'),
+    packages=find_packages(exclude=['test_app']),
     tests_require=['pytest-django'],
     cmdclass={'test': PyTest},
     include_package_data=True,
