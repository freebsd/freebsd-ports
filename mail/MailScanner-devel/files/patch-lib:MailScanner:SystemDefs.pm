--- ../MailScanner-4.22-5.old/lib/MailScanner/SystemDefs.pm	Mon Aug 11 12:15:30 2003
+++ lib/MailScanner/SystemDefs.pm	Mon Aug 11 12:36:06 2003
@@ -36,6 +36,6 @@
 $global::rm  = '/bin/rm';
 $global::cp  = '/bin/cp';
 $global::cat = '/bin/cat';
-$global::sed = '/bin/sed';
+$global::sed = '/usr/bin/sed';
 
 1;
