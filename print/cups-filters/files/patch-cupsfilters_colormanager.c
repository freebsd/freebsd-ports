--- cupsfilters/colormanager.c.orig	2023-01-25 01:41:08 UTC
+++ cupsfilters/colormanager.c
@@ -26,6 +26,7 @@ MIT Open Source License  -  http://www.opensource.org/
 */
 
 
+#include <config.h>
 #include "colormanager.h"
 #include <cupsfilters/colord.h>
 //#include <cupsfilters/kmdevices.h>
@@ -327,7 +328,7 @@ _get_ppd_icc_fallback (ppd_file_t *ppd, char **qualifi
     /* expand to a full path if not already specified */
     if (attr->value[0] != '/')
       snprintf(full_path, sizeof(full_path),
-               "%s/profiles/%s", CUPSDATA, attr->value);
+               "%s/profiles/%s", CUPS_DATADIR, attr->value);
     else {
       strncpy(full_path, attr->value, sizeof(full_path) - 1);
       if (strlen(attr->value) > 1023)
