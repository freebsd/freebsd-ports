--- ./alpine/send.c.orig	2013-08-14 23:36:01.000000000 -0500
+++ ./alpine/send.c	2014-05-25 19:15:31.000000000 -0500
@@ -71,8 +71,6 @@
     PARAMETER         *parameter;
 } BODY_PARTICULARS_S;
 
-#define	PHONE_HOME_VERSION	"-count"
-#define	PHONE_HOME_HOST		"docserver.cac.washington.edu"
 
 /*
  * macro to bind pico's headerentry pointer to PINEFIELD "extdata" hook
@@ -5481,63 +5479,6 @@
 
 
 /*----------------------------------------------------------------------
-     Generate and send a message back to the pine development team
-     
-Args: none
-
-Returns: none
-----*/      
-void
-phone_home(char *addr)
-{
-    char      tmp[MAX_ADDRESS];
-    ENVELOPE *outgoing;
-    BODY     *body;
-
-    outgoing = mail_newenvelope();
-    if(!addr || !strindex(addr, '@')){
-	snprintf(addr = tmp, sizeof(tmp), "alpine%s@%s", PHONE_HOME_VERSION, PHONE_HOME_HOST);
-	tmp[sizeof(tmp)-1] = '\0';
-    }
-
-    rfc822_parse_adrlist(&outgoing->to, addr, ps_global->maildomain);
-
-    outgoing->message_id  = generate_message_id();
-    outgoing->subject	  = cpystr("Document Request");
-    outgoing->from	  = phone_home_from();
-
-    body       = mail_newbody();
-    body->type = TYPETEXT;
-
-    if((body->contents.text.data = (void *)so_get(PicoText,NULL,EDIT_ACCESS)) != NULL){
-	so_puts((STORE_S *)body->contents.text.data, "Document request: ");
-	so_puts((STORE_S *)body->contents.text.data, "Alpine-");
-	so_puts((STORE_S *)body->contents.text.data, ALPINE_VERSION);
-	if(ps_global->first_time_user)
-	  so_puts((STORE_S *)body->contents.text.data, " for New Users");
-
-	if(ps_global->VAR_INBOX_PATH && ps_global->VAR_INBOX_PATH[0] == '{')
-	  so_puts((STORE_S *)body->contents.text.data, " and IMAP");
-
-	if(ps_global->VAR_NNTP_SERVER && ps_global->VAR_NNTP_SERVER[0]
-	      && ps_global->VAR_NNTP_SERVER[0][0])
-	  so_puts((STORE_S *)body->contents.text.data, " and NNTP");
-
-	(void)pine_simple_send(outgoing, &body, NULL,NULL,NULL,NULL, SS_NULLRP);
-
-	q_status_message(SM_ORDER, 1, 3, "Thanks for being counted!");
-    }
-    else
-      q_status_message(SM_ORDER | SM_DING, 3, 4,
-		       "Problem creating space for message text.");
-
-    mail_free_envelope(&outgoing);
-    pine_free_body(&body);
-
-}
-
-
-/*----------------------------------------------------------------------
     Set up fields for passing to pico.  Assumes first text part is
     intended to be passed along for editing, and is in the form of
     of a storage object brought into existence sometime before pico_send().
