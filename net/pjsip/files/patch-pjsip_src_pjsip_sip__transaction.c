--- pjsip/src/pjsip/sip_transaction.c.orig	2016-02-22 13:36:31 UTC
+++ pjsip/src/pjsip/sip_transaction.c
@@ -288,7 +288,8 @@ static pj_status_t create_tsx_key_2543( pj_pool_t *poo
     host = &rdata->msg_info.via->sent_by.host;
 
     /* Calculate length required. */
-    len_required = 9 +			    /* CSeq number */
+    len_required = method->name.slen +      /* Method */
+		   9 +			    /* CSeq number */
 		   rdata->msg_info.from->tag.slen +   /* From tag. */
 		   rdata->msg_info.cid->id.slen +    /* Call-ID */
 		   host->slen +		    /* Via host. */
