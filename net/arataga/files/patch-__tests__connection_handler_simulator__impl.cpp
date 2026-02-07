This patch reuses the formatter from patch-git-01-* to fix "make test"

diff -up ../tests/connection_handler_simulator/impl.cpp.orig ../tests/connection_handler_simulator/impl.cpp
--- ../tests/connection_handler_simulator/impl.cpp.orig	2022-07-13 07:09:45.000000000 +0200
+++ ../tests/connection_handler_simulator/impl.cpp	2025-08-09 15:17:18.509362000 +0200
@@ -3,6 +3,8 @@
 #include <arataga/acl_handler/connection_handler_ifaces.hpp>
 #include <arataga/acl_handler/handler_factories.hpp>
 
+#include <arataga/utils/string_literal_fmt.hpp>
+
 #include <so_5_extra/disp/asio_one_thread/pub.hpp>
 
 #include <so_5_extra/sync/pub.hpp>
