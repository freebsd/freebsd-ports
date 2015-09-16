--- src/wps/httpread.c.orig	2015-03-15 17:30:39 UTC
+++ src/wps/httpread.c
@@ -533,6 +533,13 @@ static void httpread_read_handler(int sd
 					if (!isxdigit(*cbp))
 						goto bad;
 					h->chunk_size = strtoul(cbp, NULL, 16);
+					if (h->chunk_size < 0 ||
+					    h->chunk_size > h->max_bytes) {
+						wpa_printf(MSG_DEBUG,
+							   "httpread: Invalid chunk size %d",
+							   h->chunk_size);
+						goto bad;
+					}
 					/* throw away chunk header
 					 * so we have only real data
 					 */
