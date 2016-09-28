--- src/luamm.hh.orig	2016-07-20 16:53:48 UTC
+++ src/luamm.hh
@@ -25,7 +25,9 @@
 #include <assert.h>
 #include <memory>
 #include <mutex>
+#include <exception>
 #include <stdexcept>
+#include <string>
 
 #include <lua.hpp>
 
@@ -210,7 +212,7 @@ namespace lua {
 		bool islightuserdata(int index) throw() { return lua_islightuserdata(cobj.get(), index); }
 		bool isnil(int index) throw() { return lua_isnil(cobj.get(), index); }
 		bool isnone(int index) throw() { return lua_isnone(cobj.get(), index); }
-		bool isnumber(int index) throw() { return lua_isnumber(cobj.get(), index); }
+		bool isanumber(int index) throw() { return lua_isnumber(cobj.get(), index); }
 		bool isstring(int index) throw() { return lua_isstring(cobj.get(), index); }
 		void pop(int n = 1) throw() { lua_pop(cobj.get(), n); }
 		void pushboolean(bool b) throw() { lua_pushboolean(cobj.get(), b); }
