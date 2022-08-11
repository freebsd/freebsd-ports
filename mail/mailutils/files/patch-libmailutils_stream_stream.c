--- libmailutils/stream/stream.c.orig	2022-02-12 15:20:43 UTC
+++ libmailutils/stream/stream.c
@@ -132,6 +132,7 @@ mu_stream_seterr (struct _mu_stream *stream, int code,
     case EINTR:
     case ENOSYS:
     case EINPROGRESS:
+    case MU_ERR_INFO_UNAVAILABLE:
       break;
 
     default:
