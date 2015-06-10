From 27b732f6bfcdcd96fd76e89c624f5f18ca944531 Mon Sep 17 00:00:00 2001
From: Guenter Kukkukk <kukks@samba.org>
Date: Sat, 16 Feb 2013 16:53:16 +0100
Subject: [PATCH] Fix internal DNS dyn. update, seen as: ; TSIG error with server: tsig verify failure

The dns update signed response must be handled differently than the TKEY response

Signed-off-by: Guenter Kukkukk <kukks@samba.org>
---
 source4/dns_server/dns_crypto.c |   44 ++++++++++++++++++++++++++++++++------
 1 files changed, 37 insertions(+), 7 deletions(-)

diff --git a/source4/dns_server/dns_crypto.c b/source4/dns_server/dns_crypto.c
index 7604a05..71adf68 100644
--- ./source4/dns_server/dns_crypto.c.orig	2012-10-02 08:24:46.000000000 +0000
+++ ./source4/dns_server/dns_crypto.c	2013-11-18 22:45:12.818702284 +0000
@@ -244,6 +244,8 @@
 	DATA_BLOB packet_blob, tsig_blob, sig;
 	uint8_t *buffer = NULL;
 	size_t buffer_len = 0;
+	size_t miclen_bytes = 0;
+	size_t mic_size = 0;
 	struct dns_server_tkey * tkey = NULL;
 	struct dns_res_rec *tsig = talloc_zero(mem_ctx, struct dns_res_rec);
 
@@ -298,16 +300,44 @@
 		return DNS_ERR(SERVER_FAILURE);
 	}
 
-	buffer_len = packet_blob.length + tsig_blob.length;
-	buffer = talloc_zero_array(mem_ctx, uint8_t, buffer_len);
-	if (buffer == NULL) {
-		return WERR_NOMEM;
-	}
+	/* DNS update must be handled differently than the TKEY case */ 
+	if ((packet->operation & DNS_OPCODE) == DNS_OPCODE_UPDATE) {
+		/* Here the request MIC must be placed in front of the buffer.
+		   Calculate the length of the buffer used for the request MIC:
+		   2 bytes (sizeof uint16_t) for the length itself
+		   length bytes of the MIC (here 16 + 12 = 28 bytes) */
+		miclen_bytes = sizeof(state->tsig->rdata.tsig_record.mac_size);
+		mic_size     = miclen_bytes + state->tsig->rdata.tsig_record.mac_size;
 
-	memcpy(buffer, packet_blob.data, packet_blob.length);
-	memcpy(buffer+packet_blob.length, tsig_blob.data, tsig_blob.length);
+		buffer_len = mic_size + packet_blob.length + tsig_blob.length;
+		buffer = talloc_zero_array(mem_ctx, uint8_t, buffer_len);
+		if (buffer == NULL) {
+			return WERR_NOMEM;
+		}
 
+		/* copy the 2 length bytes of request MIC in big-endian order */
+		RSSVAL(buffer,0,state->tsig->rdata.tsig_record.mac_size);
+
+		/* copy the request MIC itself */
+		memcpy(buffer + miclen_bytes, state->tsig->rdata.tsig_record.mac,
+			  state->tsig->rdata.tsig_record.mac_size);
+
+		/* copy the remaining data */
+		memcpy(buffer + mic_size, packet_blob.data, packet_blob.length);
+		memcpy(buffer + mic_size + packet_blob.length, tsig_blob.data, tsig_blob.length);
+	} else {
+		buffer_len = packet_blob.length + tsig_blob.length;
+		buffer = talloc_zero_array(mem_ctx, uint8_t, buffer_len);
+		if (buffer == NULL) {
+			return WERR_NOMEM;
+		}
 
+		memcpy(buffer, packet_blob.data, packet_blob.length);
+		memcpy(buffer+packet_blob.length, tsig_blob.data, tsig_blob.length);
+	}
+
+	/* FIXME: as in the verify case, some padding is wrong */
+	buffer_len -=2;
 	status = gensec_sign_packet(tkey->gensec, mem_ctx, buffer, buffer_len,
 				    buffer, buffer_len, &sig);
 	if (!NT_STATUS_IS_OK(status)) {
