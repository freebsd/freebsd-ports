--- setup.py.orig	2024-07-27 19:19:07 UTC
+++ setup.py
@@ -33,7 +33,7 @@ print("Packages:", packages)
 
 print("Packages:", packages)
 
-extras = "dev help browser playwright".split()
+extras = []
 
 setup(
     name="aider-chat",
