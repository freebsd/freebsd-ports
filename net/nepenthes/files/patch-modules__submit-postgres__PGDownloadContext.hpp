--- modules/submit-postgres/PGDownloadContext.hpp.orig
+++ modules/submit-postgres/PGDownloadContext.hpp
@@ -30,6 +30,7 @@
 #ifndef HAVE_PGDOWNLOADCONTEXT_HPP
 #define HAVE_PGDOWNLOADCONTEXT_HPP
 
+#include <cstring>
 #include <string>
 #include <stdint.h>
 
