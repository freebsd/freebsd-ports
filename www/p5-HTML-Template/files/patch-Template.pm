--- Template.pm.orig	Sat Feb  2 08:01:37 2002
+++ Template.pm	Thu May 30 12:33:34 2002
@@ -863,7 +863,9 @@
 use strict; # and no funny business, either.
 
 use Carp; # generate better errors with more context
+BEGIN { unshift(@INC, "%%PERL_INC%%"); }
 use File::Spec; # generate paths that work on all platforms
+shift(@INC);
 
 # define accessor constants used to improve readability of array
 # accesses into "objects".  I used to use 'use constant' but that
@@ -2011,10 +2013,10 @@
 	push(@ifstack, $cond);
 	
       } elsif ($which eq '/TMPL_IF' or $which eq '/TMPL_UNLESS') {
-	$options->{debug} and print STDERR "### HTML::Template Debug ###$fname : line $fcounter : $which end\n";
+	$options->{debug} and print STDERR "### HTML::Template Debug ### $fname : line $fcounter : $which end\n";
 	
 	my $cond = pop(@ifstack);
-	die "HTML::Template->new() : found </${which}> with no matching <TMPL_IF> at $fname : line $fcounter." unless defined $cond;
+	die "HTML::Template->new() : found <${which}> with no matching <TMPL_IF> at $fname : line $fcounter." unless defined $cond;
 	if ($which eq '/TMPL_IF') {
 	  die "HTML::Template->new() : found </TMPL_IF> incorrectly terminating a <TMPL_UNLESS> (use </TMPL_UNLESS>) at $fname : line $fcounter.\n" 
 	    if ($cond->[HTML::Template::COND::WHICH] == HTML::Template::COND::WHICH_UNLESS);
