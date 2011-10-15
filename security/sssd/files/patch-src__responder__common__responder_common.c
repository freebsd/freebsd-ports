--- ./src/responder/common/responder_common.c.orig	2011-08-29 11:39:05.000000000 -0400
+++ ./src/responder/common/responder_common.c	2011-10-13 12:15:03.000000000 -0400
@@ -195,7 +195,7 @@
         talloc_free(cctx);
         break;
 
-    case ENODATA:
+    case ECONNRESET:
         DEBUG(5, ("Client disconnected!\n"));
         talloc_free(cctx);
         break;
