--- dkimap4/imap4misc.C.old	Sun Jun 17 23:27:06 2001
+++ dkimap4/imap4misc.C	Sun Jun 17 23:27:50 2001
@@ -212,7 +212,7 @@
 dboximap4t::dboximap4t():dboxpopt()
  {
   command_ok=logout=readonly=FALSE; 
-  protocol="imap4";
+  protocol="imap";
   mailbox="";
   messages=0;
   uidvalidity=1;
