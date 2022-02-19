--- texlive-20210325-source/texk/texlive/linked_scripts/texlive/tlmgr.pl.orig	2021-03-06 21:58:15 UTC
+++ texlive-20210325-source/texk/texlive/linked_scripts/texlive/tlmgr.pl
@@ -62,7 +62,7 @@ BEGIN {
   }
   if (-r "$bindir/$kpsewhichname") {
     # if not in bootstrapping mode => kpsewhich exists, so use it to get $Master
-    chomp($Master = `kpsewhich -var-value=SELFAUTOPARENT`);
+    chomp($Master = `kpsewhich -var-value=TEXMFROOT`);
   }
 
   # if we have no directory in which to find our modules,
@@ -631,13 +631,16 @@ for the full story.\n";
   # besides doing normal logging if -logfile is specified, we try to log
   # package related actions (install, remove, update) to
   # the package-log file TEXMFSYSVAR/web2c/tlmgr.log
+  #
+  # *** FreeBSD specific: FreeBSD port uses /var/db/tlpkg/tlmgr.log.
+  #
   $packagelogged = 0;  # how many msgs we logged
   chomp (my $texmfsysvar = `kpsewhich -var-value=TEXMFSYSVAR`);
   $packagelogfile = $opts{"package-logfile"};
   if ($opts{"usermode"}) {
     $packagelogfile ||= "$::maintree/web2c/tlmgr.log";
   } else {
-    $packagelogfile ||= "$texmfsysvar/web2c/tlmgr.log";
+    $packagelogfile ||= "/var/db/tlpkg/tlmgr.log";
   }
   #
   # Try to open the packagelog file, but do NOT die when that does not work
@@ -725,9 +728,9 @@ sub give_version {
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
@@ -2264,7 +2267,7 @@ sub write_w32_updater {
   my $opt_src = $localtlpdb->option("install_srcfiles");
   my $opt_doc = $localtlpdb->option("install_docfiles");
   my $root = $localtlpdb->root;
-  my $temp = "$root/temp";
+  my $temp = "$root/tlpkg/temp";
   TeXLive::TLUtils::mkdirhier($temp);
   tlwarn("$prg: Backup option not implemented for infrastructure update.\n") if ($opts{"backup"});
   if ($media eq 'local_uncompressed') {
@@ -5266,21 +5269,19 @@ sub uninstall_texlive {
   system("rm", "-rf", "$Master/texmf-var");
   system("rm", "-rf", "$Master/tlpkg");
   system("rm", "-rf", "$Master/bin");
-  system("rm", "-rf", "$Master/readme-html.dir");
-  system("rm", "-rf", "$Master/readme-txt.dir");
+  system("rm", "-rf", "$Master/tlpkg/readme-html.dir");
+  system("rm", "-rf", "$Master/tlpkg/readme-txt.dir");
   for my $f (qw/doc.html index.html install-tl 
                 LICENSE.CTAN LICENSE.TL README README.usergroups
                 release-texlive.txt texmf.cnf texmfcnf.lua/) {
-    system("rm", "-f", "$Master/$f");
+    system("rm", "-f", "$Master/tlpkg/$f");
   }
-  if (-d "$Master/temp") {
+  if (-d "$Master/tlpkg/temp") {
     finddepth(sub { rmdir; }, "$Master/temp");
   }
-  unlink("$Master/install-tl.log");
+  unlink("$Master/tlpkg/install-tl.log");
   # if they want removal, give them removal. Hopefully they know how to
   # regenerate any changed config files.
-  system("rm", "-rf", "$Master/texmf-config");
-  finddepth(sub { rmdir; }, "$Master");
   
   return -d "$Master";
 }
@@ -6183,7 +6184,7 @@ sub action_conf {
       $fn || ( $fn = "$TEXMFCONFIG/tlmgr/config" ) ;
       $cf = TeXLive::TLConfFile->new($fn, "#", "=");
     } elsif ($arg eq "texmf" || $arg eq "auxtrees") {
-      $fn || ( $fn = "$Master/texmf.cnf" ) ;
+      $fn || ( $fn = "$Master/tlpkg/texmf.cnf" ) ;
       $cf = TeXLive::TLConfFile->new($fn, "[%#]", "=");
     } elsif ($arg eq "updmap") {
       $fn || ( chomp ($fn = `kpsewhich updmap.cfg`) ) ;
