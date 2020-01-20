--- Makefile.PL.orig	2019-05-06 14:37:59 UTC
+++ Makefile.PL
@@ -12,11 +12,12 @@ use Symbol qw(gensym);
 # the Net-SSLeay loadable object on Windows
 my $win_link_statically = 0;
 
-my $tests = prompt(
-  "Do you want to run external tests?\n".
-  "These tests *will* *fail* if you do not have network connectivity.",
-  'n',
-) =~ /^y/i ? 't/*/*.t t/*/*/*.t' : 't/local/*.t t/handle/local/*.t';
+# my $tests = prompt(
+#   "Do you want to run external tests?\n".
+#   "These tests *will* *fail* if you do not have network connectivity.",
+#   'n',
+# ) =~ /^y/i ? 't/*/*.t t/*/*/*.t' : 't/local/*.t t/handle/local/*.t';
+my $tests = 't/local/*.t t/handle/local/*.t';
 
 my %eumm_args = (
   NAME => 'Net::SSLeay',
