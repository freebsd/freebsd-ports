--- Makefile.PL	Wed Aug 20 17:07:25 2003
+++ Makefile.PL~	Wed Aug 20 17:07:16 2003
@@ -98,6 +98,18 @@
 		Socket     => 1.3,
 		IO::Socket => 1.05
 	      },
+  'MAN3PODS'  => {
+    'Net/Cmd.pm' => '$(INST_MAN3DIR)/Net::Cmd.$(MAN3EXT)',
+    'Net/Config.pm' => '$(INST_MAN3DIR)/Net::Config.$(MAN3EXT)',
+    'Net/Domain.pm' => '$(INST_MAN3DIR)/Net::Domain.$(MAN3EXT)',
+    'Net/FTP.pm' => '$(INST_MAN3DIR)/Net::FTP.$(MAN3EXT)',
+    'Net/NNTP.pm' => '$(INST_MAN3DIR)/Net::NNTP.$(MAN3EXT)',
+    'Net/Netrc.pm' => '$(INST_MAN3DIR)/Net::Netrc.$(MAN3EXT)',
+    'Net/POP3.pm' => '$(INST_MAN3DIR)/Net::POP3.$(MAN3EXT)',
+    'Net/SMTP.pm' => '$(INST_MAN3DIR)/Net::SMTP.$(MAN3EXT)',
+    'Net/Time.pm' => '$(INST_MAN3DIR)/Net::Time.$(MAN3EXT)',
+    'Net/libnetFAQ.pod' => '$(INST_MAN3DIR)/Net::libnetFAQ.$(MAN3EXT)',
+  },
   @ppd,
 );
 
