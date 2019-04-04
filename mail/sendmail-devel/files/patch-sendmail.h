--- sendmail/sendmail.h.orig	2019-02-15 10:30:19 UTC
+++ sendmail/sendmail.h
@@ -61,6 +61,10 @@ SM_UNUSED(static char SmailId[]) = "@(#)
 #endif /* _DEFINE */
 
 #include "bf.h"
+#if USE_BLACKLIST
+#include <blacklist.h>
+#endif
+#include "blacklist_client.h"
 #include "timers.h"
 #include <sm/exc.h>
 #include <sm/heap.h>
@@ -2513,6 +2517,10 @@ EXTERN int Hacks;	/* bit field of run-ti
 
 EXTERN int ConnectionRateWindowSize;
 
+#if USE_BLACKLIST
+EXTERN bool	UseBlacklist;
+#endif
+
 /*
 **  Declarations of useful functions
 */
