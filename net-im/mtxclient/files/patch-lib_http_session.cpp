https://github.com/Nheko-Reborn/mtxclient/issues/11

--- lib/http/session.cpp.orig	2018-09-21 18:29:59 UTC
+++ lib/http/session.cpp
@@ -1,4 +1,5 @@
 #include "mtxclient/http/session.hpp"
+#include <iostream> // for std::cout
 
 using namespace mtx::http;
 
