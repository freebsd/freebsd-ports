--- setup.py.orig	2019-05-17 11:59:54 UTC
+++ setup.py
@@ -77,7 +77,7 @@ setup(
         'Programming Language :: Python :: Implementation :: CPython',
     ],
     install_requires=[
-        'h2>=2.4,<3.0,!=2.5.0', 'hyperframe>=3.2,<4.0', 'rfc3986>=1.1.0,<2.0', 'brotlipy>=0.7.0,<1.0'
+        'h2>=2.4,!=2.5.0', 'hyperframe>=3.2', 'rfc3986>=1.1.0,<2.0', 'brotlipy>=0.7.0,<1.0'
     ],
     tests_require=['pytest', 'requests', 'mock'],
     cmdclass={'test': PyTest},
