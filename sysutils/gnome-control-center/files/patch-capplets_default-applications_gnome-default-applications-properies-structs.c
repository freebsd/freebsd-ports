--- capplets/default-applications/gnome-default-applications-properties-structs.c.orig	Sun Feb 20 16:18:03 2005
+++ capplets/default-applications/gnome-default-applications-properties-structs.c	Mon Feb 21 15:52:04 2005
@@ -12,6 +12,7 @@
         { N_("Firebird/FireFox"),  "mozilla-firebird",  "mozilla-firebird %s",  FALSE, FALSE },
         { N_("Firebird/FireFox"),  "mozilla-firefox",	"mozilla-firebird %s",  FALSE, FALSE },
         { N_("Firebird/FireFox"),  	"firefox",	"mozilla-firefox %s",	FALSE, FALSE },
+        { N_("Firebird/FireFox"),  	"firefox",	"firefox %s",	FALSE, FALSE },
         { N_("Mozilla/Netscape 6"), 	"mozilla-1.6",	"mozilla-1.6 %s",	FALSE, FALSE },
         { N_("Mozilla/Netscape 6"), 	"mozilla",	"mozilla %s",		FALSE, FALSE },
         { N_("Netscape Communicator"), 	"netscape",	"netscape %s",		FALSE, FALSE },
@@ -40,6 +41,7 @@
 	{ N_("Balsa"),        			"balsa",		"balsa -m %s",		FALSE, FALSE },
 	{ N_("KMail"),        			"kmail",		"kmail %s",		FALSE, FALSE },
 	{ N_("Mozilla Mail"), 			"mozilla",		"mozilla -mail %s",	FALSE, FALSE},
+	{ N_("Thunderbird"), 			"thunderbird",		"thunderbird %s",	FALSE, FALSE},
         { N_("Mutt") , 	  			"mutt",			"mutt %s",		TRUE,  FALSE },
 
 };
