--- texlive-20240312-source/texk/texlive/linked_scripts/texlive/tlmgr.pl.orig	2024-05-11 00:46:18 UTC
+++ texlive-20240312-source/texk/texlive/linked_scripts/texlive/tlmgr.pl
@@ -644,6 +644,9 @@ for the full story.\n";
   # besides doing normal logging if -logfile is specified, we try to log
   # package related actions (install, remove, update) to
   # the package-log file TEXMFSYSVAR/web2c/tlmgr.log
+  #
+  # *** FreeBSD specific: FreeBSD port uses /var/db/tlpkg/tlmgr.log.
+  #
   $packagelogged = 0;  # how many msgs we logged
   $commandslogged = 0;
   chomp (my $texmfsysvar = `kpsewhich -var-value=TEXMFSYSVAR`);
@@ -652,7 +655,7 @@ for the full story.\n";
   if ($opts{"usermode"}) {
     $packagelogfile ||= "$texmfvar/web2c/tlmgr.log";
   } else {
-    $packagelogfile ||= "$texmfsysvar/web2c/tlmgr.log";
+    $packagelogfile ||= "/var/db/tlpkg/tlmgr.log";
   }
   #
   # Try to open the packagelog file, but do NOT die when that does not work
@@ -744,9 +747,9 @@ sub give_version {
     $::mrversion = "";
     $::version_string .= "tlmgr revision $tlmgrversion\n";
     $::mrversion .= "revision $tlmgrrevision\n";
-    $::version_string .= "tlmgr using installation: $Master\n";
-    $::mrversion .= "installation $Master\n";
-    if (open (REL_TL, "$Master/release-texlive.txt")) {
+    $::version_string .= "tlmgr using installation: $Master/tlpkg\n";
+    $::mrversion .= "installation $Master/tlpkg\n";
+    if (open (REL_TL, "$Master/tlpkg/release-texlive.txt")) {
       # print first, which has the TL version info.
       my $rel_tl = <REL_TL>;
       $::version_string .= $rel_tl;
@@ -2409,7 +2412,7 @@ sub write_w32_updater {
   my $opt_src = $localtlpdb->option("install_srcfiles");
   my $opt_doc = $localtlpdb->option("install_docfiles");
   my $root = $localtlpdb->root;
-  my $temp = "$root/temp";
+  my $temp = "$root/tlpkg/temp";
   TeXLive::TLUtils::mkdirhier($temp);
   tlwarn("$prg: warning: backup option not implemented for infrastructure "
          . " update on Windows; continuing anyway.\n") 
@@ -5449,15 +5452,14 @@ sub uninstall_texlive {
   system("rm", "-rf", "$texmfsysvar");
 
   print "misc... ";
-  system("rm", "-rf", "$Master/readme-html.dir");
-  system("rm", "-rf", "$Master/readme-txt.dir");
+  system("rm", "-rf", "$Master/tlpkg/readme-html.dir");
+  system("rm", "-rf", "$Master/tlpkg/readme-txt.dir");
   for my $f (qw/doc.html index.html install-tl install-tl.log
                 LICENSE.CTAN LICENSE.TL README README.usergroups
                 release-texlive.txt texmf.cnf texmfcnf.lua
                /) {
-    system("rm", "-f", "$Master/$f");
+    system("rm", "-f", "$Master/tlpkg/$f");
   }
-  finddepth(sub { rmdir; }, $Master);
   rmdir($Master);
   print "done.\n";
   
@@ -6397,7 +6399,7 @@ sub action_conf {
       $fn || ( $fn = "$TEXMFCONFIG/tlmgr/config" ) ;
       $cf = TeXLive::TLConfFile->new($fn, "#", "=");
     } elsif ($arg eq "texmf" || $arg eq "auxtrees") {
-      $fn || ( $fn = "$Master/texmf.cnf" ) ;
+      $fn || ( $fn = "$Master/tlpkg/texmf.cnf" ) ;
       $cf = TeXLive::TLConfFile->new($fn, "[%#]", "=");
     } elsif ($arg eq "updmap") {
       $fn || ( chomp ($fn = `kpsewhich updmap.cfg`) ) ;
