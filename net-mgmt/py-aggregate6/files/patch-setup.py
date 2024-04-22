--- setup.py.orig	2017-12-01 09:46:38 UTC
+++ setup.py
@@ -70,13 +70,12 @@ setup(
         'Programming Language :: Python :: 3',
         'Programming Language :: Python :: 3.6'
     ],
-    setup_requires=["nose", "coverage", "mock"],
-    install_requires=["py-radix==0.10.0"] + (
+    install_requires=["py-radix>=0.10.0"] + (
         ["future", "ipaddress"] if sys.version_info.major == 2 else []
     ),
     packages=find_packages(exclude=['tests', 'tests.*']),
     entry_points={'console_scripts':
                   ['aggregate6 = aggregate6.aggregate6:main']},
-    data_files = [('man/man7', ['aggregate6.7'])],
+    data_files = [('share/man/man7', ['aggregate6.7'])],
     test_suite='nose.collector'
 )
