--- src/luamm.cc.orig	2016-10-04 07:49:19 UTC
+++ src/luamm.cc
@@ -57,7 +57,8 @@ namespace lua {
 				lua_pushstring(l, e.what());
 			}
 			catch(...) {
-				lua_pushstring(l, ptr->__cxa_exception_type()->name());
+//				lua_pushstring(l, ptr->__cxa_exception_type()->name());
+				lua_pushstring(l, "Unknown exception");
 			}
 			return 1;
 		}
@@ -344,7 +345,7 @@ namespace lua {
 		pushinteger(what);
 		pushinteger(data);
 		call(2, 1, 0);
-		assert(isnumber(-1));
+		assert(isanumber(-1));
 		int r = tointeger(-1);
 		pop();
 		return r;
@@ -427,7 +428,7 @@ namespace lua {
 
 		call(2, MULTRET, 0);
 
-		assert(isnumber(-1));
+		assert(isanumber(-1));
 		int r = tointeger(-1);
 		pop();
 		return r;
@@ -466,7 +467,7 @@ namespace lua {
 		pushvalue(index1);
 		pushvalue(index2);
 		call(2, 1, 0);
-		assert(isnumber(-1));
+		assert(isanumber(-1));
 		int r = tointeger(-1);
 		pop();
 		return r;
