--- main.c.orig	2011-08-06 15:04:33.000000000 +0800
+++ main.c	2016-01-30 22:17:43.489015000 +0800
@@ -1,5 +1,5 @@
 /*  This file is part of "sshpass", a tool for batch running password ssh authentication
- *  Copyright (C) 2006 Lingnu Open Source Consulting Ltd.
+ *  Copyright (C) 2006, 2015 Lingnu Open Source Consulting Ltd.
  *
  *  This program is free software; you can redistribute it and/or modify
  *  it under the terms of the GNU General Public License as published by
@@ -69,6 +69,8 @@
 	int fd;
 	const char *password;
     } pwsrc;
+
+    const char *pwprompt;
 } args;
 
 static void show_help()
@@ -77,6 +79,7 @@
 	    "   -f filename   Take password to use from file\n"
 	    "   -d number     Use number as file descriptor for getting password\n"
 	    "   -p password   Provide password as argument (security unwise)\n"
+            "   -P prompt     Which string should sshpass search for to detect a password prompt\n"
 	    "   -e            Password is passed as env-var \"SSHPASS\"\n"
 	    "   With no parameters - password will be taken from stdin\n\n"
 	    "   -h            Show help (this screen)\n"
@@ -99,7 +102,7 @@
     fprintf(stderr, "Conflicting password source\n"); \
     error=RETURN_CONFLICTING_ARGUMENTS; }
 
-    while( (opt=getopt(argc, argv, "+f:d:p:heV"))!=-1 && error==-1 ) {
+    while( (opt=getopt(argc, argv, "+f:d:p:P:heV"))!=-1 && error==-1 ) {
 	switch( opt ) {
 	case 'f':
 	    // Password should come from a file
@@ -130,6 +133,9 @@
                     optarg[i]='z';
             }
 	    break;
+        case 'P':
+            args.pwprompt=optarg;
+            break;
 	case 'e':
 	    VIRGIN_PWTYPE;
 
@@ -265,6 +271,12 @@
 	setsid();
         // This line makes the ptty our controlling tty. We do not otherwise need it open
         slavept=open(name, O_RDWR );
+#ifdef __FreeBSD__
+	if (ioctl(slavept, TIOCSCTTY, NULL) == -1) {
+	    perror("sshpass: Failed to TIOCSCTTY");
+	    exit(RETURN_RUNTIME_ERROR);
+	}
+#endif
         close( slavept );
 	
 	close( masterpt );
@@ -359,7 +371,7 @@
     // We are looking for the string
     static int prevmatch=0; // If the "password" prompt is repeated, we have the wrong password.
     static int state1, state2;
-    static const char compare1[]="assword:"; // Asking for a password
+    static const char *compare1=PASSWORD_PROMPT; // Asking for a password
     static const char compare2[]="The authenticity of host "; // Asks to authenticate host
     // static const char compare3[]="WARNING: REMOTE HOST IDENTIFICATION HAS CHANGED!"; // Warns about man in the middle attack
     // The remote identification changed error is sent to stderr, not the tty, so we do not handle it.
@@ -367,6 +379,10 @@
     char buffer[40];
     int ret=0;
 
+    if( args.pwprompt ) {
+        compare1 = args.pwprompt;
+    }
+
     int numread=read(fd, buffer, sizeof(buffer) );
 
     state1=match( compare1, buffer, numread, state1 );
