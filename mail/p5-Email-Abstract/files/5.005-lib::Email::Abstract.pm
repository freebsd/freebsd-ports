--- lib/Email/Abstract.pm.orig	Mon Jul 26 20:32:24 2004
+++ lib/Email/Abstract.pm	Mon Jul 26 20:33:09 2004
@@ -1,10 +1,9 @@
 package Email::Abstract;
 use Carp;
 use Email::Simple;
-use 5.006;
 use strict;
 use warnings;
-our $VERSION = '1.0';
+use vars '$VERSION'; $VERSION = '1.0';
 use Module::Pluggable search_path => [ __PACKAGE__ ], require => 1;
 my @plugins = __PACKAGE__->plugins(); # Requires them.
 for my $func (qw(get_header get_body 
