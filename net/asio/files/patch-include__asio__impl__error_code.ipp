--- include/asio/impl/error_code.ipp.orig	2011-02-22 10:25:34.000000000 +0300
+++ include/asio/impl/error_code.ipp	2014-11-27 20:24:00.000000000 +0300
@@ -16,6 +16,7 @@
 #endif // defined(_MSC_VER) && (_MSC_VER >= 1200)
 
 #include "asio/detail/config.hpp"
+#include <cstring>
 #include "asio/detail/local_free_on_block_exit.hpp"
 #include "asio/detail/socket_types.hpp"
 #include "asio/error.hpp"
