--- dvbdevice.c.orig
+++ dvbdevice.c
@@ -7,6 +7,7 @@
  * $Id: dvbdevice.c 2.38 2010/05/01 09:47:13 kls Exp $
  */
 
+#include <stdint.h>
 #include "dvbdevice.h"
 #include <ctype.h>
 #include <errno.h>
@@ -800,10 +801,13 @@ bool cDvbDevice::Initialize(void)
                    NextCardIndex(1); // skips this one
                 }
              }
-          else if (Frontend == 0)
-             goto LastAdapter;
-          else
+          else {
+             if (Checked >= MAXDVBDEVICES || Adapter >= MAXDVBDEVICES)
+               goto LastAdapter;
+             if (Frontend == 0)
+               NextCardIndex(1); // skips this one
              goto NextAdapter;
+             }
           }
       NextAdapter: ;
       }
