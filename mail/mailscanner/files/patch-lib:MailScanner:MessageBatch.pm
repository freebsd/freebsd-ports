--- ../MailScanner-4.29.7.orig/lib/MailScanner/MessageBatch.pm	Wed Apr 28 13:38:25 2004
+++ lib/MailScanner/MessageBatch.pm	Wed Apr 28 13:39:29 2004
@@ -472,6 +472,11 @@
         MailScanner::Config::LanguageValue($message, 'cantanalyze') . "\n";
       $message->{othertypes}{""}   .= 'e';
     }
+	 if ($message->{toomanyattach}) {
+      $message->{otherreports}{""} .=
+        MailScanner::Config::LanguageValue($message, 'toomanyattachments') . "\n";
+      $message->{othertypes}{""}   .= 'e';
+    }
     if ($message->{badtnef}) {
       $message->{entityreports}{$this->{tnefentity}} .=
         MailScanner::Config::LanguageValue($message, 'badtnef') . "\n";
