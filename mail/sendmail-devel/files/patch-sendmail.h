--- sendmail/sendmail.h.orig	2025-02-05 18:32:59 UTC
+++ sendmail/sendmail.h
@@ -73,6 +73,10 @@ SM_UNUSED(static char SmailId[]) = "@(#)$Id: sendmail.
 #endif
 
 #include "bf.h"
+#if USE_BLACKLIST
+#include <blacklist.h>
+#endif
+#include "blacklist_client.h"
 #include "timers.h"
 #include <sm/exc.h>
 #include <sm/gen.h>
@@ -2781,6 +2785,10 @@ EXTERN int ConnectionRateWindowSize;
 #endif
 
 EXTERN int ConnectionRateWindowSize;
+
+#if USE_BLACKLIST
+EXTERN bool	UseBlacklist;
+#endif
 
 /*
 **  Declarations of useful functions
