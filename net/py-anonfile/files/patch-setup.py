--- setup.py.orig	2023-06-16 04:37:29 UTC
+++ setup.py
@@ -9,14 +9,6 @@ with open("src/anonfile/anonfile.py", encoding='utf-8'
     python_major = int(re.search(r'python_major = "(.*?)"', lines).group(1))
     python_minor = int(re.search(r'python_minor = "(.*?)"', lines).group(1))
 
-print("reading dependency file")
-
-with open("requirements/release.txt", mode='r', encoding='utf-8') as requirements:
-    packages = requirements.read().splitlines()
-
-with open("requirements/dev.txt", mode='r', encoding='utf-8') as requirements:
-    dev_packages = requirements.read().splitlines()
-
 print("reading readme file")
 
 with open("README.md", "r") as fh:
@@ -37,9 +29,13 @@ setup(
         'Changelog': "https://github.com/nstrydom2/anonfile-api/blob/master/CHANGELOG.md"
     },    
     python_requires=">=%d.%d" % (python_major, python_minor),
-    install_requires=packages,
+    install_requires=[
+        "requests",
+        "requests-toolbelt",
+        "tqdm",
+        "importlib-metadata"
+    ],
     extra_requires={
-        'dev': dev_packages[1:],
         'test': ['pytest']
     },
     package_dir={'': 'src'},
