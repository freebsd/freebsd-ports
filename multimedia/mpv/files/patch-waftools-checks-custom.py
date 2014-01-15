--- waftools/checks/custom.py.orig
+++ waftools/checks/custom.py
@@ -52,10 +52,12 @@ def check_lua(ctx, dependency_identifier):
     lua_versions = [
         ( '51',     'lua >= 5.1.0 lua < 5.2.0'),
         ( '51deb',  'lua5.1 >= 5.1.0'), # debian
+        ( '51fbsd', 'lua-5.1 >= 5.1.0'), # FreeBSD
         ( 'luajit', 'luajit >= 2.0.0' ),
         # assume all our dependencies (libquvi in particular) link with 5.1
         ( '52',     'lua >= 5.2.0' ),
         ( '52deb',  'lua5.2 >= 5.2.0'), # debian
+        ( '52fbsd', 'lua-5.2 >= 5.2.0'), # FreeBSD
     ]
 
     if ctx.options.LUA_VER:
