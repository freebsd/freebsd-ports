--- sendmail/sendmail.h.orig	2026-06-19 08:47:02 UTC
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
@@ -2815,6 +2819,10 @@ EXTERN int ConnectionRateWindowSize;
 #endif
 
 EXTERN int ConnectionRateWindowSize;
+
+#if USE_BLOCKLIST
+EXTERN bool	UseBlocklist;
+#endif
 
 /*
 **  Declarations of useful functions
