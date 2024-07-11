--- texk/texlive/linked_scripts/latexmk/latexmk.pl.orig	2024-02-01 21:05:56 UTC
+++ texk/texlive/linked_scripts/latexmk/latexmk.pl
@@ -1156,17 +1156,17 @@ else {
     #
     # The following works on Solaris, LINUX, HP-UX, IRIX
     # Use -f to get full listing, including command line arguments.
-    # Use -u $ENV{USER} to get all processes started by current user (not just
+    # Use -U $ENV{USER} to get all processes started by current user (not just
     #   those associated with current terminal), but none of other users' 
     #   processes. 
     # However, the USER environment variable may not exist.  Windows uses 
     #   USERNAME instead.  (And this propagates to a situation of 
     #   unix-emulation software running under Windows.) 
     if ( exists $ENV{USER} ) {
-       $pscmd = "ps -f -u $ENV{USER}"; 
+       $pscmd = "ps -f -U $ENV{USER}"; 
     }
     elsif ( exists $ENV{USERNAME} ) {
-       $pscmd = "ps -f -u $ENV{USERNAME}"; 
+       $pscmd = "ps -f -U $ENV{USERNAME}"; 
     }
     else {
        $pscmd = "ps -f"; 
@@ -1183,7 +1183,7 @@ else {
         # But (19 Aug 2010), the truncation doesn't happen on RHEL4 and 5,
         #    unless the output is written to a terminal.  So the --width 
         #    option is now unnecessary
-        # $pscmd = "ps --width 200 -f -u $ENV{USER}"; 
+        # $pscmd = "ps --width 200 -f -U $ENV{USER}"; 
     }
     elsif ( $^O eq "darwin" ) {
         # OS-X on Macintosh
@@ -1206,7 +1206,7 @@ else {
         $ps_previewer = $ps_previewer_landscape = 'NONE';
         # Others
         $lpr_pdf  = 'lpr %O %S';
-        $pscmd = "ps -ww -u $ENV{USER}"; 
+        $pscmd = "ps -ww -U $ENV{USER}"; 
     }
 }
 
