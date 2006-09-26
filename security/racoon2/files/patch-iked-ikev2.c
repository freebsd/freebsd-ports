--- iked/ikev2.c.orig	Thu Jul  6 05:41:11 2006
+++ iked/ikev2.c	Wed Sep 20 15:24:24 2006
@@ -556,7 +556,7 @@
 	       ike_sa, packet, (int)packet->l));
 	if (packet->l > IKEV2_SHOULD_SUPPORT_PACKET_SIZE) {
 		INFO((PLOGLOC,
-		      "packet size (%d) larger than recommended implementation minimum (%d)\n",
+		      "packet size (%zu) larger than recommended implementation minimum (%d)\n",
 		      packet->l, IKEV2_SHOULD_SUPPORT_PACKET_SIZE));
 	}
 
@@ -1340,9 +1340,9 @@
 	}
 	dhlen = get_payload_length(&ke->header) - sizeof(struct ikev2payl_ke);
 	if (dhlen != dh_value_len((struct dhgroup *)negotiated_sa->dhdef->definition)) {
-		TRACE((PLOGLOC, "KE data length %d, should be %lu\n",
+		TRACE((PLOGLOC, "KE data length %d, should be %zu\n",
 		       dhlen,
-		       (unsigned long)dh_value_len((struct dhgroup *)negotiated_sa->dhdef->definition)));
+		       dh_value_len((struct dhgroup *)negotiated_sa->dhdef->definition)));
 		/* send INVALID_SYNTAX ??? */
 		goto malformed_payload;
 	}
@@ -3175,9 +3175,9 @@
 			/* send repsonse INVALID_SYNTAX */
 			isakmp_log(ike_sa, local, remote, msg,
 				   PLOG_INTERR, PLOGLOC,
-				   "invalid KE payload (data length %u != %lu)\n",
+				   "invalid KE payload (data length %u != %zu)\n",
 				   dhlen,
-				   (unsigned long)dh_value_len((struct dhgroup *)dhdef->definition));
+				   dh_value_len((struct dhgroup *)dhdef->definition));
 			goto respond_invalid_syntax;
 		}
 
@@ -3606,10 +3606,9 @@
 		if (dhlen != dh_value_len((struct dhgroup *)dhdef->definition)) {
 			isakmp_log(ike_sa, local, remote, msg,
 				   PLOG_INTERR, PLOGLOC,
-				   "invalid KE payload (data length %u != %lu)\n",
+				   "invalid KE payload (data length %u != %zu)\n",
 				   dhlen,
-				   (unsigned long)dh_value_len((struct dhgroup *)dhdef->
-						definition));
+				   dh_value_len((struct dhgroup *)dhdef->definition));
 			++isakmpstat.malformed_payload;
 			goto abort;
 		}
@@ -5146,8 +5145,8 @@
 		/* shouldn't happen */
 		isakmp_log(sa, 0, 0, 0,
 			   PLOG_PROTOERR, PLOGLOC,
-			   "requrired key length %lu exceeds 255 times the output of PRF %lu\n",
-			   (u_long)need_len, (u_long)prf_output_len);
+			   "requrired key length %zd exceeds 255 times the output of PRF %zu\n",
+			   need_len, prf_output_len);
 		return 0;
 	}
 
