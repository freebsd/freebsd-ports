--- lib/Wiki/DefaultStorage.pm.orig	Sun Aug 22 13:49:52 2004
+++ lib/Wiki/DefaultStorage.pm	Mon Nov  8 12:56:44 2004
@@ -324,12 +324,12 @@
 	my $page = shift;
 	my $path = shift;
 	
-	if(defined($self->{exists_cache}->{"$path:$page"})){
+	if($self->{exists_cache} and defined($self->{exists_cache}->{"$path:$page"})){
 		return $self->{exists_cache}->{"$path:$page"};
 	}
 	
 	my $dir = $self->{wiki}->config('data_dir');
-	if($path ne ""){
+	if(defined $path and $path ne ""){
 		$dir = "$dir/$path";
 	}
 	
