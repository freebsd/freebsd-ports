--- capplets/default-applications/gnome-default-applications-properties-structs.c.orig	Mon Dec 13 22:37:25 2004
+++ capplets/default-applications/gnome-default-applications-properties-structs.c	Mon Dec 13 22:45:16 2004
@@ -9,11 +9,8 @@
         { N_("Epiphany"), 		"epiphany",	"epiphany %s",		FALSE, FALSE },
         { N_("Galeon"), 		"galeon",	"galeon %s",		FALSE, FALSE },
         { N_("Encompass"), 		"encompass",	"encompass %s",		FALSE, FALSE },
-        { N_("Firebird/FireFox"),  "mozilla-firebird",  "mozilla-firebird %s",  FALSE, FALSE },
-        { N_("Firebird/FireFox"),  "mozilla-firefox",	"mozilla-firebird %s",  FALSE, FALSE },
-        { N_("Firebird/FireFox"),  	"firefox",	"mozilla-firebird %s",	FALSE, FALSE },
-        { N_("Mozilla/Netscape 6"), 	"mozilla-1.6",	"mozilla-1.6 %s",	FALSE, FALSE },
-        { N_("Mozilla/Netscape 6"), 	"mozilla",	"mozilla %s",		FALSE, FALSE },
+        { N_("FireFox"),  		"firefox",	"firefox %s",		FALSE, FALSE },
+        { N_("Mozilla"), 		"mozilla",	"mozilla %s",		FALSE, FALSE },
         { N_("Netscape Communicator"), 	"netscape",	"netscape %s",		FALSE, FALSE },
         { N_("Konqueror"), 		"konqueror",	"konqueror %s",		FALSE, FALSE },
         { N_("W3M Text Browser"),	"w3n",		"w3m %s",		TRUE,  FALSE },
@@ -40,6 +37,7 @@
 	{ N_("Balsa"),        			"balsa",		"balsa -m %s",		FALSE, FALSE },
 	{ N_("KMail"),        			"kmail",		"kmail %s",		FALSE, FALSE },
 	{ N_("Mozilla Mail"), 			"mozilla",		"mozilla -mail %s",	FALSE, FALSE},
+	{ N_("Thunderbird"), 			"thunderbird",		"thunderbird %s",	FALSE, FALSE},
         { N_("Mutt") , 	  			"mutt",			"mutt %s",		TRUE,  FALSE },
 
 };
