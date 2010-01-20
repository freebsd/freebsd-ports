--- Captcha.pm.orig	2003-12-18 13:44:34.000000000 +0900
+++ Captcha.pm	2010-01-19 18:52:23.656183439 +0900
@@ -65,6 +65,7 @@
 	my $keep_failures = (defined($opts{keep_failures}) && $opts{keep_failures})
 	                    ? 1 : 0;
 	$self->keep_failures($keep_failures);
+	$self->secret($opts{secret} || "");
 	
 	# create a random seed if perl version less than 5.004
 	if ($] < 5.005)
@@ -193,6 +194,18 @@
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
@@ -214,7 +227,7 @@
 	# they could be confused with (o) and (l), so we swap them in
 	$code =~ tr/01/ol/;
 
-	my $md5 = md5_hex($code);
+	my $md5 = md5_hex($code . $self->secret);
 	
 	# pull in current database
 	warn "Open File: $database_file\n" if($self->debug() >= 2);
@@ -232,7 +245,7 @@
 	foreach my $line (@data) 
 	{
 		$line =~ s/\n//;
-		my ($data_time,$data_code) = split(/::/,$line);
+		my ($data_time,$data_code) = $line =~ m/(^\d+)::([[:xdigit:]]{32})$/;
 		
 		my $png_file = File::Spec->catfile($self->output_folder(),$data_code . ".png");
 		if ($data_code eq $crypt)
@@ -351,7 +364,7 @@
 	foreach my $line (@data) 
 	{
 		$line =~ s/\n//;
-		my ($data_time,$data_code) = split(/::/,$line);
+		my ($data_time,$data_code) = $line =~ m/(^\d+)::([[:xdigit:]]{32})$/;
 		if ( (($current_time - $data_time) > ($self->expire())) ||
 		     ($data_code  eq $md5) )
 		{	# remove expired captcha, or a dup
@@ -490,7 +503,7 @@
 	my $length = shift;
 
 	my $code = $self->generate_random_string($length);
-	my $md5 = md5_hex($code);
+	my $md5 = md5_hex($code . $self->secret);
 
 	my ($captcha_data_ref,$output_filename);
 	if ($self->type() eq 'image')
@@ -625,6 +638,7 @@
    height => 35, # optional. default 35
    images_folder => '/some/folder', # optional. default to lib dir
    keep_failures => 0, # optional, defaults to 0(false)
+   secret => "", # optional, defaults to ""
    debug => 0, # optional. default 0
 
 =back
@@ -695,6 +709,14 @@
 
 Optional. Defaults to zero. This option controls whether or not the captcha will remain valid after a failed attempt. By default, we only allow one attempt to solve it. This greatly reduces the possibility that a bot could brute force a correct answer. Change it at your own risk.
 
+=item C<$captcha-E<gt>secret( "SuperSecret" );>
+
+Optional. Defaults to an empty string. This option is meant to prevent
+brute-force captcha circumvention by calculating md5 sum of multiple
+valid codes and comparing them with the image file name. Obviously, the
+secret should be the same for creating and checking the captcha. It is a
+good idea to set it to something else than the default.
+
 =item C<$captcha-E<gt>debug( [0|1|2] );>
 
 Optional. 
