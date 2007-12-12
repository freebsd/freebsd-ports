--- stream/stream_dvd.h.orig	2007-10-08 03:49:26.000000000 +0800
+++ stream/stream_dvd.h	2007-10-26 20:38:27.000000000 +0800
@@ -1,19 +1,7 @@
-#ifdef USE_DVDREAD_INTERNAL
-#include "dvdread/dvd_reader.h"
-#include "dvdread/ifo_types.h"
-#include "dvdread/ifo_read.h"
-#include "dvdread/nav_read.h"
-#elif defined(USE_DVDNAV)
-#include <dvd_reader.h>
-#include <ifo_types.h>
-#include <ifo_read.h>
-#include <nav_read.h>
-#else
-#include <dvdread/dvd_reader.h>
-#include <dvdread/ifo_types.h>
-#include <dvdread/ifo_read.h>
-#include <dvdread/nav_read.h>
-#endif
+#include "../dvdread/dvd_reader.h"
+#include "../dvdread/ifo_types.h"
+#include "../dvdread/ifo_read.h"
+#include "../dvdread/nav_read.h"
 
 typedef struct {
   dvd_reader_t *dvd;
