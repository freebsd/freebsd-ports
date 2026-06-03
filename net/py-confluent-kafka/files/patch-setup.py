--- setup.py.orig	2022-01-13 08:07:07 UTC
+++ setup.py
@@ -87,7 +87,6 @@ setup(name='confluent-kafka',
       ext_modules=[module],
       packages=find_packages('src'),
       package_dir={'': 'src'},
-      data_files=[('', [os.path.join(work_dir, 'LICENSE.txt')])],
       install_requires=INSTALL_REQUIRES,
       classifiers=trove_classifiers,
       extras_require={
