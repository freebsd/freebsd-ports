--- mDNSCore/mDNS.c.orig	2019-07-20 09:39:10 UTC
+++ mDNSCore/mDNS.c
@@ -23,6 +23,7 @@
  * routines, or types (which may or may not be present on any given platform).
  */
 
+#include <stddef.h>
 #include "DNSCommon.h"                  // Defines general DNS utility routines
 #include "uDNS.h"                       // Defines entry points into unicast-specific routines
 #include "nsec.h"
