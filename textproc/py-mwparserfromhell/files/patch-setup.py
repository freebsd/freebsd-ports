--- setup.py.orig	2025-03-16 19:50:17 UTC
+++ setup.py
@@ -82,7 +82,7 @@ setup(
     packages=find_packages("src"),
     package_dir={"": "src"},
     ext_modules=[tokenizer] if use_extension else [],
-    setup_requires=["pytest-runner"]
+    setup_requires=[]
     if "test" in sys.argv or "pytest" in sys.argv
     else [],
     tests_require=["pytest"],
