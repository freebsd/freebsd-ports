--- ECB.pm.orig	Mon Dec 27 11:05:33 2004
+++ ECB.pm	Mon Dec 27 11:06:45 2004
@@ -274,7 +274,7 @@ sub finish (\$)
     $crypt->{Mode}   = '';
     $crypt->{buffer} = '';
 
-    return '' unless $data;
+    return '' unless defined($data) && length($data) > 0;
 
     my $cipher = $crypt->_getcipher;
 
