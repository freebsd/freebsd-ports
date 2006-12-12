--- webmail/newmsg.c.orig	Sun Jul 30 21:01:42 2006
+++ webmail/newmsg.c	Sat Dec  9 22:27:06 2006
@@ -630,13 +630,14 @@
 	printf("<table width=\"100%%\" border=\"0\" cellspacing=\"0\" cellpadding=\"4\" class=\"new-message-box\"><tr><td>\n");
 
 	printf("<table border=\"0\" width=\"100%%\">\n");
+{
 	int wbnochangingfrom=auth_getoptionenvint("wbnochangingfrom");
 	if (wbnochangingfrom < 2)
 		newmsg_header_rfc822(fromlab, "headerfrom", curfrom,
 			*cgi("from") ? cgi("from"):
 			pref_from && *pref_from ? pref_from:
 			login_fromhdr(), wbnochangingfrom ? 1:0);
-
+}
 	printf("<tr valign=\"middle\"><th align=\"right\">"
 	       "<p class=\"new-message-header\">"
 	       "<span class=\"new-message-header-addressbook\">"
