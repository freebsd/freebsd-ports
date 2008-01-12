--- portable/libtorrent/bindings/python/src/peer_plugin.cpp.orig	2008-01-10 20:55:51.000000000 +0100
+++ portable/libtorrent/bindings/python/src/peer_plugin.cpp	2008-01-11 21:47:50.000000000 +0100
@@ -2,6 +2,9 @@
 // subject to the Boost Software License, Version 1.0. (See accompanying
 // file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 
+#include <cctype>
+#include <iostream>
+
 #include <libtorrent/extensions.hpp>
 #include <libtorrent/entry.hpp>
 #include <libtorrent/peer_request.hpp>
