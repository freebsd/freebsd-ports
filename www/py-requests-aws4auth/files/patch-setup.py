--- setup.py.orig	2023-01-20 22:33:41 UTC
+++ setup.py
@@ -24,8 +24,6 @@ def find_version(*file_paths):
 
 with codecs.open('README.md', 'r', 'utf-8') as f:
     readme = f.read()
-with codecs.open('HISTORY.md', 'r', 'utf-8') as f:
-    history = f.read()
 
 
 version = find_version('requests_aws4auth', '__init__.py')
@@ -35,7 +33,7 @@ setup(
     name='requests-aws4auth',
     version=version,
     description='AWS4 authentication for Requests',
-    long_description=readme + '\n\n' + history,
+    long_description=readme,
     long_description_content_type='text/markdown',
     author='Ted Timmons',
     author_email='ted@tedder.dev',
