--- /dev/null  Fri Jul 27 20:05:08 2007
+++ t/20passfd.t       Fri Jul 27 20:06:50 2007
X@@ -0,0 +1,46 @@
+# 20passfd.t -- ...
+#
+# $Id: 20passfd.t,v 1.4 2005/08/14 18:07:19 hoehrmann Exp $
+
+use strict;
+use warnings;
+use Test::More tests => 7;
+use Test::Exception;
+use File::Spec qw();
+
+use constant NO_DOCTYPE   => File::Spec->catfile('samples', 'no-doctype.xml');
+use constant TEST_CATALOG => File::Spec->catfile('samples', 'test.soc');
+
+BEGIN { use_ok('SGML::Parser::OpenSP') };
+require_ok('SGML::Parser::OpenSP');
+my $p = SGML::Parser::OpenSP->new;
+isa_ok($p, 'SGML::Parser::OpenSP');
+
+sub TestHandler20::new { bless{ok1=>0},shift }
+sub TestHandler20::start_element { shift->{ok1}++ }
+
+sub TestHandler21::new { bless{ok1=>0},shift }
+sub TestHandler21::start_element { shift->{ok1}++ }
+
+#
+# Check pass as filename (should work on all platforms).
+$p = SGML::Parser::OpenSP->new;
+my $h1 = TestHandler20->new;
+$p->handler($h1);
+$p->pass_file_descriptor(0);
+lives_ok { $p->parse_string("<no-doctype></no-doctype>") } 'parse_string with temp file name';
+is($h1->{ok1}, 1, "temp file name handler called");
+undef $p;
+
+#
+# Check pass as file descriptor (not on Win32).
+SKIP: {
+  skip 'passing fds for temp files not supported on Win32', 2 if $^O eq 'MSWin32';
+  $p = SGML::Parser::OpenSP->new;
+  my $h2 = TestHandler21->new;
+  $p->handler($h2);
+  $p->pass_file_descriptor(1);
+  lives_ok { $p->parse_string("<no-doctype></no-doctype>") } 'parse by fd';
+  is($h2->{ok1}, 1, "temp file descriptor handler called");
+  undef $p;
+}

