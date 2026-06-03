--- src/deps/src/luajit-geoip/geoip/mmdb.lua.orig	2026-05-25 18:23:18 UTC
+++ src/deps/src/luajit-geoip/geoip/mmdb.lua
@@ -166,7 +166,7 @@ ffi.cdef([[  const char *gai_strerror(int ecode);
                             MMDB_entry_data_s *const entry_data,
                             ...);
 ]])
-local lib = ffi.load("/usr/share/bunkerweb/deps/lib/libmaxminddb.so")
+local lib = ffi.load("/usr/local/lib/libmaxminddb.so")
 local consume_map, consume_array
 local consume_value
 consume_value = function(current)
