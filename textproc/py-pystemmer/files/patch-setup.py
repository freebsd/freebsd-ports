--- setup.py.orig	2025-05-08 03:04:00 UTC
+++ setup.py
@@ -150,7 +150,7 @@ class BootstrapCommand(Command):
             self.libstemmer_url, self.libstemmer_sha256)
 
 
-setup(name='PyStemmer',
+setup(name='pystemmer',
       version=version_str,
       author='Richard Boulton',
       author_email='richard@tartarus.org',
