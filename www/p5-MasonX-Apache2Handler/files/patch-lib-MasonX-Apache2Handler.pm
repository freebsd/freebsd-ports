--- lib/MasonX/Apache2Handler.pm	Thu Sep 23 17:26:41 2004
+++ lib/MasonX/Apache2Handler.pm	Thu Sep 23 17:26:54 2004
@@ -615,7 +615,7 @@
     if (exists $allowed_params->{data_dir} and not exists $params{data_dir})
     {
 	# constructs path to <server root>/mason
-	my $def = $defaults{data_dir} = Apache->server->server_root_relative('mason');
+	my $def = $defaults{data_dir} = File::Spec->catfile(Apache::ServerUtil::server_root(), 'mason');
 	param_error "Default data_dir (MasonDataDir) '$def' must be an absolute path"
 	    unless File::Spec->file_name_is_absolute($def);
 	  
