--- print-null.c.orig	1993-04-22 20:40:19 UTC
+++ print-null.c
@@ -76,9 +76,17 @@ null_print(p, ip, length)
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
