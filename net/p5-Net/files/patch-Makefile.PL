--- Makefile.PL.orig	2007-08-26 08:14:13.000000000 -0400
+++ Makefile.PL	2012-04-25 14:43:48.565212760 -0400
@@ -47,7 +47,7 @@
   last if ($config_pm = $_) =~ s/^ExtUtils(.)MakeMaker.pm/Net${1}libnet.cfg/;
  }
 
- system(($^O eq 'VMS' ? 'mcr ': ()),$^X, 'Configure')
+ system(($^O eq 'VMS' ? 'mcr ': ()),$^X, 'Configure','-d')
 	unless -f $libnet_cfg;
 
  $self->{PM}->{$libnet_cfg} = $self->catfile('$(INST_LIBDIR)',$config_pm);
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
 
