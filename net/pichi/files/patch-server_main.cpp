--- server/main.cpp.orig	1970-01-01 00:00:00 UTC
+++ server/main.cpp
@@ -1,10 +1,11 @@
+#include <pichi/config.hpp>
+// Include config.hpp first
 #include <boost/filesystem/operations.hpp>
 #include <boost/filesystem/path.hpp>
 #include <boost/program_options.hpp>
 #include <fstream>
 #include <iostream>
 #include <memory>
-#include <pichi/config.hpp>
 #include <stdio.h>
 #ifdef HAS_UNISTD_H
 #include <errno.h>
