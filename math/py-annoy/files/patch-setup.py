--- setup.py.orig	2023-01-12 05:20:26 UTC
+++ setup.py
@@ -104,6 +104,6 @@ setup(name='annoy',
           'Programming Language :: Python :: 3.9',
       ],
       keywords='nns, approximate nearest neighbor search',
-      setup_requires=['nose>=1.0'],
+      setup_requires=[],
       tests_require=['numpy', 'h5py']
       )
