--- qmail-remote.c.orig	2010-09-20 10:31:12.000000000 -0300
+++ qmail-remote.c	2010-09-20 10:32:12.000000000 -0300
@@ -507,6 +507,10 @@
     j = str_chr(smtptext.s+i+8,'L');		/* AUTH LOGIN */
     if (j > 0) 
       if (case_starts(smtptext.s+i+8+j,"LOGIN")) { mailfrom_login(); flagauth = 1; return; }
+    /* Deal with EHLO messages like "PLAIN LOGIN" in this order */
+    j = str_chr(smtptext.s+i+14,'L');		/* AUTH LOGIN */
+    if (j > 0)
+      if (case_starts(smtptext.s+i+14+j,"LOGIN")) { mailfrom_login(); flagauth = 1; return; }
     j = str_chr(smtptext.s+i+8,'P');		/* AUTH PLAIN */
     if (j > 0) 
       if (case_starts(smtptext.s+i+8+j,"PLAIN")) { mailfrom_plain(); flagauth = 2; return; }
