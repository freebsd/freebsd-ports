--- e-util/e-host-utils.c.orig	Tue Apr 13 15:19:43 2004
+++ e-util/e-host-utils.c	Sun Oct  3 01:17:57 2004
@@ -136,12 +136,21 @@
 	case EAI_SERVICE:
 		return NO_DATA;
 		break;
+#ifdef EAI_ADDRFAMILY
 	case EAI_ADDRFAMILY:
 		return NO_ADDRESS;
 		break;
+#endif
+#if defined(EAI_NODATA) && EAI_NODATA != EAI_NONAME
 	case EAI_NODATA:
 		return NO_DATA;
 		break;
+#endif
+#ifdef EAI_NOFAMILY
+	case EAI_NOFAMILY:
+		return NO_ADDRESS;
+		break;
+#endif
 	case EAI_MEMORY:
 		return ENOMEM;
 		break;
