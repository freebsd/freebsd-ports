--- src/libs/services/auth/include/services/auth/IPasswordService.hpp
+++ src/libs/services/auth/include/services/auth/IPasswordService.hpp
@@ -20,6 +20,7 @@
 #pragma once
 
 #include <string_view>
+#include <optional>
 
 #include <boost/asio/ip/address.hpp>
 #include <Wt/WDateTime.h>
