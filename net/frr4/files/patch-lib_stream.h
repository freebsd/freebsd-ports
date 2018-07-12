--- lib/stream.h.orig	2018-07-12 06:57:53 UTC
+++ lib/stream.h
@@ -123,9 +123,6 @@ struct stream_fifo {
 #define STREAM_CONCAT_REMAIN(S1, S2, size) ((size) - (S1)->endp - (S2)->endp)
 
 /* deprecated macros - do not use in new code */
-#if CONFDATE > 20181128
-CPP_NOTICE("lib: time to remove deprecated stream.h macros")
-#endif
 #define STREAM_PNT(S)   stream_pnt((S))
 #define STREAM_REMAIN(S) STREAM_WRITEABLE((S))
 
