--- third_party/boringssl/src/util/generate_build_files.py.orig	2023-12-23 12:33:28 UTC
+++ third_party/boringssl/src/util/generate_build_files.py
@@ -772,10 +772,10 @@ def main(platforms):
   ]
 
   # Generate err_data.c
-  with open('err_data.c', 'w+') as err_data:
-    subprocess.check_call(['go', 'run', 'err_data_generate.go'],
-                          cwd=os.path.join('src', 'crypto', 'err'),
-                          stdout=err_data)
+#  with open('err_data.c', 'w+') as err_data:
+#    subprocess.check_call(['go', 'run', 'err_data_generate.go'],
+#                          cwd=os.path.join('src', 'crypto', 'err'),
+#                          stdout=err_data)
   crypto_c_files.append('err_data.c')
   crypto_c_files.sort()
 
@@ -786,11 +786,11 @@ def main(platforms):
   crypto_test_files = []
   if EMBED_TEST_DATA:
     # Generate crypto_test_data.cc
-    with open('crypto_test_data.cc', 'w+') as out:
-      subprocess.check_call(
-          ['go', 'run', 'util/embed_test_data.go'] + cmake['CRYPTO_TEST_DATA'],
-          cwd='src',
-          stdout=out)
+#    with open('crypto_test_data.cc', 'w+') as out:
+#      subprocess.check_call(
+#          ['go', 'run', 'util/embed_test_data.go'] + cmake['CRYPTO_TEST_DATA'],
+#          cwd='src',
+#          stdout=out)
     crypto_test_files.append('crypto_test_data.cc')
 
   crypto_test_files += PrefixWithSrc(cmake['CRYPTO_TEST_SOURCES'])
