--- lib/zclient.c.orig	2026-07-15 15:51:52 UTC
+++ lib/zclient.c
@@ -3191,6 +3191,8 @@ size_t zebra_interface_link_params_write(struct stream
  * :               :
  * |               |
  * +-+-+-+-+-+-+-+-+
+ * |  dst_pfx_len  |  prefixlen of destination (peer) address; 0 = unknown
+ * +-+-+-+-+-+-+-+-+
  */
 
 static int memconstant(const void *s, int c, size_t n)
@@ -3243,6 +3245,7 @@ struct connected *zebra_interface_address_read(int typ
 
 	/* Fetch destination address. */
 	STREAM_GET(&d.u.prefix, s, plen);
+	STREAM_GETC(s, d.prefixlen);
 
 	/* N.B. NULL destination pointers are encoded as all zeroes */
 	dp = memconstant(&d.u.prefix, 0, plen) ? NULL : &d;
@@ -3256,10 +3259,19 @@ struct connected *zebra_interface_address_read(int typ
 		}
 		if (ifc) {
 			ifc->flags = ifc_flags;
-			if (ifc->destination)
-				ifc->destination->prefixlen =
-					ifc->address->prefixlen;
-			else if (CHECK_FLAG(ifc->flags, ZEBRA_IFA_PEER)) {
+			if (ifc->destination) {
+				/* Preserve peer-side prefixlen from the wire
+				 * (FreeBSD point-to-point tunnels: local /32,
+				 * peer carries the real subnet prefixlen).
+				 * Fall back to address prefixlen when the
+				 * sender didn't supply one. */
+				if (d.prefixlen)
+					ifc->destination->prefixlen =
+						d.prefixlen;
+				else
+					ifc->destination->prefixlen =
+						ifc->address->prefixlen;
+			} else if (CHECK_FLAG(ifc->flags, ZEBRA_IFA_PEER)) {
 				/* carp interfaces on OpenBSD with 0.0.0.0/0 as
 				 * "peer" */
 				flog_err(
