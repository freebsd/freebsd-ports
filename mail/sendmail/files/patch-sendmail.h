--- sendmail/sendmail.h.orig	2025-11-26 16:02:45 UTC
+++ sendmail/sendmail.h
@@ -79,6 +79,10 @@ SM_UNUSED(static char SmailId[]) = "@(#)$Id: sendmail.
 #endif
 
 #include "bf.h"
+#if USE_BLOCKLIST
+#include <blocklist.h>
+#endif
+#include "blocklist_client.h"
 #include "timers.h"
 #include <sm/exc.h>
 #include <sm/gen.h>
@@ -2809,6 +2813,10 @@ EXTERN int ConnectionRateWindowSize;
 #endif
 
 EXTERN int ConnectionRateWindowSize;
+
+#if USE_BLOCKLIST
+EXTERN bool	UseBlocklist;
+#endif
 
 /*
 **  Declarations of useful functions
