--- src/ParsedFlow.cpp.orig	2020-03-26 13:52:23 UTC
+++ src/ParsedFlow.cpp
@@ -127,17 +127,17 @@ void ParsedFlow::fromLua(lua_State *L, int index) {
 	if(!strcmp(key, "vlan_id"))
 	  vlan_id = lua_tonumber(L, -1);
 	else if(!strcmp(key, "version"))
-	  version = htons(lua_tonumber(L, -1));
+	  version = htons(lua_tointeger(L, -1));
 	else if(!strcmp(key, "src_port"))
-	  src_port = htons(lua_tonumber(L, -1));
+	  src_port = htons(lua_tointeger(L, -1));
 	else if(!strcmp(key, "dst_port"))
-	  dst_port = htons(lua_tonumber(L, -1));
+	  dst_port = htons(lua_tointeger(L, -1));
 	else if(!strcmp(key, "l4_proto"))
 	  l4_proto = lua_tonumber(L, -1);
 	else if(!strcmp(key, "tcp_flags"))
-	  tcp.tcp_flags = htons(lua_tonumber(L, -1));
+	  tcp.tcp_flags = htons(lua_tointeger(L, -1));
 	else if(!strcmp(key, "direction"))
-	  direction = htons(lua_tonumber(L, -1));
+	  direction = htons(lua_tointeger(L, -1));
 	else if(!strcmp(key, "first_switched"))
 	  first_switched = lua_tonumber(L, -1);
 	else if(!strcmp(key, "last_switched"))
