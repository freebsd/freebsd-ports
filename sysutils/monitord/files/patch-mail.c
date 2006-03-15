--- ./mail.c.orig	Thu Aug 21 15:44:20 2003
+++ ./mail.c	Wed Mar 15 11:09:01 2006
@@ -81,13 +81,13 @@
 	read (serversd, buf, _BUFSIZE);
 
 	// Set "MAIL FROM"
-	sprintf(buf, "MAIL FROM: monitord-notification@%s\n", thisname);
+	sprintf(buf, "MAIL FROM: <monitord-notification@%s>\n", thisname);
 	write(serversd, buf, strlen(buf));
 	read (serversd, buf, _BUFSIZE);
 
 	// set "RCPT TO"
 	bzero (buf, _BUFSIZE );
-	sprintf(buf, "RCPT TO: %s\n", address);
+	sprintf(buf, "RCPT TO: <%s>\n", address);
 	write(serversd, buf, strlen(buf));
 	read (serversd, buf, _BUFSIZE);
 
@@ -97,17 +97,17 @@
 	read (serversd, buf, _BUFSIZE);
 
 	// Set "FROM"
-	sprintf(buf, "FROM: monitord-notification@%s\n", thisname);
+	sprintf(buf, "From: <monitord-notification@%s>\n", thisname);
 	write(serversd, buf, strlen(buf));
 
 	// set "TO"
 	bzero (buf, _BUFSIZE );
-	sprintf(buf, "TO: %s\n", address);
+	sprintf(buf, "To: <%s>\n", address);
 	write(serversd, buf, strlen(buf));
 
 	// set "SUBJECT"
 	bzero (buf, _BUFSIZE );
-	sprintf(buf, "SUBJECT: %s\n", subject);
+	sprintf(buf, "Subject: %s\n", subject);
 	write(serversd, buf, strlen(buf));
 
 	// send actual data
