--- setup.py.orig	2020-12-18 20:51:29 UTC
+++ setup.py
@@ -40,7 +40,6 @@ setup(
     ],
     keywords="markdown lexer parser development",
     python_requires="~=3.6",
-    install_requires=["markdown-it-py>=0.5.8,<2.0.0"],
     extras_require={
         "code_style": ["pre-commit==2.6"],
         "testing": [
