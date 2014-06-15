--- ./pith/send.c.orig	2013-08-14 23:36:22.000000000 -0500
+++ ./pith/send.c	2014-05-25 19:15:32.000000000 -0500
@@ -210,13 +210,6 @@
 
 
 /*
- * Phone home hash controls
- */
-#define PH_HASHBITS	24
-#define PH_MAXHASH	(1<<(PH_HASHBITS))
-
-
-/*
  * postponed_stream - return stream associated with postponed messages
  *                    in argument.
  */
@@ -1677,48 +1670,6 @@
 }
 
 
-/*
- * phone_home_from - make phone home request's from address IMpersonal.
- *		     Doesn't include user's personal name.
- */
-ADDRESS *
-phone_home_from(void)
-{
-    ADDRESS *addr = mail_newaddr();
-    char     tmp[32];
-
-    /* garble up mailbox name */
-    snprintf(tmp, sizeof(tmp), "hash_%08u", phone_home_hash(ps_global->VAR_USER_ID));
-    tmp[sizeof(tmp)-1] = '\0';
-    addr->mailbox = cpystr(tmp);
-    addr->host	  = cpystr(ps_global->maildomain);
-    return(addr);
-}
-
-
-/*
- * one-way-hash a username into an 8-digit decimal number 
- *
- * Corey Satten, corey@cac.washington.edu, 7/15/98
- */
-unsigned int
-phone_home_hash(char *s)
-{
-    unsigned int h;
-    
-    for (h=0; *s; ++s) {
-        if (h & 1)
-	  h = (h>>1) | (PH_MAXHASH/2);
-        else 
-	  h = (h>>1);
-
-        h = ((h+1) * ((unsigned char) *s)) & (PH_MAXHASH - 1);
-    }
-    
-    return (h);
-}
-
-
 /*----------------------------------------------------------------------
      Call the mailer, SMTP, sendmail or whatever
      
