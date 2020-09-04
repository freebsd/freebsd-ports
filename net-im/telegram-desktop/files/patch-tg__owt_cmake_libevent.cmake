--- tg_owt/cmake/libevent.cmake.orig	2020-08-30 09:41:57 UTC
+++ tg_owt/cmake/libevent.cmake
@@ -17,14 +17,13 @@ if (APPLE)
 else()
     target_include_directories(libevent
     PRIVATE
-        ${libevent_loc}/linux
+        ${libevent_loc}/freebsd
     )
 endif()
 
 nice_target_sources(libevent ${libevent_loc}
 PRIVATE
     buffer.c
-    epoll.c
     evbuffer.c
     evdns.c
     event.c
@@ -32,6 +31,7 @@ PRIVATE
     evrpc.c
     evutil.c
     http.c
+    kqueue.c
     log.c
     poll.c
     select.c
