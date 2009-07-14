--- ./lib/Gantry/Build.pm.orig	2009-07-14 17:44:09.567989717 -0400
+++ ./lib/Gantry/Build.pm	2009-07-14 17:44:24.917686676 -0400
@@ -115,8 +115,6 @@
 
     my $tmpl_dir = $p->{web_dir};
 
-    if( $tmpl_dir && $tmpl_dir ne '__skip__' ) {
-
         if ( not -d $tmpl_dir and $p->{ create_web_dir } =~ /^n/i ) {
             exit;
         }
@@ -145,10 +143,6 @@
         else {
             print "Web content copied: $num\n";
         }
-    }
-    else {
-        print "SKIPPING WEB CONTENT INSTALL\n";
-    }
     print "-" x 80;
     print "\n";
 
