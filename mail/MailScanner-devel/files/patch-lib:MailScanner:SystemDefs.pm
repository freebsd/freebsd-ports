--- ../MailScanner-4.21-9.orig/lib/MailScanner/SystemDefs.pm	Sun Nov 10 16:02:15 2002
+++ lib/MailScanner/SystemDefs.pm	Thu Jun 12 15:29:39 2003
@@ -36,6 +36,6 @@
 $global::rm  = '/bin/rm';
 $global::cp  = '/bin/cp';
 $global::cat = '/bin/cat';
-$global::sed = '/bin/sed';
+$global::sed = '/usr/bin/sed';
 
 1;
