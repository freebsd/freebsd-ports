--- ident2.c.orig	Wed Oct 15 05:45:40 2003
+++ ident2.c	Wed Oct 15 05:46:50 2003
@@ -75,8 +75,8 @@
 {
 	print_header();
 	puts(
-"	ident2 is free software, and you are welcome to redistribute it
-	under certain conditions; ident2 comes with ABSOLUTELY NO WARRANTY;
+"	ident2 is free software, and you are welcome to redistribute it \n\
+	under certain conditions; ident2 comes with ABSOLUTELY NO WARRANTY; \n\
 	for details, go to http://www.gnu.org/\n");
 }
 
@@ -86,53 +86,53 @@
 	print_header();
 #ifdef HAS_GETOPT_LONG
 	puts (  
-"usage: ident2 [options]
-options:
-
-these parameters apply to all incarnations of ident2
-
-	-h	--help			this command line information
-	-u	--usage			shows example command lines
-	-v	--version		show version information
-	-l	--license		show licensing information
-	-a	--force-inetd		force inetd mode
-	-d	--force-daemon		force standalone daemon
-	-i	--use-user-ident	allow user defined ident replies
-	-y	--user-reply-file	file in user's homedir for replies
-	-n	--allow-noident-file	don't reply if user has a ~/NOIDENT file
-	-o	--client-timeout	clients timeout after this many secs
-	-s	--dont-change-uid	don't try to change uid (to nobody)
-	-r	--always-random		always send a random reply
-	
-these parameters only apply to the daemon ident2
-
-	-m	--daemon-maxclients	accept no more than this many clients
-	-p	--daemon-port		bind this port, instead of 'auth'
+"usage: ident2 [options] \n\
+options: \n\
+ \n\
+these parameters apply to all incarnations of ident2 \n\
+\n\
+	-h	--help			this command line information\n\
+	-u	--usage			shows example command lines\n\
+	-v	--version		show version information\n\
+	-l	--license		show licensing information\n\
+	-a	--force-inetd		force inetd mode\n\
+	-d	--force-daemon		force standalone daemon\n\
+	-i	--use-user-ident	allow user defined ident replies\n\
+	-y	--user-reply-file	file in user's homedir for replies\n\
+	-n	--allow-noident-file	don't reply if user has a ~/NOIDENT file\n\
+	-o	--client-timeout	clients timeout after this many secs\n\
+	-s	--dont-change-uid	don't try to change uid (to nobody)\n\
+	-r	--always-random		always send a random reply\n\
+	\n\
+these parameters only apply to the daemon ident2\n\
+\n\
+	-m	--daemon-maxclients	accept no more than this many clients\n\
+	-p	--daemon-port		bind this port, instead of 'auth'\n\
 ");
 #else
 	puts(
-"usage: ident2 [options]
-options:
-
-these parameters apply to all incarnations of ident2
-
-	-h		this command line information
-	-u		shows example command lines
-	-v		show version information
-	-l		show licensing information
-	-a		force inetd mode
-	-d		force standalone daemon
-	-i		allow user defined ident replies
-	-y		file in user's homedir for replies
-	-n		don't reply if user has a ~/NOIDENT file
-	-o		clients timeout after this many secs
-	-s		don't try to change uid (ex: to nobody)
-	-r		always send a random reply, even to bad requests
-                      
-these parameters only apply to the daemon ident2
-
-	-m		accept no more than this many clients
-	-p		bind this port, instead of 'auth'
+"usage: ident2 [options]\n\
+options:\n\
+\n\
+these parameters apply to all incarnations of ident2\n\
+\n\
+	-h		this command line information\n\
+	-u		shows example command lines\n\
+	-v		show version information\n\
+	-l		show licensing information\n\
+	-a		force inetd mode\n\
+	-d		force standalone daemon\n\
+	-i		allow user defined ident replies\n\
+	-y		file in user's homedir for replies\n\
+	-n		don't reply if user has a ~/NOIDENT file\n\
+	-o		clients timeout after this many secs\n\
+	-s		don't try to change uid (ex: to nobody)\n\
+	-r		always send a random reply, even to bad requests\n\
+                      \n\
+these parameters only apply to the daemon ident2\n\
+\n\
+	-m		accept no more than this many clients\n\
+	-p		bind this port, instead of 'auth'\n\
 ");
 #endif                                                                                                                -p      --daemon-port           bind this port, instead of 'auth'
 }
