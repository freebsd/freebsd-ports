--- fast_neural_style/download_saved_models.py.orig	2025-02-09 16:56:58 UTC
+++ fast_neural_style/download_saved_models.py
@@ -24,5 +24,7 @@ if __name__ == '__main__':
 
 
 if __name__ == '__main__':
-    _download_url_to_file('https://www.dropbox.com/s/lrvwfehqdcxoza8/saved_models.zip?dl=1', 'saved_models.zip', None, True)
-    unzip('saved_models.zip', '.')
+    temp_dir = os.path.expanduser("~/pytorch-examples-temp/fast_neural_style")
+    zip_file_path = os.path.join(temp_dir, 'saved_models.zip')
+    _download_url_to_file('https://www.dropbox.com/s/lrvwfehqdcxoza8/saved_models.zip?dl=1', zip_file_path, None, True)
+    unzip(zip_file_path, temp_dir)
