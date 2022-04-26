--- setup.py.orig      2022-03-25 15:45:28 UTC
+++ setup.py
@@ -41,7 +41,7 @@ if sys.argv[-1] == 'publish':
 setup(
     name='django-star-ratings',
     version=version,
-    packages=find_packages(),
+    packages=find_packages(exclude=['tests*']),
     include_package_data=True,
     package_data={
         'star_ratings/static': ['*'],
