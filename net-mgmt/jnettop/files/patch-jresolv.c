--- jresolv.c.orig	2006-04-12 03:47:01.000000000 -0400
+++ jresolv.c	2011-06-20 11:37:40.000000000 -0400
@@ -306,6 +306,10 @@
 	case DLT_EN10MB:
 		result = resolveStreamEther(packet, data, len, stream, payloads);
 		break;
+	case DLT_NULL:
+	case DLT_LOOP:
+		result = resolveStreamIPn(packet, data + 4, len - 4, stream, payloads);
+		break;
 #ifdef linux
 #ifdef DLT_LINUX_SLL
 	case DLT_LINUX_SLL:
