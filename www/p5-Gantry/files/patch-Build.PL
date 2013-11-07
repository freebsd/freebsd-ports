--- Build.PL.orig	2010-01-14 01:33:31.000000000 +0800
+++ Build.PL	2013-11-07 20:14:30.000000000 +0800
@@ -107,27 +107,6 @@ if (! $template_path) {
 
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
@@ -151,14 +130,13 @@ sub _custom_code {
 
         my $install_base = $self->install_destination('lib') 
             || $p->{install_sets}{site}{lib};
-        
-        my $initf = "$install_base/$p->{dist_name}/Init.pm";
+        my $destdir = $self->destdir;
+        my $initf = "$destdir$install_base/$p->{dist_name}/Init.pm";
                 
         $self->SUPER::ACTION_install();
 
         my $tmpl_dir = $self->notes( 'install_web_directory' );
             
-        if( $tmpl_dir && $tmpl_dir ne '__skip__' ) {
 
             # write Init.pm file with install options
 
@@ -236,10 +214,6 @@ EO_INIT
             else {
                 print "\n$num Gantry templates copied to $tmpl_dir\n";
             }
-        }
-        else {
-            print "SKIPPING WEB CONTENT INSTALL\n";
-        }
         
         print "\n";
 
