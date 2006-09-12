--- webinject.pl.orig	Wed Jan  4 19:10:30 2006
+++ webinject.pl	Mon Sep  4 16:19:08 2006
@@ -1362,12 +1362,12 @@
 #------------------------------------------------------------------
 sub getdirname {  #get the directory webinject engine is running from
         
-    $dirname = $0;    
-    $dirname =~ s~(.*/).*~$1~;  #for nix systems
-    $dirname =~ s~(.*\\).*~$1~; #for windoz systems   
-    if ($dirname eq $0) { 
+#    $dirname = $0;    
+#    $dirname =~ s~(.*/).*~$1~;  #for nix systems
+#    $dirname =~ s~(.*\\).*~$1~; #for windoz systems   
+#    if ($dirname eq $0) { 
         $dirname = './'; 
-    }
+#    }
 }    
 #------------------------------------------------------------------
 sub getoptions {  #command line options
