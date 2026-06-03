--- opendkim/opendkim.c	2024-12-21 10:50:37.224458000 +0100
+++ opendkim/opendkim.c	2024-12-21 10:52:34.002259000 +0100
@@ -12105,8 +12105,10 @@
 
 				if (domainok)
 				{
-					strlcpy((char *) dfc->mctx_domain, p,
-					        sizeof dfc->mctx_domain);
+					// We must not use strlcpy() here since
+					// src and dst overlap.
+					char* p2 = dfc->mctx_domain;
+					while( (*p2++ = *p++) );
 					break;
 				}
 			}
commit 7c70ee7c86da1cecc621182355cc950d3b193314
Author: David Bürgin <dbuergin@gluet.ch>
Date:   Sat Oct 14 09:19:37 2023 +0200

    Delete Authentication-Results headers in reverse

diff --git opendkim/opendkim.c opendkim/opendkim.c
index 803f37b0..cfa5f018 100644
--- opendkim/opendkim.c
+++ opendkim/opendkim.c
@@ -13653,8 +13653,15 @@ mlfi_eom(SMFICTX *ctx)
 			return SMFIS_TEMPFAIL;
 		}
 
-		c = 0;
+		c = 1;
+
 		for (hdr = dfc->mctx_hqhead; hdr != NULL; hdr = hdr->hdr_next)
+		{
+			if (strcasecmp(hdr->hdr_hdr, AUTHRESULTSHDR) == 0)
+				c++;
+		}
+
+		for (hdr = dfc->mctx_hqtail; hdr != NULL; hdr = hdr->hdr_prev)
 		{
 			memset(ares, '\0', sizeof(struct authres));
 
@@ -13666,7 +13673,7 @@ mlfi_eom(SMFICTX *ctx)
 				char *slash;
 
 				/* remember index */
-				c++;
+				c--;
 
 				/* parse the header */
 				arstat = ares_parse((u_char *) hdr->hdr_val,
