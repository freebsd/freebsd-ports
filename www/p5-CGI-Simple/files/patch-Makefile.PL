--- Makefile.PL.orig	Wed Nov 10 22:33:32 2004
+++ Makefile.PL	Wed Nov 10 22:33:38 2004
@@ -5,4 +5,10 @@
     'NAME'            => 'CGI::Simple',
     'VERSION_FROM'    => 'Simple.pm', # finds $VERSION
     'PREREQ_PM'       => {}, # e.g., Module::Name => 1.1
+    'MAN3PODS'        => {
+        'Simple.pm'           => '$(INST_MAN3DIR)/CGI::Simple.$(MAN3EXT)',
+        'Simple/Cookie.pm'    => '$(INST_MAN3DIR)/CGI::Simple::Cookie.$(MAN3EXT)',
+        'Simple/Standard.pm'  => '$(INST_MAN3DIR)/CGI::Simple::Standard.$(MAN3EXT)',
+        'Simple/Util.pm'      => '$(INST_MAN3DIR)/CGI::Simple::Util.$(MAN3EXT)',
+    },
 );
