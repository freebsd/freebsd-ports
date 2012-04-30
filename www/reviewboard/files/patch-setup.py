--- setup.py.orig	2012-04-30 13:56:46.000000000 +0800
+++ setup.py	2012-04-30 13:56:58.000000000 +0800
@@ -99,9 +99,9 @@
       },
       cmdclass=cmdclasses,
       install_requires=[
-          'Django==1.3.1',
+          'Django>=1.3.1',
           'django_evolution>=0.6.5',
-          'Djblets==0.6.16',
+          'Djblets>=0.6.16',
           'Pygments>=1.4',
           'flup',
           'paramiko>=1.7.6',
