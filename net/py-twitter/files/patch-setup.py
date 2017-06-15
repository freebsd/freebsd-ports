--- setup.py.orig	2016-12-23 00:11:09 UTC
+++ setup.py
@@ -57,7 +57,6 @@ setup(
     packages=find_packages(exclude=('tests', 'docs')),
     platforms=['Any'],
     install_requires=['future', 'requests', 'requests-oauthlib'],
-    setup_requires=['pytest-runner'],
     tests_require=['pytest'],
     keywords='twitter api',
     classifiers=[
