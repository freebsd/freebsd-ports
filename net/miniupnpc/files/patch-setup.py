--- setup.py.orig	2018-01-06 09:33:40 UTC
+++ setup.py
@@ -23,6 +23,6 @@ setup(name="miniupnpc",
       description='miniUPnP client',
       ext_modules=[
          Extension(name="miniupnpc", sources=["miniupnpcmodule.c"],
-                   extra_objects=["libminiupnpc.a"])
+                   libraries=["miniupnpc"])
       ])
 
