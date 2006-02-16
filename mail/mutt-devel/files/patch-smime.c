--- smime.c.orig	Sun Aug 14 14:33:37 2005
+++ smime.c	Thu Feb 16 08:49:37 2006
@@ -1989,7 +1989,6 @@
 
     if ((p = smime_ask_for_key (_("Sign as: "), NULL, 0))) 
     {
-      p[mutt_strlen (p)-1] = '\0';
       mutt_str_replace (&SmimeDefaultKey, p);
 	
       msg->security |= SIGN;
