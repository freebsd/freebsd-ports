--- sendmail/sendmail.h.orig	2020-07-02 05:00:37 UTC
+++ sendmail/sendmail.h
@@ -63,6 +63,10 @@ SM_UNUSED(static char SmailId[]) = "@(#)$Id: sendmail.
 #endif
 
 #include "bf.h"
+#if USE_BLACKLIST
+#include <blacklist.h>
+#endif
+#include "blacklist_client.h"
 #include "timers.h"
 #include <sm/exc.h>
 #include <sm/heap.h>
@@ -2575,6 +2579,10 @@ EXTERN int Hacks;	/* bit field of run-time enabled "ha
 #endif
 
 EXTERN int ConnectionRateWindowSize;
+
+#if USE_BLACKLIST
+EXTERN bool	UseBlacklist;
+#endif
 
 /*
 **  Declarations of useful functions
