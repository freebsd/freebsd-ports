--- super_resolution/data.py.orig	2025-02-09 16:56:58 UTC
+++ super_resolution/data.py
@@ -1,4 +1,4 @@
-from os.path import exists, join, basename
+from os.path import exists, join, basename, expanduser
 from os import makedirs, remove
 from six.moves import urllib
 import tarfile
@@ -51,7 +51,7 @@ def get_training_set(upscale_factor):
 
 
 def get_training_set(upscale_factor):
-    root_dir = download_bsd300()
+    root_dir = download_bsd300(join(expanduser("~/pytorch-examples-temp"), "dataset"))
     train_dir = join(root_dir, "train")
     crop_size = calculate_valid_crop_size(256, upscale_factor)
 
@@ -61,7 +61,7 @@ def get_test_set(upscale_factor):
 
 
 def get_test_set(upscale_factor):
-    root_dir = download_bsd300()
+    root_dir = download_bsd300(join(expanduser("~/pytorch-examples-temp"), "dataset"))
     test_dir = join(root_dir, "test")
     crop_size = calculate_valid_crop_size(256, upscale_factor)
 
