--- Makefile.PL.orig	Mon Mar 25 08:47:50 2002
+++ Makefile.PL	Wed Apr  3 01:03:40 2002
@@ -4,10 +4,6 @@
 WriteMakefile(
     'NAME'		=> 'Spread::Session',
     'VERSION_FROM'	=> 'Session.pm', # finds $VERSION
-    'PREREQ_PM'		=> {
-			    Log::Channel => 0.4,
-			    Event => 0.85, # for test cases
-			   },
     ($] >= 5.005 ?    ## Add these new keywords supported since 5.005
       (ABSTRACT_FROM => 'Session.pm', # retrieve abstract from module
        AUTHOR     => 'Jason W. May <jmay@pobox.com>') : ()),
