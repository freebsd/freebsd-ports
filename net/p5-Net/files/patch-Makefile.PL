--- Makefile.PL.orig	Sat May 19 15:56:18 2007
+++ Makefile.PL	Tue Jun 19 16:05:28 2007
@@ -98,6 +98,18 @@
 		IO::Socket => 1.05
 	      },
   dist => { DIST_DEFAULT => 'mydist', },
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
 
