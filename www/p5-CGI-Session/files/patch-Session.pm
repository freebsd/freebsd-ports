--- Session.pm.orig	Wed Jun 12 11:56:43 2002
+++ Session.pm	Wed Jun 12 12:04:39 2002
@@ -915,7 +915,7 @@
 =head2 STANDARD INSTALLATION
 
 The library is installed with just like other Perl libraries, or via CPAN interactive
-shell (Perl -MCPAN -e install CGI::Session).
+shell (Perl -MCPAN C<-e> install CGI::Session).
 
 Installation can also be done by following below instructions:
 
@@ -1117,7 +1117,7 @@
 above example. So, how do we "mark" the user? There are several ways of
 "marking".
 
-=head3 IDENTIFYING THE USER VIA CGI QUERY
+=item IDENTIFYING THE USER VIA CGI QUERY
 
 One way of doing it is to append the session id to every single link in the
 web site:
@@ -1167,7 +1167,7 @@
 session id appended to them. Too bad, because the client has to start
 everything over again.
 
-=head3 INDENTIFYING THE USER VIA COOKIES
+=item INDENTIFYING THE USER VIA COOKIES
 
 We can deal with the above problem by sending the client a cookie. This cookie
 will hold the session id only! Thus if the client visits some other site, or
@@ -1211,7 +1211,7 @@
 the C<sid> parameter in the URL, and if that fails, then it will default to
 undef, which will force C<CGI::Session> to create a new id for the client.
 
-=head3 IDENTIFYING THE USER VIA PATH_INFO
+=item IDENTIFYING THE USER VIA PATH_INFO
 
 The least common, but at the same time quite convenient way of C<marking> users
 with a session id is appending the session id to the url of the script
@@ -1363,7 +1363,7 @@
 
 =back
 
-=head3 SPECIAL NAMES
+=item SPECIAL NAMES
 
 When you create a fresh-blank session, it's not blank as it seems. It is
 initialized with the following 4 parameters, which are serialized together
