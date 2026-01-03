--- src/lib/log/logger_level_impl.cc.orig	2025-10-17 14:58:41 UTC
+++ src/lib/log/logger_level_impl.cc
@@ -10,6 +10,7 @@
 #include <string.h>
 #include <iostream>
 #include <boost/lexical_cast.hpp>
+#include <boost/static_assert.hpp>
 
 #include <log4cplus/logger.h>
 
