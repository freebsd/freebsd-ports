--- setup.py.orig	2022-08-17 06:38:42 UTC
+++ setup.py
@@ -30,7 +30,7 @@ install_requires = [
     "matplotlib",  # only needed for tensorboard export
     "msgpack",
     "optax",
-    "rich~=11.1",
+    "rich>=11.1",
     "typing_extensions>=4.1.1",
     "PyYAML>=5.4.1",
 ]
