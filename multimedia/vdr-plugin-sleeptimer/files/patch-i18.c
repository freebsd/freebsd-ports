--- a/i18n.c
+++ b/i18n.c
@@ -6,9 +6,10 @@
  * $Id: i18n.c 1.3 2002/06/23 13:05:59 kls Exp $
  */
 
-#include "i18n.h"
+#include <vdr/config.h>
 
 #if VDRVERSNUM < 10507
+#include "i18n.h"
 
 const tI18nPhrase Phrases[] = {
   { "Not active",// English
