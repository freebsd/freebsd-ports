--- src/luamm.cc.orig	2019-01-08 01:26:24 UTC
+++ src/luamm.cc
@@ -336,7 +336,7 @@ int state::gc(int what, int data) {
   pushinteger(what);
   pushinteger(data);
   call(2, 1, 0);
-  assert(isnumber(-1));
+  assert(isanumber(-1));
   int r = tointeger(-1);
   pop();
   return r;
@@ -411,7 +411,7 @@ bool state::next(int index) {
 
   call(2, MULTRET, 0);
 
-  assert(isnumber(-1));
+  assert(isanumber(-1));
   int r = tointeger(-1);
   pop();
   return r != 0;
@@ -451,7 +451,7 @@ bool state::safe_compare(lua_CFunction trampoline, int
   pushvalue(index1);
   pushvalue(index2);
   call(2, 1, 0);
-  assert(isnumber(-1));
+  assert(isanumber(-1));
   int r = tointeger(-1);
   pop();
   return r != 0;
