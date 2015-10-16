--- texlive-20150521-source/texk/texlive/linked_scripts/texlive/tlmgr.pl.orig	2015-05-11 21:37:36 UTC
+++ texlive-20150521-source/texk/texlive/linked_scripts/texlive/tlmgr.pl
@@ -72,7 +72,7 @@ BEGIN {
   }
   if (-r "$bindir/$kpsewhichname") {
     # if not in bootstrapping mode => kpsewhich exists, so use it to get $Master
-    chomp($Master = `kpsewhich -var-value=SELFAUTOPARENT`);
+    chomp($Master = `kpsewhich -var-value=TEXMFROOT`);
   }
   $::installerdir = $Master;
 
@@ -581,13 +581,16 @@ for the full story.\n";
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
@@ -650,8 +653,8 @@ sub give_version {
   if (!defined($::version_string)) {
     $::version_string = "";
     $::version_string .= "tlmgr revision $tlmgrrevision\n";
-    $::version_string .= "tlmgr using installation: $Master\n";
-    if (open (REL_TL, "$Master/release-texlive.txt")) {
+    $::version_string .= "tlmgr using installation: $Master/tlpkg\n";
+    if (open (REL_TL, "$Master/tlpkg/release-texlive.txt")) {
       # print first and last lines, which have the TL version info.
       my @rel_tl = <REL_TL>;
       $::version_string .= $rel_tl[0];
@@ -2085,7 +2088,7 @@ sub write_w32_updater {
   my $opt_src = $localtlpdb->option("install_srcfiles");
   my $opt_doc = $localtlpdb->option("install_docfiles");
   my $root = $localtlpdb->root;
-  my $temp = "$root/temp";
+  my $temp = "$root/tlpkg/temp";
   TeXLive::TLUtils::mkdirhier($temp);
   tlwarn("Backup option not implemented for infrastructure update.\n") if ($opts{"backup"});
   if ($media eq 'local_uncompressed') {
@@ -4663,19 +4666,19 @@ sub action_uninstall {
   system("rm", "-rf", "$Master/texmf-var");
   system("rm", "-rf", "$Master/tlpkg");
   system("rm", "-rf", "$Master/bin");
-  system("rm", "-rf", "$Master/readme-html.dir");
-  system("rm", "-rf", "$Master/readme-txt.dir");
+  system("rm", "-rf", "$Master/tlpkg/readme-html.dir");
+  system("rm", "-rf", "$Master/tlpkg/readme-txt.dir");
   for my $f (qw/doc.html index.html LICENSE.CTAN LICENSE.TL README
                 README.usergroups release-texlive.txt texmf.cnf/) {
-    system("rm", "-f", "$Master/$f");
+    system("rm", "-f", "$Master/tlpkg/$f");
   }
-  if (-d "$Master/temp") {
-    system("rmdir", "--ignore-fail-on-non-empty", "$Master/temp");
+  if (-d "$Master/tlpkg/temp") {
+    system("rmdir", "--ignore-fail-on-non-empty", "$Master/tlpkg/temp");
   }
-  unlink("$Master/install-tl.log");
+  unlink("$Master/tlpkg/install-tl.log");
   # should we do that????
-  system("rm", "-rf", "$Master/texmf-config");
-  system("rmdir", "--ignore-fail-on-non-empty", "$Master");
+  # system("rm", "-rf", "$Master/texmf-config");
+  # system("rmdir", "--ignore-fail-on-non-empty", "$Master");
 }
 
 
@@ -5466,7 +5469,7 @@ sub action_conf {
       $fn || ( $fn = "$TEXMFCONFIG/tlmgr/config" ) ;
       $cf = TeXLive::TLConfFile->new($fn, "#", "=");
     } elsif ($arg eq "texmf") {
-      $fn || ( $fn = "$Master/texmf.cnf" ) ;
+      $fn || ( $fn = "$Master/tlpkg/texmf.cnf" ) ;
       $cf = TeXLive::TLConfFile->new($fn, "[%#]", "=");
     } elsif ($arg eq "updmap") {
       $fn || ( chomp ($fn = `kpsewhich updmap.cfg`) ) ;
