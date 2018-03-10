--- lib/utils/fd_utils.cpp.orig	2014-01-25 20:13:54 UTC
+++ lib/utils/fd_utils.cpp
@@ -21,6 +21,7 @@
 
 #include "fd_utils.h"
 #include <sys/socket.h>
+#include <sys/types.h>
 #include <fcntl.h>
 
 QTC_EXPORT bool
