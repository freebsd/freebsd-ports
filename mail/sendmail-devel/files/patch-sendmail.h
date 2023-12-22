--- sendmail/sendmail.h.orig	2023-12-05 09:53:22 UTC
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
@@ -2734,6 +2738,10 @@ EXTERN int Hacks;	/* bit field of run-time enabled "ha
 #endif
 
 EXTERN int ConnectionRateWindowSize;
+
+#if USE_BLACKLIST
+EXTERN bool	UseBlacklist;
+#endif
 
 /*
 **  Declarations of useful functions
