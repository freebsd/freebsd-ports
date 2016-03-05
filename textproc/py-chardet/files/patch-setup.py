--- setup.py.orig	2014-10-07 15:03:14 UTC
+++ setup.py
@@ -36,4 +36,7 @@ setup(name='chardet',
                     "Modules"),
                    "Topic :: Text Processing :: Linguistic"],
       packages=['chardet'],
-      entry_points={'console_scripts': ['chardetect = chardet.chardetect:main']})
+      entry_points={'console_scripts': ['chardetect = chardet.chardetect:main']},
+      tests_require=['nose'],
+      test_suite='nose.collector',
+)
