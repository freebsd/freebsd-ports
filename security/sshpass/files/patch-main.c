--- main.c.orig	2011-08-06 07:04:33 UTC
+++ main.c
@@ -1,5 +1,5 @@
 /*  This file is part of "sshpass", a tool for batch running password ssh authentication
- *  Copyright (C) 2006 Lingnu Open Source Consulting Ltd.
+ *  Copyright (C) 2006, 2015 Lingnu Open Source Consulting Ltd.
  *
  *  This program is free software; you can redistribute it and/or modify
  *  it under the terms of the GNU General Public License as published by
@@ -69,6 +69,8 @@ struct {
 	int fd;
 	const char *password;
     } pwsrc;
+
+    const char *pwprompt;
 } args;
 
 static void show_help()
@@ -77,6 +79,7 @@ static void show_help()
 	    "   -f filename   Take password to use from file\n"
 	    "   -d number     Use number as file descriptor for getting password\n"
 	    "   -p password   Provide password as argument (security unwise)\n"
+            "   -P prompt     Which string should sshpass search for to detect a password prompt\n"
 	    "   -e            Password is passed as env-var \"SSHPASS\"\n"
 	    "   With no parameters - password will be taken from stdin\n\n"
 	    "   -h            Show help (this screen)\n"
@@ -99,7 +102,7 @@ static int parse_options( int argc, char
     fprintf(stderr, "Conflicting password source\n"); \
     error=RETURN_CONFLICTING_ARGUMENTS; }
 
-    while( (opt=getopt(argc, argv, "+f:d:p:heV"))!=-1 && error==-1 ) {
+    while( (opt=getopt(argc, argv, "+f:d:p:P:heV"))!=-1 && error==-1 ) {
 	switch( opt ) {
 	case 'f':
 	    // Password should come from a file
@@ -130,6 +133,9 @@ static int parse_options( int argc, char
                     optarg[i]='z';
             }
 	    break;
+        case 'P':
+            args.pwprompt=optarg;
+            break;
 	case 'e':
 	    VIRGIN_PWTYPE;
 
@@ -359,7 +365,7 @@ int handleoutput( int fd )
     // We are looking for the string
     static int prevmatch=0; // If the "password" prompt is repeated, we have the wrong password.
     static int state1, state2;
-    static const char compare1[]="assword:"; // Asking for a password
+    static const char *compare1=PASSWORD_PROMPT; // Asking for a password
     static const char compare2[]="The authenticity of host "; // Asks to authenticate host
     // static const char compare3[]="WARNING: REMOTE HOST IDENTIFICATION HAS CHANGED!"; // Warns about man in the middle attack
     // The remote identification changed error is sent to stderr, not the tty, so we do not handle it.
@@ -367,6 +373,10 @@ int handleoutput( int fd )
     char buffer[40];
     int ret=0;
 
+    if( args.pwprompt ) {
+        compare1 = args.pwprompt;
+    }
+
     int numread=read(fd, buffer, sizeof(buffer) );
 
     state1=match( compare1, buffer, numread, state1 );
