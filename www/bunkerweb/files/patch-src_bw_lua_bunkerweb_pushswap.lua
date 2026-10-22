--- src/bw/lua/bunkerweb/pushswap.lua.orig	2026-10-21 13:42:35 UTC
+++ src/bw/lua/bunkerweb/pushswap.lua
@@ -26,7 +26,7 @@ pushswap.INSTALL_SENTINEL = pushswap.RESERVED_PREFIX .
 -- that carries it. It has the reserved prefix, so the sweep skips it and it is never placed from
 -- an archive. Keep the name in step with sync_tree.INSTALL_SENTINEL.
 pushswap.INSTALL_SENTINEL = pushswap.RESERVED_PREFIX .. "install-incomplete"
-pushswap.SENTINEL_DESTINATION = "/etc/nginx"
+pushswap.SENTINEL_DESTINATION = "/usr/local/etc/nginx"
 
 -- The applied digest describes a destination, it is never part of one. On Linux and
 -- all-in-one the archived source directory and the receiver destination are the same
