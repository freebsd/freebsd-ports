--- qmail-smtpd.c.orig	2014-06-26 16:33:05.703716277 -0500
+++ qmail-smtpd.c	2014-06-26 16:40:11.516685934 -0500
@@ -116,6 +116,28 @@ int seenhelo = 0;
 char *badmailcond;
 char *badhelocond;
 
+void err_rbl(s1,s2,s3,s4,s5,s6,s7) char *s1, *s2, *s3, *s4, *s5, *s6, *s7; {
+  char *rblmatch;
+  stralloc rblmessage = {0};
+  stralloc new_s1 = {0};
+
+  rblmatch = env_get("RBLMATCH");
+
+  if (!stralloc_copys(&rblmessage,"553 sorry, your IP is listed on a RBL list ")) die_nomem(); 
+  if (!stralloc_cats(&rblmessage,rblmatch)) die_nomem(); 
+  if (!stralloc_cats(&rblmessage," (#5.7.1)\r\n")) die_nomem(); 
+  if (!stralloc_0(&rblmessage)) die_nomem(); 
+
+  if (!stralloc_copys(&new_s1, s1)) die_nomem();
+  if (!stralloc_cats(&new_s1, " ")) die_nomem();
+  if (!stralloc_cats(&new_s1, rblmatch)) die_nomem();
+  if (!stralloc_0(&new_s1)) die_nomem(); 
+
+  out(rblmessage.s); 
+  smtp_logg(new_s1.s,s2,s3,s4,s5,s6,s7);
+  return;
+  }
+
 void dohelo(arg) char *arg; 
 {
   if (!stralloc_copys(&helohost,arg)) die_nomem(); 
@@ -183,6 +205,8 @@ int tarpitcount = 0;
 int tarpitdelay = 0;
 
 char *auth;
+char *rbl2smtpd;
+char *rblmatch;
 int smtpauth = 0;	/* -1:Cert 0:none 1:login/plain 2:cram 3:login/plain/cram 11:must_login/plain 12:must_2 13:must_3 */
 int seenauth = 0;
 
@@ -344,6 +368,9 @@ void setup()
     if (!stralloc_cats(&mailto," ")) die_nomem();
   }
 
+  rbl2smtpd = env_get("RBL2SMTPD");
+  rblmatch = env_get("RBLMATCH");
+
   rblsmtpd = env_get("RBLSMTPD");
   if (rblsmtpd) {
     if (!stralloc_cats(&rblinfo,rblsmtpd)) die_nomem();
@@ -909,6 +936,10 @@ void smtp_rcpt(arg) char *arg; {
       return; 
     }
 
+    if (!seenauth && rbl2smtpd && rblmatch && str_len(rblmatch) != 0) {
+      err_rbl("Reject::RBL::RBL_Listed:",protocol.s,remoteip,remotehost,helohost.s,mailfrom.s,addr.s);
+      return;
+    }
     if (tarpitcount && flagerrcpts >= tarpitcount) { 	/* Tarpitting et al. */
       if (tarpitdelay == 999) flagnotorious++;
       err_rcpts("Reject::RCPT::Toomany_Rcptto",protocol.s,remoteip,remotehost,helohost.s,mailfrom.s,addr.s); 
