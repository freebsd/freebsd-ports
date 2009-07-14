--- ./Build.PL.orig	2009-07-14 17:08:45.608765850 -0400
+++ ./Build.PL	2009-07-14 17:40:19.239457739 -0400
@@ -106,27 +106,6 @@
 
 $build->notes( install_web_directory => $template_path );
 
-if ( not -d $template_path ) {
-    my $make_path = $ENV{'GANTRY_TEMPLATE_PATH'} || $build->y_n(
-        "$template_path does not exist, should I make it?",
-        'y'
-    );
-
-    if ( $make_path ) {
-        eval {  
-            File::Path::mkpath( $template_path );
-        };
-        if ( $@ ) {
-            $@ =~ s/ at .+?$//;
-            print "Error: unable to create directory $template_path @_\n";
-            $build->notes( install_web_directory => '__skip__' );
-        }
-    }
-    else {
-        $build->notes( install_web_directory => '__skip__' );
-    }
-}
-
 $build->create_build_script;
 
 sub _custom_code {
@@ -157,7 +136,6 @@
 
         my $tmpl_dir = $self->notes( 'install_web_directory' );
             
-        if( $tmpl_dir && $tmpl_dir ne '__skip__' ) {
 
             # write Init.pm file with install options
 
@@ -235,10 +213,6 @@
             else {
                 print "\n$num Gantry templates copied to $tmpl_dir\n";
             }
-        }
-        else {
-            print "SKIPPING WEB CONTENT INSTALL\n";
-        }
         
         print "\n";
 
