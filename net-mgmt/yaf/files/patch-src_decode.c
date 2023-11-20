--- src/decode.c.orig	2023-02-08 18:37:15 UTC
+++ src/decode.c
@@ -1653,6 +1653,12 @@ yfDecodeIP(
             key->dp = 0;
         }
         break;
+      case YF_PROTO_TUNNEL_IP6:
+        if (!(pkt = yfDecodeIP(ctx, YF_TYPE_IPv6, caplen, pkt, key, iplen,
+			       fraginfo, tcpinfo))) {
+	    return NULL;
+	}
+	break;
       default:
         /* No layer 4 header we understand. Zero ports. */
         key->sp = 0;
