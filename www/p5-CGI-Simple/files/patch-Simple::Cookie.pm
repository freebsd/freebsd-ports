--- Simple/Cookie.pm.orig	Wed Nov 10 21:56:28 2004
+++ Simple/Cookie.pm	Wed Nov 10 21:57:07 2004
@@ -142,11 +142,11 @@
 
 __END__
 
-=head2 NAME
+=head1 NAME
 
 CGI::Cookie - Interface to Netscape Cookies
 
-=head2 SYNOPSIS
+=head1 SYNOPSIS
 
     use CGI::Simple::Standard qw(header);
     use CGI::Simple::Cookie;
@@ -166,7 +166,7 @@
     # create cookies returned from an external source
     %cookies = parse CGI::Simple::Cookie($ENV{COOKIE});
 
-=head2 DESCRIPTION
+=head1 DESCRIPTION
 
 CGI::Simple::Cookie is an interface to Netscape (HTTP/1.1) cookies, an
 innovation that allows Web servers to store persistent information on
@@ -178,7 +178,7 @@
 
     http://www.ics.uci.edu/pub/ietf/http/rfc2109.txt
 
-=head2 USING CGI::Simple::Cookie
+=head1 USING CGI::Simple::Cookie
 
 CGI::Simple::Cookie is object oriented.  Each cookie object has a name
 and a value.  The name is any scalar value.  The value is any scalar or
@@ -228,7 +228,7 @@
 
 =back
 
-=head3 Creating New Cookies
+=head2 Creating New Cookies
 
     $c = new CGI::Simple::Cookie( -name    =>  'foo',
                                   -value   =>  'bar',
@@ -260,7 +260,7 @@
 B<-secure> if set to a true value instructs the browser to return the
 cookie only when a cryptographic protocol is in use.
 
-=head3 Sending the Cookie to the Browser
+=head2 Sending the Cookie to the Browser
 
 Within a CGI script you can send a cookie to the browser by creating
 one or more Set-Cookie: fields in the HTTP header.  Here is a typical
@@ -295,7 +295,7 @@
 
     print "Set-Cookie: ",$c->as_string,"\n";
 
-=head3 Recovering Previous Cookies
+=head2 Recovering Previous Cookies
 
     %cookies = fetch CGI::Simple::Cookie;
 
@@ -322,7 +322,7 @@
        $COOKIES = `cat /usr/tmp/Cookie_stash`;
        %cookies = parse CGI::Simple::Cookie($COOKIES);
 
-=head3 Manipulating Cookies
+=head2 Manipulating Cookies
 
 Cookie objects have a series of accessor methods to get and set cookie
 attributes.  Each accessor has a similar syntax.  Called without
@@ -365,7 +365,7 @@
 =back
 
 
-=head2 AUTHOR INFORMATION
+=head1 AUTHOR INFORMATION
 
 Original version copyright 1997-1998, Lincoln D. Stein.  All rights reserved.
 
@@ -376,11 +376,11 @@
 
 Address bug reports and comments to: jfreeman@tassie.net.au
 
-=head2 BUGS
+=head1 BUGS
 
 This section intentionally left blank :-)
 
-=head2 SEE ALSO
+=head1 SEE ALSO
 
 L<CGI::Carp>, L<CGI::Simple>
 
