--- Template.pm.orig	Sat Feb  2 08:01:37 2002
+++ Template.pm	Tue Mar 12 11:24:20 2002
@@ -863,7 +863,9 @@
 use strict; # and no funny business, either.
 
 use Carp; # generate better errors with more context
+BEGIN { unshift(@INC, "%%PERL_INC%%"); }
 use File::Spec; # generate paths that work on all platforms
+shift(@INC);
 
 # define accessor constants used to improve readability of array
 # accesses into "objects".  I used to use 'use constant' but that
@@ -2011,7 +2013,7 @@
 	push(@ifstack, $cond);
 	
       } elsif ($which eq '/TMPL_IF' or $which eq '/TMPL_UNLESS') {
-	$options->{debug} and print STDERR "### HTML::Template Debug ###$fname : line $fcounter : $which end\n";
+	$options->{debug} and print STDERR "### HTML::Template Debug ### $fname : line $fcounter : $which end\n";
 	
 	my $cond = pop(@ifstack);
 	die "HTML::Template->new() : found </${which}> with no matching <TMPL_IF> at $fname : line $fcounter." unless defined $cond;
