--- Captcha.pm.orig	Mon May 10 10:58:05 2004
+++ Captcha.pm	Mon May 10 11:06:24 2004
@@ -65,6 +65,7 @@ sub new
 	my $keep_failures = (defined($opts{keep_failures}) && $opts{keep_failures})
 	                    ? 1 : 0;
 	$self->keep_failures($keep_failures);
+	$self->secret($opts{secret} || "");
 	
 	# create a random seed if perl version less than 5.004
 	if ($] < 5.005)
@@ -193,6 +194,18 @@ sub data_folder
    }
 }
 
+sub secret
+{
+   ref(my $self = shift) or croak "instance variable needed";
+   if (@_)
+   {   # it's a setter
+       $self->{_secret} = $_[0];
+       return $self->{_secret};
+   } else {
+       return $self->{_secret};
+   }
+}
+
 
 sub check_code 
 {
@@ -214,7 +227,7 @@ sub check_code 
 	# they could be confused with (o) and (l), so we swap them in
 	$code =~ tr/01/ol/;
 
-	my $md5 = md5_hex($code);
+	my $md5 = md5_hex($code . $self->secret);
 	
 	# pull in current database
 	warn "Open File: $database_file\n" if($self->debug() >= 2);
@@ -490,7 +503,7 @@ sub generate_code 
 	my $length = shift;
 
 	my $code = $self->generate_random_string($length);
-	my $md5 = md5_hex($code);
+	my $md5 = md5_hex($code . $self->secret);
 
 	my ($captcha_data_ref,$output_filename);
 	if ($self->type() eq 'image')
@@ -625,6 +638,7 @@ See the method descriptions for more det
    height => 35, # optional. default 35
    images_folder => '/some/folder', # optional. default to lib dir
    keep_failures => 0, # optional, defaults to 0(false)
+   secret => "", # optional, defaults to ""
    debug => 0, # optional. default 0
 
 =back
@@ -694,6 +708,14 @@ Optional. Number of pixels wide for the 
 =item C<$captcha-E<gt>keep_failures( [0|1] );>
 
 Optional. Defaults to zero. This option controls whether or not the captcha will remain valid after a failed attempt. By default, we only allow one attempt to solve it. This greatly reduces the possibility that a bot could brute force a correct answer. Change it at your own risk.
+
+=item C<$captcha-E<gt>secret( "SuperSecret" );>
+
+Optional. Defaults to an empty string. This option is meant to prevent
+brute-force captcha circumvention by calculating md5 sum of multiple
+valid codes and comparing them with the image file name. Obviously, the
+secret should be the same for creating and checking the captcha. It is a
+good idea to set it to something else than the default.
 
 =item C<$captcha-E<gt>debug( [0|1|2] );>
 
