--- w3mfix.PL.bak	Mon Feb  5 00:21:47 2001
+++ w3mfix.PL	Sun Apr 17 21:56:24 2005
@@ -686,12 +686,15 @@
 
 	substr($lf_url,0,0)='./' unless substr($lf_url,0,1) eq '/';
 
+	my($slash)=($lf_url =~ /^\//);
 	$lf_url_o=url $lf_url;
 	my $tmp=$lf_url_o->clone;
 	$tmp->basename($indexname);
+	my($tpath)=$tmp->unix_path;
+	$tpath =~ s~^/~~ if (!$slash);
 
 	if ( $doindex && $lf_url_o->basename eq "" && 
-	     &stat($tmp->unix_path) eq 'f' &&
+	     &stat($tpath) eq 'f' &&
 	     !$htmlop::isdir{$key}) {
 	  $lf_url_o=$tmp;
 	  $il=1;
