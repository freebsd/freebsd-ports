--- libmailutils/stream/streamcpy.c.orig	2022-02-12 15:20:43 UTC
+++ libmailutils/stream/streamcpy.c
@@ -55,7 +55,11 @@ mu_stream_copy_wcb (mu_stream_t dst, mu_stream_t src, 
 	case 0:
 	  break;
 
+	case EAGAIN:
+	case EINTR:
 	case ENOSYS:
+	case EINPROGRESS:
+	case MU_ERR_INFO_UNAVAILABLE:
 	  size = 0;
 	  break;
 
