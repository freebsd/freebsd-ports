- same patch as suggested here: https://github.com/onnx/onnx-tensorflow/issues/1016

--- setup.py.orig	2022-03-25 17:32:07 UTC
+++ setup.py
@@ -30,7 +30,7 @@ setuptools.setup(
     author='Arpith Jacob, Tian Jin, Gheorghe-Teodor Bercea, Wenhao Hu',
     author_email='tian.jin1@ibm.com',
     license='Apache License 2.0',
-    packages=setuptools.find_packages(),
+    packages=setuptools.find_packages(exclude=['test*']),
     zip_safe=False, 
     classifiers=[
          "Programming Language :: Python :: 2",
