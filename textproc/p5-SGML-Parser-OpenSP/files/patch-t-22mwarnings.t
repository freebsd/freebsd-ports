--- /dev/null  Fri Jul 27 20:05:08 2007
+++ t/22mwarnings.t    Fri Jul 27 20:06:59 2007
@@ -0,0 +1,67 @@
+# 10errors.t -- ...
+#
+# $Id: 22mwarnings.t,v 1.1 2006/11/07 11:14:13 hoehrmann Exp $
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
+#########################################################
+## Error reporting
+#########################################################
+
+sub TestHandler5::new         { bless{ok=>0},shift }
+sub TestHandler5::error
+{
+    return unless @_ == 2;
+    $_[0]->{ok}++ if $_[1]->{Message} =~ /:8:7:W:/;
+}
+
+my $h5 = TestHandler5->new;
+$p->catalogs(TEST_CATALOG);
+$p->warnings('xml');
+$p->handler($h5);
+lives_ok { $p->parse("<LITERAL>" . <<"__DOC__");
+<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN"
+    "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
+<html xmlns="http://www.w3.org/1999/xhtml">
+<head>
+<title></title>
+</head>
+<body>
+<p>foo & bar</p>
+</body>
+</html>
+__DOC__
+} 'ampersand as data';
+
+is($h5->{ok}, 1, 'ampersand as data generates warning');
+
+# special case
+$p->warnings(qw/non-sgml-char-ref valid no-duplicate xml/);
+
+lives_ok { $p->parse("<LITERAL>" . <<"__DOC__");
+<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN"
+    "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
+<html xmlns="http://www.w3.org/1999/xhtml">
+<head>
+<title></title>
+</head>
+<body>
+<p>foo & bar</p>
+</body>
+</html>
+__DOC__
+} 'ampersand as data';
+
+is($h5->{ok}, 2, 'ampersand as data generates warning');

