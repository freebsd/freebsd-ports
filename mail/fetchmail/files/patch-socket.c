--- socket.c.org	2009-08-08 16:01:49.000000000 +0200
+++ socket.c	2009-08-08 16:03:17.000000000 +0200
@@ -628,9 +628,10 @@
 				report(stdout, GT_("Unknown Issuer CommonName\n"));
 		}
 		if ((i = X509_NAME_get_text_by_NID(subj, NID_commonName, buf, sizeof(buf))) != -1) {
-			if (outlevel >= O_VERBOSE)
+			if (outlevel >= O_VERBOSE) {
 				report(stdout, GT_("Server CommonName: %s\n"), (tt = sdump(buf, i)));
-			xfree(tt);
+				xfree(tt);
+			}
 			if ((size_t)i >= sizeof(buf) - 1) {
 				/* Possible truncation. In this case, this is a DNS name, so this
 				 * is really bad. We do not tolerate this even in the non-strict case. */
