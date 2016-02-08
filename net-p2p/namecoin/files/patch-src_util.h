--- src/util.h.orig	2014-12-18 14:47:02 UTC
+++ src/util.h
@@ -15,11 +15,13 @@
 #include <vector>
 #include <string>
 
+#ifndef Q_MOC_RUN
 #include <boost/version.hpp>
 #include <boost/thread.hpp>
 #include <boost/interprocess/sync/interprocess_recursive_mutex.hpp>
 #include <boost/date_time/gregorian/gregorian_types.hpp>
 #include <boost/date_time/posix_time/posix_time_types.hpp>
+#endif
 
 #include <openssl/sha.h>
 #include <openssl/ripemd.h>
