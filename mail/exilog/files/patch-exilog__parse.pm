--- exilog_parse.pm.orig	2024-04-04 09:14:20 UTC
+++ exilog_parse.pm
@@ -260,7 +260,7 @@ sub parse_reject_line {
   # and one with message ID (post-DATA). Try the latter first.
 
   m/()()()()/;
-  $subj =~ m/(\d{4}-\d\d-\d\d) (\d\d:\d\d:\d\d( [-+]\d{4})?) ([A-Za-z0-9]{6}-[A-Za-z0-9]{6}-[A-Za-z0-9]{2}) (H=.*)$/;
+  $subj =~ m/(\d{4}-\d\d-\d\d) (\d\d:\d\d:\d\d( [-+]\d{4})?) ([A-Za-z0-9]{6}-[A-Za-z0-9]{6,11}-[A-Za-z0-9]{2,4}) (H=.*)$/;
   my ($date,$tod,$msgid,$line) = ($1,$2,$4,$5);
   if ($date && $tod && $msgid && $line) {
     # line with message id
@@ -297,7 +297,7 @@ sub parse_message_line {
   return 0 if ($subj =~ /retry time not reached for any host$/);
 
   # Grab date, time and message id
-  $subj =~ m/(\d{4}-\d\d-\d\d) (\d\d:\d\d:\d\d( [-+]\d{4})?) ([A-Za-z0-9]{6}-[A-Za-z0-9]{6}-[A-Za-z0-9]{2}) (([^ ]+).*)$/;
+  $subj =~ m/(\d{4}-\d\d-\d\d) (\d\d:\d\d:\d\d( [-+]\d{4})?) ([A-Za-z0-9]{6}-[A-Za-z0-9]{6,11}-[A-Za-z0-9]{2,4}) (([^ ]+).*)$/;
   my ($date,$tod,$msgid,$line,$type) = ($1,$2,$4,$5,$6);
   $line =~ s/^ +// if (defined($line));
   unless ($date && $tod && $msgid && $line && $type) {
