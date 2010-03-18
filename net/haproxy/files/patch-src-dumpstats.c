--- src/dumpstats.c.orig	2010-03-18 01:41:57.000000000 +0300
+++ src/dumpstats.c	2010-03-18 20:25:27.000000000 +0300
@@ -2458,7 +2458,7 @@
 
 		chunk_printf(&msg,
 			     " wex=%s\n"
-			     "      data=%p r=%d w=%d lr=%d total=%lld\n",
+			     "      data=%p r=%ld w=%ld lr=%ld total=%lld\n",
 			     sess->req->wex ?
 			     human_time(TICKS_TO_MS(sess->req->wex - now_ms),
 					TICKS_TO_MS(1000)) : "<NEVER>",
@@ -2488,7 +2488,7 @@
 
 		chunk_printf(&msg,
 			     " wex=%s\n"
-			     "      data=%p r=%d w=%d lr=%d total=%lld\n",
+			     "      data=%p r=%ld w=%ld lr=%ld total=%lld\n",
 			     sess->rep->wex ?
 			     human_time(TICKS_TO_MS(sess->rep->wex - now_ms),
 					TICKS_TO_MS(1000)) : "<NEVER>",
