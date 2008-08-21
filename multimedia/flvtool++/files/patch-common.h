--- common.h.orig	2008-08-07 21:56:41.000000000 +0800
+++ common.h	2008-08-07 21:58:29.000000000 +0800
@@ -19,6 +19,10 @@
 #include <boost/shared_ptr.hpp>
 #include <stdexcept>
 
+#include <sys/endian.h>
+
+#define	bswap_64	bswap64
+
 using std::map;
 using std::vector;
 using std::string;
