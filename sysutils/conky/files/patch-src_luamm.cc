--- src/luamm.cc.orig	2018-12-02 18:26:02 UTC
+++ src/luamm.cc
@@ -56,7 +56,7 @@ int exception_to_string(lua_State *l) {
   } catch (std::exception &e) {
     lua_pushstring(l, e.what());
   } catch (...) {
-#if defined(__APPLE__) && defined(__MACH__)
+#if (defined(__APPLE__) && defined(__MACH__)) || defined(__FreeBSD__)
     // lua_pushstring(l, ptr->__cxa_exception_type()->name());
     printf(
         "%s: FIXME: no member named '__cxa_exception_type' in "
@@ -345,7 +345,7 @@ int state::gc(int what, int data) {
   pushinteger(what);
   pushinteger(data);
   call(2, 1, 0);
-  assert(isnumber(-1));
+  assert(isanumber(-1));
   int r = tointeger(-1);
   pop();
   return r;
@@ -420,7 +420,7 @@ bool state::next(int index) {
 
   call(2, MULTRET, 0);
 
-  assert(isnumber(-1));
+  assert(isanumber(-1));
   int r = tointeger(-1);
   pop();
   return r != 0;
@@ -460,7 +460,7 @@ bool state::safe_compare(lua_CFunction trampoline, int
   pushvalue(index1);
   pushvalue(index2);
   call(2, 1, 0);
-  assert(isnumber(-1));
+  assert(isanumber(-1));
   int r = tointeger(-1);
   pop();
   return r != 0;
