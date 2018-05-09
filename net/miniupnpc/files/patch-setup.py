--- setup.py.orig	2017-11-02 17:38:01 UTC
+++ setup.py
@@ -30,6 +30,6 @@ setup(name="miniupnpc",
       cmdclass={'build_ext': make_then_build_ext},
       ext_modules=[
          Extension(name="miniupnpc", sources=["miniupnpcmodule.c"],
-                   extra_objects=EXT)
+                   libraries=["miniupnpc"])
       ])
 
