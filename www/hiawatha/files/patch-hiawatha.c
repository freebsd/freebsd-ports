--- ./hiawatha.c.orig	2010-11-02 17:03:24.000000000 -0400
+++ ./hiawatha.c	2011-02-25 16:41:31.000000000 -0500
@@ -34,6 +34,7 @@
 #include <sys/wait.h>
 #include <sys/socket.h>
 #include <sys/time.h>
+#include <limits.h>
 #include "alternative.h"
 #include "mimetype.h"
 #include "serverconfig.h"
@@ -418,7 +419,7 @@
 							*strend = '\0';
 							content_length = str2int(strstart);
 							*strend = '\r';
-							if (content_length < 0) {
+							if ((content_length < 0) || (INT_MAX - content_length - 2 <= header_length)) {
 								result = 400;
 								break;
 							}
