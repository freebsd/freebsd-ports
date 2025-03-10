--- setup.py.orig	2024-09-06 04:01:39 UTC
+++ setup.py
@@ -20,8 +20,8 @@ setup(
 setup(
     version=version,
     python_requires=">=3.9",
-    install_requires=["numpy >=2,<3"],
-    setup_requires=["numpy >=2,<3"],
+    install_requires=["numpy"],
+    setup_requires=["numpy"],
     ext_modules=[NLOptBuildExtension("nlopt._nlopt", version)],
     cmdclass={"build_ext": NLOptBuild},
     zip_safe=False,
