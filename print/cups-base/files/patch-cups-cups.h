# This is to workaround a CUPS bug. Should be fixed by 1.7.3.
# pfg@ filed a bug report upstream: https://www.cups.org/str.php?L4397
#
--- cups/cups.h.orig	2014-04-04 14:02:34.056258164 +0400
+++ cups/cups.h	2014-04-04 14:02:46.828258878 +0400
@@ -30,10 +30,6 @@
 typedef off_t ssize_t;			/* @private@ */
 #  endif /* WIN32 && !__CUPS_SSIZE_T_DEFINED */
 
-#  ifdef __BLOCKS__
-#    include <dispatch/dispatch.h>
-#  endif /* __BLOCKS__ */
-
 #  include "file.h"
 #  include "ipp.h"
 #  include "language.h"
