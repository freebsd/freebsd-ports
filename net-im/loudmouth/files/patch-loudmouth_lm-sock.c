--- loudmouth/lm-sock.c.orig	Mon Apr 16 23:37:43 2007
+++ loudmouth/lm-sock.c	Mon Apr 16 23:38:08 2007
@@ -273,9 +273,11 @@
 	case EAI_FAIL:     
 		return _("The nameserver encountered errors "
 			 "looking up this address");
+#ifdef EAI_NODATA
 	case EAI_NODATA:   
 		return _("The remote host exists but no address "
 			 "is available");
+#endif
 	case EAI_NONAME:   
 		return _("The remote address is unknown");
 	case EAI_FAMILY:
