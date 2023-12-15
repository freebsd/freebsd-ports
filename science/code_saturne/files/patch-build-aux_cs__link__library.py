--- build-aux/cs_link_library.py.orig	2023-12-14 20:36:11 UTC
+++ build-aux/cs_link_library.py
@@ -263,8 +263,7 @@ def build_shared_library(linker,
     for o in other:
         if o in ignore_deps:
             continue
-        if o[:2] == '-R':
-            cmd += ["-Wl,-rpath", "-Wl,"+o[2:]]
+    # Not useful on FreeBSD (we have lsconfig) and causes libs to be linked against $DESTDIR
         else:
             cmd.append(o)
 
