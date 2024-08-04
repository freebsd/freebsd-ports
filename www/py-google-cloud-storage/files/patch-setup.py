--- setup.py.orig	2024-06-10 22:46:41 UTC
+++ setup.py
@@ -35,7 +35,7 @@ dependencies = [
     "requests >= 2.18.0, < 3.0.0dev",
     "google-crc32c >= 1.0, < 2.0dev",
 ]
-extras = {"protobuf": ["protobuf<5.0.0dev"]}
+extras = {"protobuf": ["protobuf<6.0.0dev"]}
 
 
 # Setup boilerplate below this line.
