--- Simple/Util.pm.orig	Wed Nov 10 21:57:52 2004
+++ Simple/Util.pm	Wed Nov 10 21:58:15 2004
@@ -338,18 +338,18 @@
 
 __END__
 
-=head2 NAME
+=head1 NAME
 
 CGI::Util - Internal utilities used by CGI::Simple module
 
-=head2 SYNOPSIS
+=head1 SYNOPSIS
 
     $escaped     = escapeHTML('In HTML you need to escape < > " and & chars');
     $unescaped   = unescapeHTML('&lt;&gt;&quot;&amp;');
     $url_encoded = escape($string);
     $decoded     = unescape($url_encoded);
 
-=head2 DESCRIPTION
+=head1 DESCRIPTION
 
 CGI::Simple::Util contains essentially non public subroutines used by
 CGI::Simple. There are HTML and URL escape and unescape routines that may
@@ -358,7 +358,7 @@
 An internal object is used to store a number of system specific details to
 enable the escape routines to be accurate.
 
-=head2 AUTHOR INFORMATION
+=head1 AUTHOR INFORMATION
 
 Original version copyright 1995-1998, Lincoln D. Stein.  All rights reserved.
 
@@ -369,7 +369,7 @@
 
 Address bug reports and comments to: jfreeman@tassie.net.au
 
-=head2 SEE ALSO
+=head1 SEE ALSO
 
 L<CGI::Simple>
 
