--- lib/Mail/SpamAssassin/PerMsgStatus.pm.bak	Thu Jan 24 05:39:15 2002
+++ lib/Mail/SpamAssassin/PerMsgStatus.pm	Tue Feb 26 19:08:32 2002
@@ -788,6 +788,8 @@
   if ($encoding =~ /^US-ASCII$/i
   	|| $encoding =~ /^ISO-8859-\d+$/i
   	|| $encoding =~ /^UTF-8$/i
+	|| $encoding =~ /^KOI8-\w$/i
+	|| $encoding =~ /^WINDOWS-125\d$/i
       )
   {
     # keep 8-bit stuff. forget mapping charsets though
