--- src/luamm.hh.orig	2018-12-02 18:26:02 UTC
+++ src/luamm.hh
@@ -204,7 +204,7 @@ class state : private std::mutex {
   }
   bool isnil(int index) throw() { return lua_isnil(cobj.get(), index); }
   bool isnone(int index) throw() { return lua_isnone(cobj.get(), index); }
-  bool isnumber(int index) throw() { return lua_isnumber(cobj.get(), index); }
+  bool isanumber(int index) throw() { return lua_isnumber(cobj.get(), index); }
   bool isstring(int index) throw() { return lua_isstring(cobj.get(), index); }
   void pop(int n = 1) throw() { lua_pop(cobj.get(), n); }
   void pushboolean(bool b) throw() { lua_pushboolean(cobj.get(), b); }
