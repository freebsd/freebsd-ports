--- mail.c.orig	2003-08-21 18:44:20 UTC
+++ mail.c
@@ -47,11 +47,11 @@ int mail ( char *address, char *eserver, char *subject
 	username = (char *) malloc ( (size_t) _BUFSIZE ); // init the username buffer
 	hostname = (char *) malloc ( (size_t) _BUFSIZE ); // init the hostname buffer
 	thisname = (char *) malloc ( (size_t) _BUFSIZE ); // init the hostname buffer
-	bzero (buf, sizeof (buf) );
-	bzero (token, sizeof (token) );
-	bzero (username, sizeof (username) );
-	bzero (hostname, sizeof (hostname) );
-	bzero (thisname, sizeof (thisname) );
+	bzero (buf, sizeof (*buf) );
+	bzero (token, sizeof (*token) );
+	bzero (username, sizeof (*username) );
+	bzero (hostname, sizeof (*hostname) );
+	bzero (thisname, sizeof (*thisname) );
 
 	strncpy (buf, address, _BUFSIZE);
 	username = strtok (buf, "@");
@@ -81,13 +81,13 @@ int mail ( char *address, char *eserver, char *subject
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
 
@@ -97,17 +97,17 @@ int mail ( char *address, char *eserver, char *subject
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
