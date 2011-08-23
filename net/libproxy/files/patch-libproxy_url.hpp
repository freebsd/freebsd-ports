--- libproxy/url.hpp.orig	2010-09-01 14:30:33.000000000 +0200
+++ libproxy/url.hpp	2010-09-01 14:31:13.000000000 +0200
@@ -20,6 +20,8 @@
 #ifndef URL_HPP_
 #define URL_HPP_
 
+#include <sys/types.h>
+
 #include <map>
 #include <stdexcept>
 #include <string>
