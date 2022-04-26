--- setup.py.orig	2022-01-14 21:55:54 UTC
+++ setup.py
@@ -18,7 +18,7 @@ setup(
     license="BSD",
     keywords="cryptography API NaCl libsodium",
     url="https://github.com/stef/pysodium",
-    packages=find_packages(),
+    packages=find_packages(exclude=['test*']),
     long_description=read('README.md'),
     requires=["libsodium"],
     classifiers=["Development Status :: 4 - Beta",
