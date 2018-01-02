--- sendmail/sendmail.h.orig	2015-06-19 12:59:29 UTC
+++ sendmail/sendmail.h
@@ -57,6 +57,10 @@ SM_UNUSED(static char SmailId[]) = "@(#)
 #endif /* _DEFINE */
 
 #include "bf.h"
+#if USE_BLACKLIST
+#include <blacklist.h>
+#endif
+#include "blacklist_client.h"
 #include "timers.h"
 #include <sm/exc.h>
 #include <sm/heap.h>
@@ -2544,6 +2548,10 @@ EXTERN int ConnectionRateWindowSize;
 EXTERN bool	SSLEngineInitialized;
 #endif /* STARTTLS && USE_OPENSSL_ENGINE */
 
+#if USE_BLACKLIST
+EXTERN bool	UseBlacklist;
+#endif
+
 /*
 **  Declarations of useful functions
 */
