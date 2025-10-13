--- setup.py.orig	2025-05-06 15:48:45 UTC
+++ setup.py
@@ -92,7 +92,7 @@ Clustering Routines for R and Python*, Journal of Stat
       long_description_content_type='text/markdown',
       python_requires='>=3',
       requires=['numpy'],
-      install_requires=["numpy>=2"],
+      install_requires=["numpy"],
       provides=['fastcluster'],
       ext_modules=[Extension('_fastcluster',
                              ['src/fastcluster_python.cpp'],
