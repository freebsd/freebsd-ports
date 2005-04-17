--- w3mir.PL.orig	Mon Feb  5 00:21:47 2001
+++ w3mir.PL	Sun Apr 17 21:43:30 2005
@@ -648,8 +648,10 @@
   $rum_url_o = url $rum_url_o 
     unless ref $rum_url_o;
   
+  my($slash)=($lf_url =~ /^\//);
   # Derive a filename from the url, the filename contains no URL-quoting
   my($lf_name) = (url "file:$lf_url")->unix_path;
+  $lf_name =~ s~^/~~ if (!$slash);
 
   # Make all intermediate directories
   &mkdir($lf_name) if $s==0;
