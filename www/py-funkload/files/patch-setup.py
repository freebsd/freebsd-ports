--- setup.py.orig	Sat Mar  3 12:15:17 2007
+++ setup.py	Sat Mar  3 12:15:24 2007
@@ -135,8 +135,6 @@
         'Topic :: System :: Monitoring',
     ],
     # setuptools specific keywords
-    install_requires = ['webunit  == 1.3.8',
-                        'docutils >= 0.3.7'],
     zip_safe=True,
     package_data={'funkload': ['data/*',
                                'demo/simple/*', 'demo/zope/*',
