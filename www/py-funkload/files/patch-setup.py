--- setup.py.orig	2010-01-30 02:16:39.051847143 +0800
+++ setup.py	2010-01-30 02:16:50.065356904 +0800
@@ -149,9 +149,6 @@
         'Topic :: System :: Monitoring',
     ],
     # setuptools specific keywords
-    install_requires = ['webunit  >= 1.3.8',
-                        'docutils >= 0.3.7',
-                        'setuptools'],
     zip_safe=True,
     package_data={'funkload': ['data/*',
                                'demo/simple/*', 'demo/zope/*',
