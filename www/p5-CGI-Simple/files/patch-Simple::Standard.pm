--- Simple/Standard.pm.orig	Wed Nov 10 21:58:55 2004
+++ Simple/Standard.pm	Wed Nov 10 21:59:28 2004
@@ -126,12 +126,12 @@
 
 1;
 
-=head2 NAME
+=head1 NAME
 
 CGI::Simple::Standard - a wrapper module for CGI::Simple that provides a
 function style interface
 
-=head2 SYNOPSIS
+=head1 SYNOPSIS
 
     use CGI::Simple::Standard qw( -autoload );
     use CGI::Simple::Standard qw( :core :cookie :header :misc );
@@ -210,13 +210,13 @@
 
     dienice( cgi_error() ) if cgi_error();
 
-=head2 DESCRIPTION
+=head1 DESCRIPTION
 
 This module is a wrapper for the completely object oriented CGI::Simple
 module and provides a simple functional style interface. It provides two
 different methods to import function names into your namespace.
 
-=head3 Autoloading
+=head2 Autoloading
 
 If you specify the '-autoload' pragma like this:
 
@@ -234,7 +234,7 @@
 (if it exists) to it. A fatal exception will be thrown if you try to use an
 undefined method (function).
 
-=head3 Specified Export
+=head2 Specified Export
 
 Alternatively you can specify the functions you wish to import. You can do
 this on a per function basis like this:
@@ -284,12 +284,12 @@
 
 Note that the function groups all start with a : char.
 
-=head3 Mix and Match
+=head2 Mix and Match
 
 You can use the '-autoload' pragma, specifically named function imports and
 tag group imports together if you desire.
 
-=head2 $POST_MAX and $DISABLE_UPLOADS
+=head1 $POST_MAX and $DISABLE_UPLOADS
 
 If you wish to set $POST_MAX or $DISABLE_UPLOADS you must do this *after* the
 use statement and *before* the first function call as shown in the synopsis.
@@ -307,7 +307,7 @@
 
     use CGI::Simple::Standard qw( -default ..... );
 
-=head2 EXPORT
+=head1 EXPORT
 
 Nothing by default.
 
@@ -321,7 +321,7 @@
 stub functions will be replaced with the real functions only if you actually
 call them saving wasted compilation effort.
 
-=head2 FUNCTION DETAILS
+=head1 FUNCTION DETAILS
 
 This is a wrapper module for CGI::Simple. Virtually all the methods available
 in the OO interface are available via the functional interface. Several
@@ -349,11 +349,11 @@
 For full details of the available functions see the CGI::Simple docs. Just
 remove the $q-> part and use the method name directly.
 
-=head2 BUGS
+=head1 BUGS
 
 As this is 0.01 there are almost bound to be some.
 
-=head2 AUTHOR
+=head1 AUTHOR
 
 Dr James Freeman E<lt>jfreeman@tassie.net.auE<gt>
 
@@ -361,12 +361,12 @@
 implied warranty. It may be used, redistributed and/or modified under the terms
 of the Perl Artistic License (see http://www.perl.com/perl/misc/Artistic.html)
 
-=head2 CREDITS
+=head1 CREDITS
 
 The interface and key sections of the CGI::Simple code come from
 CGI.pm by Lincoln Stein.
 
-=head2 SEE ALSO
+=head1 SEE ALSO
 
 L<CGI::Simple which is the back end for this module>,
 B<CGI.pm by Lincoln Stein>
