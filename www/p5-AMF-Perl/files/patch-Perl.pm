--- lib/AMF/Perl.pm.orig	Tue Jun 29 15:39:46 2004
+++ lib/AMF/Perl.pm	Tue Jun 29 15:41:17 2004
@@ -103,18 +103,23 @@
     John Cowen - datatype io additions, class structure
     Klaasjan Tukker - modifications, check routines, and register-framework
 
-==head1 CHANGES
+=head1 CHANGES
+
 =head2 Thu Apr 29 17:20:07 EDT 2004
+
 =item Changed "use Apache2" to "require Apache2" to avoid breaking on non-modperl systems.
 
 =head2 Sat Apr 24 20:41:10 EDT 2004
+
 =item Another patch from Kostas Chatzikokolakis fixing MP2 issues.
 
 =head2 Sat Mar 13 16:25:00 EST 2004
 
 =item Patch from Kostas Chatzikokolakis handling encoding.
+
 =item Changed non-mod_perl behavior for reading POST data from using <> to using read()
 to work around a bug in IIS
+
 =item Joined code for mod_perl 1 and 2. Separated the output code for the mod_perl and non-mod_perl
 cases.
 
