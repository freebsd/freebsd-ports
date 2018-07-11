After https://github.com/boostorg/uuid/commit/33da3e2a5b87 build fails:

xml-utils.cxx:34:10: fatal error: 'boost/uuid/sha1.hpp' file not found
#include <boost/uuid/sha1.hpp>
         ^~~~~~~~~~~~~~~~~~~~~

--- src/libcmis/xml-utils.cxx.orig	2016-03-01 16:14:26 UTC
+++ src/libcmis/xml-utils.cxx
@@ -31,7 +31,12 @@
 #include <sstream>
 #include <stdlib.h>
 
+#include <boost/version.hpp>
+#if (BOOST_VERSION >= 106600)
+#include <boost/uuid/detail/sha1.hpp>
+#else
 #include <boost/uuid/sha1.hpp>
+#endif
 #include <curl/curl.h>
 
 #include "xml-utils.hxx"
