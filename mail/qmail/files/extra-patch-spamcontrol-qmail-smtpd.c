--- qmail-smtpd.c.orig	Fri Jun 30 15:41:00 2006
+++ qmail-smtpd.c	Fri Jun 30 15:44:49 2006
@@ -129,6 +129,18 @@
   logs(s1,s2,s3,s4,s5,s6,s7);
   return;
   }
+void err_rbl(s1,s2,s3,s4,s5,s6,s7) char *s1, *s2, *s3, *s4, *s5, *s6, *s7; {
+  stralloc rblmessage = {0};
+
+  if (!stralloc_copys(&rblmessage,"553 sorry, your IP is listed on a RBL list ")) die_nomem(); 
+  if (!stralloc_cats(&rblmessage,env_get("RBLMATCH"))) die_nomem(); 
+  if (!stralloc_cats(&rblmessage," (#5.7.1)\r\n")) die_nomem(); 
+  if (!stralloc_0(&rblmessage)) die_nomem(); 
+
+  out(rblmessage.s); 
+  logs(s1,s2,s3,s4,s5,s6,s7);
+  return;
+  }
 void err_brcptto(s1,s2,s3,s4,s5,s6,s7) char *s1, *s2, *s3, *s4, *s5, *s6, *s7; {
   out("550 sorry, your envelope recipient is in my badrcptto list (#5.7.1)\r\n");
   logs(s1,s2,s3,s4,s5,s6,s7);
@@ -270,6 +282,8 @@
 
 char *auth;
 char *reqauth;
+char *rbl2smtpd;
+char *rblmatch;
 int smtpauth = 0;
 int seenauth = 0;
 
@@ -388,6 +402,9 @@
   if(env_get("UCSPITLS")) starttls = 1;
   if(starttls) reqttls = env_get("REQUIRETLS");
 
+  rbl2smtpd = env_get("RBL2SMTPD");
+  rblmatch = env_get("RBLMATCH");
+
 #ifdef RELAYMAILFROM
   if (!relayclient) {
     relaymailfromok = control_readfile(&relaymailfrom,"control/relaymailfrom",0);
@@ -876,6 +893,10 @@
       flagerrcpts++;
       return; 
     } 
+    if (!seenauth && rbl2smtpd && rblmatch && str_len(rblmatch) != 0) {
+      err_rbl("Reject::RBL::RBL_Listed:",protocol.s,remoteip,remotehost,helohost.s,mailfrom.s,addr.s);
+      return;
+    }
     if (tarpitcount && flagerrcpts >= tarpitcount) { 	/* Tarpitting et al. */
       err_rcpts("Reject::RCPT::Toomany_Rcptto:",protocol.s,remoteip,remotehost,helohost.s,mailfrom.s,addr.s); 
       return; 
