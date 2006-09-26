--- iked/ikev2_payload.c.orig	Thu Jul  6 06:36:39 2006
+++ iked/ikev2_payload.c	Wed Sep 20 15:24:24 2006
@@ -106,14 +106,14 @@
 	bytes = packet->l;
 	if (bytes < sizeof(struct ikev2_header)) {
 		TRACE((PLOGLOC,
-		       "packet length %d is shorter than ikev2 header\n",
+		       "packet length %zu is shorter than ikev2 header\n",
 		       bytes));
 		return -1;
 	}
 	if (bytes != get_uint32(&hdr->length)) {
 		/* actually, shouldn't happen since already checked in isakmp.c */
 		TRACE((PLOGLOC,
-		       "packet length does not match with length field of ikev2 header (%d != %d)\n",
+		       "packet length does not match with length field of ikev2 header (%zu != %u)\n",
 		       bytes, get_uint32(&hdr->length)));
 		return -1;
 	}
@@ -125,7 +125,7 @@
 	     POINT_NEXT_PAYLOAD(p, type)) {
 		if (bytes < sizeof(struct ikev2_payload_header)) {
 			TRACE((PLOGLOC,
-			       "offset 0x%x: packet remaining (%d) can't hold payload header\n",
+			       "offset 0x%x: packet remaining (%zu) can't hold payload header\n",
 			       packet->l - bytes, bytes));
 			return -1;
 		}
@@ -135,7 +135,7 @@
 		       payload_length));
 		if (bytes < payload_length) {
 			TRACE((PLOGLOC,
-			       "payload length (%d) longer than packet remaining (%d)\n",
+			       "payload length (%d) longer than packet remaining (%zu)\n",
 			       payload_length, bytes));
 			return -1;
 		}
@@ -148,7 +148,7 @@
 		if (IKEV2_PAYLOAD_TYPE_DEFINED(type) &&
 		    payload_length < IKEV2_PAYLOAD_TYPES(type).minimum_length) {
 			TRACE((PLOGLOC,
-			       "payload length (%d) is shorter than minimum (%d)\n",
+			       "payload length (%d) is shorter than minimum (%zu)\n",
 			       payload_length,
 			       IKEV2_PAYLOAD_TYPES(type).minimum_length));
 			return -1;
@@ -174,7 +174,7 @@
 				if (payload_length <
 				    sizeof(struct ikev2payl_notify) + n->nh.spi_size) {
 					TRACE((PLOGLOC,
-					       "payload length (%d) is shorter than expected (%d)\n",
+					       "payload length (%d) is shorter than expected (%zu)\n",
 					       payload_length,
 					       sizeof(struct ikev2payl_notify) +
 					       n->nh.spi_size));
@@ -190,7 +190,7 @@
 				    sizeof(struct ikev2payl_delete) +
 				    d->dh.spi_size * get_uint16(&d->dh.num_spi)) {
 					TRACE((PLOGLOC,
-					       "payload length (%d) is shorter than expected (%d)\n",
+					       "payload length (%d) is shorter than expected (%zu)\n",
 					       payload_length,
 					       sizeof(struct ikev2payl_delete) +
 					       d->dh.spi_size * get_uint16(&d->dh.num_spi)));
@@ -308,7 +308,7 @@
 	TRACE((PLOGLOC, "TS payload len %d num_ts %d\n",
 	       get_payload_length(payload), ts_payload->tsh.num_ts));
 	if (get_payload_length(ts_payload) < sizeof(struct ikev2payl_traffic_selector)) {
-		TRACE((PLOGLOC, "short TS payload (%d < %d)\n",
+		TRACE((PLOGLOC, "short TS payload (%u < %zu)\n",
 		       get_payload_length(ts_payload),
 		       sizeof(struct ikev2payl_traffic_selector)));
 		return -1;
@@ -321,7 +321,7 @@
 	for (i = 0; i < ts_payload->tsh.num_ts; ++i) {
 		if (ts_bytes < sizeof(struct ikev2_traffic_selector)) {
 			TRACE((PLOGLOC,
-			       "TS overflows payload length (%d < %d)\n",
+			       "TS overflows payload length (%zu < %zu)\n",
 			       ts_bytes,
 			       sizeof(struct ikev2_traffic_selector)));
 			return -1;	/* short payload */
@@ -338,13 +338,13 @@
 		 * assert sizeof(...)+2*addrsize <= ts_len <= ts_bytes
 		 */
 		if (ts_len < sizeof(struct ikev2_traffic_selector) + 2 * addrsize) {	/* ??? */
-			TRACE((PLOGLOC, "short traffic selector (%d < %d)\n",
+			TRACE((PLOGLOC, "short traffic selector (%u < %zu)\n",
 			       ts_len,
 			       sizeof(struct ikev2_traffic_selector) + 2 * addrsize));
 			return -1;
 		}
 		if (ts_bytes < ts_len) {
-			TRACE((PLOGLOC, "TS overflows payload boundary (%d < %d)\n",
+			TRACE((PLOGLOC, "TS overflows payload boundary (%zu < %u)\n",
 			       ts_bytes, ts_len));
 			return -1;	/* short payload */
 		}
@@ -396,7 +396,7 @@
 	if (get_payload_data_length(p) < icv_len) {
 		isakmp_log(ike_sa, 0, 0, 0,
 			   PLOG_PROTOERR, PLOGLOC,
-			   "payload content length (%d) shorter than expected ICV length (%d)\n",
+			   "payload content length (%zd) shorter than expected ICV length (%zu)\n",
 			   get_payload_data_length(p), icv_len);
 		goto fail;	/* malformed */
 	}
