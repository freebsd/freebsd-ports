--- w3http.pm.bak	Mon Feb  5 00:21:47 2001
+++ w3http.pm	Sun Apr 17 21:43:30 2005
@@ -551,13 +551,16 @@
       # found at cool sites.
       $save=1;
 
+      my($slash)=($saveto =~ /^\//);
       # Find a temporary filename
       $tmpf=url "file:$saveto";
       $tmpf->basename($tmpfile);
       $tmpf=$tmpf->unix_path;
+      $tmpf =~ s~^/~~ if (!$slash);
       
       # Find suitable final filename, one with no URL escapes
       $saveto=(url "file:$saveto")->unix_path;
+      $saveto =~ s~^/~~ if (!$slash);
 
       # If output to stdout then send it directly there rather than
       # using disk unnecesarily.
