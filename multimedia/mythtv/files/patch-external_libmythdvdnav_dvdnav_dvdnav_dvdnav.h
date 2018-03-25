--- external/libmythdvdnav/dvdnav/dvdnav/dvdnav.h.orig	2018-01-11 12:39:22 UTC
+++ external/libmythdvdnav/dvdnav/dvdnav/dvdnav.h
@@ -33,11 +33,11 @@
 extern "C" {
 #endif
 
-#include <dvdnav/dvd_types.h>
+#include "dvd_types.h"
 #include <dvdread/dvd_reader.h>
 #include <dvdread/nav_types.h>
 #include <dvdread/ifo_types.h> /* For vm_cmd_t */
-#include <dvdnav/dvdnav_events.h>
+#include "dvdnav_events.h"
 
 #include "compat.h"
 
