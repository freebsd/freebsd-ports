--- setup.py.orig	2025-08-17 20:33:32 UTC
+++ setup.py
@@ -3,7 +3,7 @@ from setuptools import find_packages, setup
 
 from setuptools import find_packages, setup
 
-install_requires = ["black", "GitPython", "tqdm", "pyyaml", "packaging", "nbformat", "huggingface_hub"]
+install_requires = ["GitPython", "tqdm", "pyyaml", "packaging", "nbformat", "huggingface_hub"]
 
 extras = {}
 
@@ -62,4 +62,4 @@ setup(
 #      twine upload dist/* -r pypi
 # 9. Add release notes to the tag in github once everything is looking hunky-dory.
 # 10. Go back to the main branch and update the version in __init__.py, setup.py to the new version ".dev" and push to
-#     main.
\ No newline at end of file
+#     main.
