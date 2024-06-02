--- autobahn/nvx/_utf8validator.py.orig	2024-06-02 09:20:40 UTC
+++ autobahn/nvx/_utf8validator.py
@@ -55,7 +55,7 @@ with open(os.path.join(os.path.dirname(__file__), '_ut
         "_nvx_utf8validator",
         c_source,
         libraries=[],
-        extra_compile_args=['-std=c99', '-Wall', '-Wno-strict-prototypes', '-O3', '-march=native'],
+        extra_compile_args=['-std=c99', '-Wall', '-Wno-strict-prototypes', '-O3'],
         optional=optional
     )
 
