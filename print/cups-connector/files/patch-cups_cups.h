--- cups/cups.h.orig	2016-03-11 18:40:32 UTC
+++ cups/cups.h
@@ -12,6 +12,7 @@ https://developers.google.com/open-sourc
 #define _IPP_PRIVATE_STRUCTURES 1
 
 #include <cups/cups.h>
+#include <cups/ppd.h>
 #include <stddef.h>      // size_t
 #include <stdlib.h>      // free, calloc, malloc
 #include <sys/socket.h>  // AF_UNSPEC
