--- print-null.c.orig	Mon May 12 17:35:00 2003
+++ print-null.c	Mon May 12 17:36:30 2003
@@ -76,9 +76,17 @@
 		printf("ip: ");
 		break;
 
+#ifdef AF_NS
 	case AF_NS:
 		printf("ns: ");
 		break;
+#endif /* AF_NS */
+#ifdef AF_NETBIOS
+        case AF_NETBIOS:
+                printf("netbios: ");
+                break;
+#endif /* AF_NETBIOS */
+
 
 	default:
 		printf("AF %d: ", family);
