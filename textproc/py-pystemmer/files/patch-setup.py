--- setup.py.orig	2020-07-15 11:49:38 UTC
+++ setup.py
@@ -187,7 +187,7 @@ setup(name='PyStemmer',
           "Topic :: Text Processing :: Indexing",
           "Topic :: Text Processing :: Linguistic",
       ],
-      setup_requires=['Cython>=0.28.5,<1.0', 'setuptools>=18.0'],
+      setup_requires=['Cython>=0.28.5', 'setuptools>=18.0'],
       ext_modules=[
         Extension(
             'Stemmer',
