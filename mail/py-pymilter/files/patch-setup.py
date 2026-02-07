--- setup.py.orig	2025-05-08 14:17:14 UTC
+++ setup.py
@@ -17,7 +17,7 @@ modules = ["mime"]
 modules = ["mime"]
 
 # NOTE: importing Milter to obtain version fails when milter.so not built
-setup(name = "pymilter", version = '1.0.5',
+setup(name = "pymilter", version = '1.0.6',
 	description="Python interface to sendmail milter API",
 	long_description=long_description,
     long_description_content_type='text/markdown',
