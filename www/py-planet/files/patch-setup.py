--- setup.py.orig	2021-11-30 19:53:02 UTC
+++ setup.py
@@ -72,7 +72,6 @@ setup(name='planet',
       url='https://github.com/planetlabs/planet-client-python',
       license='Apache 2.0',
       packages=find_packages(exclude=['examples', 'tests']),
-      data_files=[('', ['LICENSE'])],
       include_package_data=True,
       zip_safe=False,
       install_requires=[
