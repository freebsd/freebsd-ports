--- lib/Mail/SpamAssassin/Constants.pm.orig	Tue Aug 29 23:16:47 2006
+++ lib/Mail/SpamAssassin/Constants.pm	Fri Sep 29 10:49:46 2006
@@ -265,7 +265,7 @@
 
 # regular expression that matches message separators in The University of
 # Washington's MBX mailbox format
-use constant MBX_SEPARATOR => qr/([\s|\d]\d-[a-zA-Z]{3}-\d{4}\s\d{2}:\d{2}:\d{2}.*),(\d+);([\da-f]{12})-(\w{8})/;
+use constant MBX_SEPARATOR => qr/^([\s|\d]\d-[a-zA-Z]{3}-\d{4}\s\d{2}:\d{2}:\d{2}.*),(\d+);([\da-f]{12})-(\w{8})\r?$/;
 # $1 = datestamp (str)
 # $2 = size of message in bytes (int)
 # $3 = message status - binary (hex)
