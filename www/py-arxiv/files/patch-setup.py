--- setup.py.orig	2023-10-17 08:50:39 UTC
+++ setup.py
@@ -11,7 +11,7 @@ setup(
     packages=["arxiv"],
     # dependencies
     python_requires=">=3.7",
-    install_requires=["feedparser==6.0.10", "requests==2.31.0"],
+    install_requires=["feedparser>=6.0.10", "requests>=2.31.0"],
     tests_require=["pytest", "pdoc", "ruff"],
     # metadata for upload to PyPI
     author="Lukas Schwab",
