--- opendmarc/opendmarc.c.orig	2017-03-04 13:28:39 UTC
+++ opendmarc/opendmarc.c
@@ -2193,7 +2193,7 @@ mlfi_eom(SMFICTX *ctx)
 	strncpy(dfc->mctx_fromdomain, domain, sizeof dfc->mctx_fromdomain - 1);
 
 	ostatus = opendmarc_policy_store_from_domain(cc->cctx_dmarc,
-	                                             from->hdr_value);
+	                                             dfc->mctx_fromdomain);
 	if (ostatus != DMARC_PARSE_OKAY)
 	{
 		if (conf->conf_dolog)
