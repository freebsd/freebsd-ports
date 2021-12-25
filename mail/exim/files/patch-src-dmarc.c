--- src/dmarc.c.orig	2021-04-30 12:08:21 UTC
+++ src/dmarc.c
@@ -37,6 +37,7 @@ uschar *spf_human_readable = NULL;
 u_char *header_from_sender = NULL;
 int history_file_status    = DMARC_HIST_OK;
 uschar *dkim_history_buffer= NULL;
+uschar *dkim_selector = NULL;
 
 typedef struct dmarc_exim_p {
   uschar *name;
@@ -446,7 +447,7 @@ if (!dmarc_abort && !sender_host_authenticated)
 		  vs == PDKIM_VERIFY_INVALID ? DMARC_POLICY_DKIM_OUTCOME_TMPFAIL :
 		  DMARC_POLICY_DKIM_OUTCOME_NONE;
     libdm_status = opendmarc_policy_store_dkim(dmarc_pctx, US sig->domain,
-					       dkim_result, US"");
+					       dkim_selector, dkim_result, US"");
     DEBUG(D_receive)
       debug_printf("DMARC adding DKIM sender domain = %s\n", sig->domain);
     if (libdm_status != DMARC_PARSE_OKAY)
