--- veusz/helpers/src/threed/objects.cpp.orig	2020-01-06 22:03:24 UTC
+++ veusz/helpers/src/threed/objects.cpp
@@ -23,6 +23,8 @@
 #include "objects.h"
 #include "twod.h"
 
+#define vec_step vec_step_
+
 Object::~Object()
 {
 }
