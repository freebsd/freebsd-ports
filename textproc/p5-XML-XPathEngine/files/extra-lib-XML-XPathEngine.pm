--- lib/XML/XPathEngine.pm.orig	Tue Aug  8 22:49:51 2006
+++ lib/XML/XPathEngine.pm	Tue Aug  8 22:50:29 2006
@@ -1,27 +1,10 @@
 package XML::XPathEngine;
 
-use warnings;
 use strict;
 
-use vars qw($VERSION $AUTOLOAD $revision);
-
 $VERSION = '0.03';
 $XML::XPathEngine::Namespaces = 0;
 $XML::XPathEngine::DEBUG = 0;
-
-use vars qw/
-        $NCName 
-        $QName 
-        $NCWild
-        $QNWild
-        $NUMBER_RE 
-        $NODE_TYPE 
-        $AXIS_NAME 
-        %AXES 
-        $LITERAL
-        $REGEXP_RE
-        $REGEXP_MOD_RE
-        %CACHE/;
 
 use XML::XPathEngine::Step;
 use XML::XPathEngine::Expr;
