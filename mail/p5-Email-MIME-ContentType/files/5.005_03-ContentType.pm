--- ContentType.pm.orig	Sun Aug 29 15:11:25 2004
+++ ContentType.pm	Sun Aug 29 15:11:51 2004
@@ -1,11 +1,11 @@
 package Email::MIME::ContentType;
-require 5.006;
 use base 'Exporter';
-our @EXPORT = qw(parse_content_type);
+use vars qw(@EXPORT $VERSION);
+@EXPORT = qw(parse_content_type);
 use strict;
 use Carp;
 use warnings;
-our $VERSION = '1.0';
+$VERSION = '1.0';
 
 my $tspecials = quotemeta '()<>@,;:\\"/[]?=';
 my $ct_default = 'text/plain; charset=us-ascii';
