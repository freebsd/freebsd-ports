--- src/Text/Pandoc/Writers/Custom.hs.orig	2017-01-25 16:07:43 UTC
+++ src/Text/Pandoc/Writers/Custom.hs
@@ -183,7 +183,11 @@ writeCustom luaFile opts doc@(Pandoc meta _) = do
   setForeignEncoding utf8
   lua <- Lua.newstate
   Lua.openlibs lua
+#if MIN_VERSION_hslua(0,5,0)
+  status <- Lua.loadstring lua luaScript
+#else
   status <- Lua.loadstring lua luaScript luaFile
+#endif
   -- check for error in lua script (later we'll change the return type
   -- to handle this more gracefully):
   when (status /= 0) $
