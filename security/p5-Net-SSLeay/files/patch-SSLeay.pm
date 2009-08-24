--- inc/Module/Install/PRIVATE/Net/SSLeay.pm.orig	2009-08-24 12:42:03.000000000 +0000
+++ inc/Module/Install/PRIVATE/Net/SSLeay.pm	2009-08-24 12:42:58.000000000 +0000
@@ -45,7 +45,7 @@
 
     $self->makemaker_args( CCCDLFLAGS => $opts->{cccdlflags} );
 
-    if ( $self->prompt(
+    if ( 0 && $self->prompt( #don't require interaction during install
             "Do you want to run external tests?\n".
             "These tests *will* *fail* if you do not have network connectivity.",
             'n',
