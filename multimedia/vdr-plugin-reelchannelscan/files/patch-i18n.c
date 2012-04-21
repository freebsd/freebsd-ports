--- a/i18n.c
+++ b/i18n.c
@@ -23,8 +23,10 @@
  *
  ***************************************************************************/
 
+#include <vdr/config.h>
 #include "i18n.h"
 
+#if (APIVERSNUM < 10507)
 const tI18nPhrase Phrases[] = {
     {"Channel Scan",
      "Kanalsuche",
@@ -1881,3 +1883,4 @@ const tI18nPhrase Phrases[] = {
      },
     {NULL}
 };
+#endif
