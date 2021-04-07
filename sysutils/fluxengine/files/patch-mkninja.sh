Fix ninja generator

devel/samurai does not like the extra whitespace:

ninja: .obj/build.ninja:6:5: expected name

--- mkninja.sh.orig	2021-03-31 12:47:37 UTC
+++ mkninja.sh
@@ -7,7 +7,7 @@ rule cxx
     description = CXX \$in
     depfile = \$out.d
     deps = gcc
-    
+
 rule library
     command = $AR \$out \$in
     description = AR \$in
