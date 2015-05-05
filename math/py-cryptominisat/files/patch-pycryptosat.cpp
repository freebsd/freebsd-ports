On FreeBSD -std=c++11 turns NULL into nullptr which sometimes breaks:

  pycryptosat.cpp:393:12: error: cannot initialize return object of type 'int' with an rvalue of type 'nullptr_t'
      return NULL;
             ^~~~
  /usr/include/sys/_null.h:35:14: note: expanded from macro 'NULL'
  #define NULL    nullptr
                  ^~~~~~~
--- pycryptosat.cpp.orig	2014-07-06 23:41:16 UTC
+++ pycryptosat.cpp
@@ -390,7 +390,7 @@ Solver_init(Solver *self, PyObject *args
     if (!self->cmsat) {
         return -1;
     }
-    return NULL;
+    return 0;
 }
 
 static PyMemberDef Solver_members[] = {
