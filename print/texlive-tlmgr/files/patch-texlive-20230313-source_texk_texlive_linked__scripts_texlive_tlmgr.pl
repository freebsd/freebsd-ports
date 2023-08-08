--- texlive-20230313-source/texk/texlive/linked_scripts/texlive/tlmgr.pl.orig	2023-04-02 15:07:53 UTC
+++ texlive-20230313-source/texk/texlive/linked_scripts/texlive/tlmgr.pl
@@ -3,7 +3,7 @@
 # Copyright 2008-2023 Norbert Preining
 # This file is licensed under the GNU General Public License version 2
 # or any later version.
-# 
+#
 # TeX Live Manager.
 
 use strict; use warnings;
@@ -125,7 +125,7 @@ our $FLAG_REINSTALL = "I";
 our $FLAG_REINSTALL = "I";
 
 # keep in sync with install-tl.
-our $common_fmtutil_args = 
+our $common_fmtutil_args =
   "--no-error-if-no-engine=$TeXLive::TLConfig::PartialEngineSupport";
 
 # option variables
@@ -137,7 +137,7 @@ my %action_specification = (
     "run-post" => 0,
     "function" => \&action_include_tlpobj
   },
-  "backup" => { 
+  "backup" => {
     "options" => {
       "all" => 1,
       "backupdir" => "=s",
@@ -151,25 +151,25 @@ my %action_specification = (
     "run-post" => 0,
     "function" => \&action_candidates
   },
-  "check" => { 
+  "check" => {
     "options"  => { "use-svn" => 1 },
     "run-post" => 1,
     "function" => \&action_check
   },
   "conf" => {
-    "options"  => { 
+    "options"  => {
       "conffile" => "=s",
       "delete" => 1,
     },
     "run-post" => 0,
     "function" => \&action_conf
   },
-  "dump-tlpdb" => { 
+  "dump-tlpdb" => {
     "options"  => { local => 1, remote => 1 },
     "run-post" => 0,
     "function" => \&action_dumptlpdb
   },
-  "generate" => { 
+  "generate" => {
     "options"  => {
       "dest" => "=s",
       "localcfg" => "=s",
@@ -182,7 +182,7 @@ my %action_specification = (
     "run-post" => 0,
     "function" => \&action_get_mirror
   },
-  "gui" => { 
+  "gui" => {
     "options"  => {
       "load" => 1,
       # Tk::CmdLine options
@@ -203,11 +203,11 @@ my %action_specification = (
     "run-post" => 1,
     "function" => \&action_gui
   },
-  "info" => { 
-    "options"  => { 
+  "info" => {
+    "options"  => {
       "data" => "=s",
       "all" => 1,
-      "list" => 1, 
+      "list" => 1,
       "only-installed" => 1,
       "only-remote" => 1
     },
@@ -236,11 +236,11 @@ my %action_specification = (
     "run-post" => 0,
     "function" => \&action_key
   },
-  "option" => { 
+  "option" => {
     "run-post" => 1,
     "function" => \&action_option
   },
-  "paper" => { 
+  "paper" => {
     "options"  => { "list" => 1 },
     "run-post" => 1,
     "function" => \&action_paper
@@ -250,12 +250,12 @@ my %action_specification = (
     "run-post" => 0,
     "function" => \&action_path
   },
-  "pinning" => { 
+  "pinning" => {
     "options"  => { "all" => 1 },
     "run-post" => 1,
     "function" => \&action_pinning
   },
-  "platform" => { 
+  "platform" => {
     "options"  => { "dry-run|n" => 1 },
     "run-post" => 1,
     "function" => \&action_platform
@@ -269,12 +269,12 @@ my %action_specification = (
     "run-post" => 0,
     "function" => \&action_postaction
   },
-  "recreate-tlpdb" => { 
+  "recreate-tlpdb" => {
     "options"  => { "platform|arch" => "=s" },
     "run-post" => 0,
     "function" => \&action_recreate_tlpdb
   },
-  "remove" => { 
+  "remove" => {
     "options"  => {
       "all" => 1,
       "backup" => 1,
@@ -471,7 +471,7 @@ sub main {
 
   # unify arguments so that the $action contains paper in all cases
   # and push the first arg back to @ARGV for action_paper processing
-  if (defined $action 
+  if (defined $action
       && $action =~ /^(paper|xdvi|psutils|pdftex|dvips|dvipdfmx?|context)$/) {
     unshift(@ARGV, $action);
     $action = "paper";
@@ -542,7 +542,7 @@ sub main {
     # less can break control characters and thus the output of pod2usage
     # is broken.  We add/set LESS=-R in the environment and unset
     # LESSPIPE and LESSOPEN to try to help.
-    # 
+    #
     if (defined($ENV{'LESS'})) {
       $ENV{'LESS'} .= " -R";
     } else {
@@ -582,7 +582,7 @@ for the full story.\n";
   }
 
   # --machine-readable is only supported by update.
-  if ($::machinereadable && 
+  if ($::machinereadable &&
     $action ne "update" && $action ne "install" && $action ne "option" && $action ne "shell" && $action ne "remove") {
     tlwarn("$prg: --machine-readable output not supported for $action\n");
   }
@@ -638,6 +638,9 @@ for the full story.\n";
   # besides doing normal logging if -logfile is specified, we try to log
   # package related actions (install, remove, update) to
   # the package-log file TEXMFSYSVAR/web2c/tlmgr.log
+  #
+  # *** FreeBSD specific: FreeBSD port uses /var/db/tlpkg/tlmgr.log.
+  #
   $packagelogged = 0;  # how many msgs we logged
   $commandslogged = 0;
   chomp (my $texmfsysvar = `kpsewhich -var-value=TEXMFSYSVAR`);
@@ -646,7 +649,7 @@ for the full story.\n";
   if ($opts{"usermode"}) {
     $packagelogfile ||= "$texmfvar/web2c/tlmgr.log";
   } else {
-    $packagelogfile ||= "$texmfsysvar/web2c/tlmgr.log";
+    $packagelogfile ||= "/var/db/tlpkg/tlmgr.log";
   }
   #
   # Try to open the packagelog file, but do NOT die when that does not work
@@ -719,13 +722,13 @@ for the full story.\n";
   # being run (e.g., untar fails).  F_WARNING continues on, including
   # postactions (e.g., user tries to install 10 packages and the
   # checksum fails for one, but the others are ok), but still ends the
-  # program by exiting unsuccessfully.  So call them both "errors" 
+  # program by exiting unsuccessfully.  So call them both "errors"
   # as far as the user is concerned.
   if ($ret & ($F_ERROR | $F_WARNING)) {
     tlwarn("$prg: An error has occurred. See above messages. Exiting.\n");
   }
 
-  # end of main program, returns also error codes 
+  # end of main program, returns also error codes
   exit ($ret);
 
 } # end main
@@ -736,9 +739,9 @@ sub give_version {
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
@@ -831,7 +834,7 @@ sub execute_action {
 
 # run CMD with notice to the user and if exit status is nonzero, complain.
 # return exit status.
-# 
+#
 sub do_cmd_and_check {
   my $cmd = shift;
   # we output the pre-running notice on a separate line so that
@@ -920,7 +923,7 @@ sub handle_execute_actions {
     for my $m (keys %{$::execute_actions{'disable'}{'maps'}}) {
       $updmap_run_needed = 1;
     }
-    my $dest = $opts{"usermode"} ? "$::maintree/web2c/updmap.cfg" 
+    my $dest = $opts{"usermode"} ? "$::maintree/web2c/updmap.cfg"
                : "$TEXMFDIST/web2c/updmap.cfg";
     if ($updmap_run_needed) {
       TeXLive::TLUtils::create_updmap($localtlpdb, $dest);
@@ -929,7 +932,7 @@ sub handle_execute_actions {
   }
 
   # format relevant things
-  # we first have to check if the config files, that is fmtutil.cnf 
+  # we first have to check if the config files, that is fmtutil.cnf
   # or one of the language* files have changed, regenerate them
   # if necessary, and then run the necessary fmtutil calls.
   {
@@ -990,7 +993,7 @@ sub handle_execute_actions {
                                        "$TEXMFDIST/web2c/fmtutil.cnf");
     }
     if (!$::regenerate_all_formats) {
-      # first regenerate all formats --byengine 
+      # first regenerate all formats --byengine
       for my $e (keys %updated_engines) {
         debug ("updating formats based on $e\n");
         $errors += do_cmd_and_check
@@ -1098,7 +1101,7 @@ sub action_get_mirror {
 #
 # just return a mirror
 sub action_get_mirror {
-  my $loc = give_ctan_mirror(); 
+  my $loc = give_ctan_mirror();
   print "$loc\n";
   return ($F_OK | $F_NOPOSTACTION);
 }
@@ -1188,7 +1191,7 @@ sub backup_and_remove_package {
   }
   if ($opts{"backup"}) {
     $tlp->make_container($::progs{'compressor'}, $localtlpdb->root,
-                         destdir => $opts{"backupdir"}, 
+                         destdir => $opts{"backupdir"},
                          relative => $tlp->relocated,
                          user => 1);
     if ($autobackup) {
@@ -1253,7 +1256,7 @@ sub action_remove {
   #
   # remove all .ARCH dependencies, too, unless $opts{"no-depends-at-all"}
   @packs = $localtlpdb->expand_dependencies("-only-arch", $localtlpdb, @packs)
-    unless $opts{"no-depends-at-all"}; 
+    unless $opts{"no-depends-at-all"};
   # remove deps unless $opts{"no-depends"}
   @packs = $localtlpdb->expand_dependencies("-no-collections", $localtlpdb, @packs) unless $opts{"no-depends"};
   my %allpacks;
@@ -1293,7 +1296,7 @@ sub action_remove {
   my $currnr = 1;
   my $starttime = time();
   my $donesize = 0;
-  
+
   print "total-bytes\t$sizes{'__TOTAL__'}\n" if $::machinereadable;
   print "end-of-header\n" if $::machinereadable;
 
@@ -1382,7 +1385,7 @@ sub action_remove {
 
 
 #  PAPER
-# 
+#
 # ARGV can look like:
 #   paper a4
 #   paper letter
@@ -1612,11 +1615,11 @@ sub action_dumptlpdb {
 #
 sub action_dumptlpdb {
   init_local_db();
-  
+
   # we are basically doing machine-readable output.
   my $savemr = $::machinereadable;
   $::machinereadable = 1;
-  
+
   if ($opts{"local"} && !$opts{"remote"}) {
     if ($opts{"json"}) {
       print $localtlpdb->as_json;
@@ -1639,11 +1642,11 @@ sub action_dumptlpdb {
     tlwarn("$prg dump-tlpdb: need exactly one of --local and --remote.\n");
     return ($F_ERROR);
   }
-  
+
   $::machinereadable = $savemr;
   return ($F_OK | $F_NOPOSTACTION);
 }
-    
+
 #  INFO
 #
 sub action_info {
@@ -1711,7 +1714,7 @@ sub action_info {
   # tlmgr info
   # tlmgr info collection
   # tlmgr info scheme
-  # these commands just list the packages/collections/schemes installed with 
+  # these commands just list the packages/collections/schemes installed with
   # a short list
   my @whattolist;
   $what = ($what || "-all");
@@ -1790,11 +1793,11 @@ sub action_search {
     $tlpdb = $localtlpdb;
   }
 
-  my ($foundfile, $founddesc) = search_tlpdb($tlpdb, $r, 
-    $opts{'file'} || $opts{'all'}, 
-    (!$opts{'file'} || $opts{'all'}), 
+  my ($foundfile, $founddesc) = search_tlpdb($tlpdb, $r,
+    $opts{'file'} || $opts{'all'},
+    (!$opts{'file'} || $opts{'all'}),
     $opts{'word'});
- 
+
   print $founddesc;
   print $foundfile;
 
@@ -1807,7 +1810,7 @@ sub search_tlpdb {
   my $retdesc = '';
   foreach my $pkg ($tlpdb->list_packages) {
     my $tlp = $tlpdb->get_package($pkg);
-    
+
     # --file or --all -> search (full) file names
     if ($dofile) {
       my @ret = search_pkg_files($tlp, $what);
@@ -1902,7 +1905,7 @@ sub get_available_backups {
     # for more on that please see man perlport
     my $usedt = $ctime;
     if (!$usedt) {
-      # can happen on 
+      # can happen on
       $usedt = $mtime;
     }
     if (!$usedt) {
@@ -1923,8 +1926,8 @@ sub restore_one_package {
   # first remove the package, then reinstall it
   # this way we get rid of useless files
   my $restore_file;
-  for my $ext (map {$Compressors{$_}{'extension'}} 
-                 sort {$Compressors{$a}{'priority'} <=> $Compressors{$a}{'priority'}} 
+  for my $ext (map {$Compressors{$_}{'extension'}}
+                 sort {$Compressors{$a}{'priority'} <=> $Compressors{$a}{'priority'}}
                    keys %Compressors) {
     if (-r "$bd/${pkg}.r${rev}.tar.$ext") {
       $restore_file = "$bd/${pkg}.r${rev}.tar.$ext";
@@ -1996,7 +1999,7 @@ sub setup_backup_directory {
   my $saving_verb = $opts{"dry-run"} || $opts{"list"} ? "would save" :"saving";
   info("$prg: $saving_verb backups to $opts{'backupdir'}\n")
     if $opts{"backup"} && !$::machinereadable;
-  
+
   return ($ret, $autobackup);
 }
 
@@ -2103,7 +2106,7 @@ sub action_restore {
         my ($sec,$min,$hour,$mday,$mon,$year,$wday,$yday,$isdst) =
           localtime($revs{$rs});
         # localtime returns dates starting from 1900, and the month is 0..11
-        $dstr = sprintf "%04d-%02d-%02d %02d:%02d", 
+        $dstr = sprintf "%04d-%02d-%02d %02d:%02d",
           $year+1900, $mon+1, $mday, $hour, $min;
       }
       if ($mode eq "json") {
@@ -2233,7 +2236,7 @@ sub action_backup {
   }
 
   # if we do --clean --all we also want to remove packages that
-  # are not present anymore in the tlpdb, so use the readdir mode 
+  # are not present anymore in the tlpdb, so use the readdir mode
   # to determine backups
   if ($opts{"all"} && $clean_mode) {
     # initialize the hash(packages) of hash(revisions)
@@ -2304,15 +2307,15 @@ sub action_backup {
 # * write_w32_updater subroutine in tlmgr.pl prepares the update
 #   and writes the updater script. Packages in .xz archives are
 #   downloaded/copied and uncompressed to .tar files. Also .tar
-#   backups of the current packages are made. If everything is 
-#   successful, the update script is created from the template. 
+#   backups of the current packages are made. If everything is
+#   successful, the update script is created from the template.
 #   Otherwise the update is aborted.
-# * updater-w32[.bat] batch script, triggers and executes the actual 
-#   update. It first restarts itself in a separate instance of cmd.exe 
-#   (and in a new console window in gui mode) and runs the update 
-#   from there. The update is run with echo on and all output is 
-#   logged to a file (or stderr in verbose mode). After successful 
-#   infrastructure update, tlmgr is optionally restarted if update 
+# * updater-w32[.bat] batch script, triggers and executes the actual
+#   update. It first restarts itself in a separate instance of cmd.exe
+#   (and in a new console window in gui mode) and runs the update
+#   from there. The update is run with echo on and all output is
+#   logged to a file (or stderr in verbose mode). After successful
+#   infrastructure update, tlmgr is optionally restarted if update
 #   of other packages is asked for.
 #      The infrastructure update itself proceeds as follows:
 #   (1) untar all package archives
@@ -2323,9 +2326,9 @@ sub action_backup {
 #   (2) untar all package backups
 #   (3) include .tlpobj files (from backup) into tlpdb
 #   (4) print restore info to console
-#      Any error during (2) or (3) and we go into panic state.  At this 
-#   point there is no guarantee that the installation is still working. 
-#   There is not much we can do but to print failed restore info and 
+#      Any error during (2) or (3) and we go into panic state.  At this
+#   point there is no guarantee that the installation is still working.
+#   There is not much we can do but to print failed restore info and
 #   give instructions to download and run 'update-tlmgr-latest.exe'
 #   to repair the installation.
 # =====================================================================
@@ -2343,7 +2346,7 @@ sub write_w32_updater {
   my $opt_src = $localtlpdb->option("install_srcfiles");
   my $opt_doc = $localtlpdb->option("install_docfiles");
   my $root = $localtlpdb->root;
-  my $temp = "$root/temp";
+  my $temp = "$root/tlpkg/temp";
   TeXLive::TLUtils::mkdirhier($temp);
   tlwarn("$prg: Backup option not implemented for infrastructure update.\n") if ($opts{"backup"});
   if ($media eq 'local_uncompressed') {
@@ -2360,7 +2363,7 @@ sub write_w32_updater {
     $media = $remotetlpdb->media;
     if ($media eq "virtual") {
       my $maxtlpdb;
-      (undef, undef, $mediatlp, $maxtlpdb) = 
+      (undef, undef, $mediatlp, $maxtlpdb) =
         $remotetlpdb->virtual_candidate($pkg);
       $repo = $maxtlpdb->root . "/$Archive";
       # update the media type of the used tlpdb
@@ -2422,7 +2425,7 @@ sub write_w32_updater {
       unlink($dlcontainer); # we don't need that archive anymore
     }
   }
-  
+
   # prepare updater script
   my $respawn_cmd = "cmd.exe /e:on/v:off/d/c";
   $respawn_cmd = "start /wait $respawn_cmd" if ($::gui_mode);
@@ -2440,8 +2443,8 @@ sub write_w32_updater {
   }
   my $batch_script = <<"EOF";
 :: This file is part of an automated update process of
-:: infrastructure files and should not be run standalone. 
-:: For more details about the update process see comments 
+:: infrastructure files and should not be run standalone.
+:: For more details about the update process see comments
 :: in tlmgr.pl (subroutine write_w32_updater).
 
   if [%1]==[:doit] goto :doit
@@ -2466,10 +2469,10 @@ sub write_w32_updater {
   if not errorlevel 1 goto :update
   >con echo Could not change working directory to "%~dp0.."
   >con echo Aborting infrastructure update, no changes have been made.
-  >con $gui_pause 
+  >con $gui_pause
   popd
   exit /b 1
-    
+
 :update
   for %%I in (@upd_tar) do (
     temp\\tar.exe -xmf temp\\%%I
@@ -2479,10 +2482,10 @@ sub write_w32_updater {
   if errorlevel 1 goto :rollback
   >>$pkg_log echo [%date% %time%] self update: @upd_info
   >con echo self update: @upd_info
-  del "%~dp0*.tar" "%~dp0tar.exe" 
+  del "%~dp0*.tar" "%~dp0tar.exe"
   >con echo Infrastructure update finished successfully.
   >con echo $post_update_msg
-  >con $gui_pause 
+  >con $gui_pause
   popd
   exit /b 0
 
@@ -2499,7 +2502,7 @@ sub write_w32_updater {
   >>$pkg_log echo [%date% %time%] self restore: @rst_info
   >con echo self restore: @rst_info
   >con echo Infrastructure update failed. Previous version has been restored.
-  >con $gui_pause 
+  >con $gui_pause
   popd
   exit /b 1
 
@@ -2510,7 +2513,7 @@ sub write_w32_updater {
   >con echo Infrastructure update failed and backup recovery failed too.
   >con echo To repair your TeX Live installation download and run:
   >con echo $TeXLive::TLConfig::TeXLiveURL/update-tlmgr-latest.exe
-  >con $gui_pause 
+  >con $gui_pause
   popd
   exit /b 666
 EOF
@@ -2537,7 +2540,7 @@ EOF
 
 #  UPDATE
 
-# compute the list of auto-install, auto-remove, forcibly-removed 
+# compute the list of auto-install, auto-remove, forcibly-removed
 # packages from the list of packages to be installed
 # the list of packages passed in is already expanded
 sub auto_remove_install_force_packages {
@@ -2582,7 +2585,7 @@ sub auto_remove_install_force_packages {
     delete($removals_full{$p});
   }
   # in a first round we check only for forcibly removed collections
-  # this is necessary to NOT declare a package that is contained 
+  # this is necessary to NOT declare a package that is contained
   # in a forcibly removed collections as auto-install since it appears
   # in the @remoteexpansion_full, but not in @localexpansion_full.
   for my $p (@localexpansion_full) {
@@ -2608,9 +2611,9 @@ sub auto_remove_install_force_packages {
   # now we have in %forcermpkgs_full only collections that have been
   # forcibly removed. Again, expand those against the remote tlpdb
   # and remove the expanded packages from the list of localexpansion.
-  my @pkgs_from_forcerm_colls = 
+  my @pkgs_from_forcerm_colls =
     $remotetlpdb->expand_dependencies($localtlpdb, keys %forcermpkgs_full);
-  # 
+  #
   # the package in @pkgs_from_forcerm_colls would be auto-installed, so
   # check for that:
   for my $p (keys %newpkgs_full) {
@@ -2735,9 +2738,9 @@ sub action_update {
   $opts{"no-depends"} = 1 if $opts{"no-depends-at-all"};
 
   # make a quick check on command line arguments to avoid loading
-  # the remote db uselessly. 
+  # the remote db uselessly.
   # we require:
-  # if no --list is given: either --self or --all or <pkgs> 
+  # if no --list is given: either --self or --all or <pkgs>
   # if --list is given:    nothing
   # other options just change the behavior
   if (!($opts{"list"} || @ARGV || $opts{"all"} || $opts{"self"})) {
@@ -2837,8 +2840,8 @@ sub action_update {
     @todo = grep (!m/$CriticalPackagesRegexp/, @todo)
       unless $opts{"list"};
   }
-    
-  my ($remref, $newref, $forref, $new_due_to_forcerm_coll_ref) = 
+
+  my ($remref, $newref, $forref, $new_due_to_forcerm_coll_ref) =
     auto_remove_install_force_packages(@todo);
   my %removals = %$remref;
   my %forcermpkgs = %$forref;
@@ -2888,7 +2891,7 @@ sub action_update {
     tlwarn("$prg: Please resolve these conflicts!\n");
     return ($F_ERROR);
   }
-      
+
   #
   # we first collect the list of packages to be actually updated or installed
   my %updated;
@@ -3075,7 +3078,7 @@ sub action_update {
     }
     #
     # the idea of suppressing warnings is simply that if a file is present
-    # in more than one package either in the beginning or after a full 
+    # in more than one package either in the beginning or after a full
     # update then this should give a warning. In all other cases
     # the warning should be suppressed.
     for my $f (keys %old_files_to_pkgs) {
@@ -3097,7 +3100,7 @@ sub action_update {
   # 2. updates
   # 3. auto-install
   # that way if a file has been moved from one to another package it
-  # removing the old version after the new package has been installed 
+  # removing the old version after the new package has been installed
   # will not give a warning about files being included somewhere else
   #
 
@@ -3166,7 +3169,7 @@ sub action_update {
   my $totalsize = $sizes{'__TOTAL__'};
 
 
-  # 
+  #
   # UPDATES AND NEW PACKAGES
   #
   # order:
@@ -3178,10 +3181,10 @@ sub action_update {
   # - install new schemes (? will not happen?)
   #
   # this makes sure that only if all depending packages are installed
-  # the collection is updated, which in turn makes sure that 
+  # the collection is updated, which in turn makes sure that
   # if the installation of a new package does break it will not be
   # counted as forcibly removed later on.
-  # 
+  #
   my @inst_packs;
   my @inst_colls;
   my @inst_schemes;
@@ -3215,7 +3218,7 @@ sub action_update {
   for my $pkg (@new_packs, @new_colls, @new_schemes) {
     $is_new{$pkg} = 1;
   }
-  
+
   #
   # TODO idea
   # currently this big loop contains a long if then for new packages
@@ -3225,7 +3228,7 @@ sub action_update {
   # and following it after the change would make it much harder
   #
   foreach my $pkg (@inst_packs, @new_packs, @inst_colls, @new_colls, @inst_schemes, @new_schemes) {
-    
+
     if (!$is_new{$pkg}) {
       # skip this loop if infra update on w32
       next if ($pkg =~ m/^00texlive/);
@@ -3304,9 +3307,9 @@ sub action_update {
         $updated{$pkg} = 1;
         next;
       }
-      
+
       # older tlmgr forgot to clear the relocated bit when saving a tlpobj
-      # into the local tlpdb, although the paths were rewritten. 
+      # into the local tlpdb, although the paths were rewritten.
       # We have to clear this bit otherwise the make_container calls below
       # for creating an unwind container will create some rubbish
       # TODO for user mode we should NOT clear this bit!
@@ -3323,19 +3326,19 @@ sub action_update {
                              user => 1);
         $unwind_package =
             "$opts{'backupdir'}/${pkg}.r" . $tlp->revision . ".tar.$compressorextension";
-        
+
         if ($autobackup) {
           # in case we do auto backups we remove older backups
           clear_old_backups($pkg, $opts{"backupdir"}, $autobackup);
         }
       }
-      
+
       my ($estrem, $esttot);
       if (!$opts{"list"}) {
         ($estrem, $esttot) = TeXLive::TLUtils::time_estimate($totalsize,
                                                              $donesize, $starttime);
       }
-      
+
       if ($::machinereadable) {
         machine_line($pkg, $FLAG_UPDATE, $rev, $mediarev, $sizes{$pkg}, $estrem, $esttot, @addargs);
       } else {
@@ -3345,7 +3348,7 @@ sub action_update {
       }
       $donesize += $sizes{$pkg};
       $currnr++;
-      
+
       if ($opts{"dry-run"}) {
         info("\n") unless $::machinereadable;
         $updated{$pkg} = 1;
@@ -3353,7 +3356,7 @@ sub action_update {
       } else {
         info(" ... ") unless $::machinereadable;  # more to come
       }
-      
+
       if (!$unwind_package) {
         # no backup was made, so let us create a temporary .tar file
         # of the package
@@ -3382,7 +3385,7 @@ sub action_update {
       if ($pkg =~ m/$CriticalPackagesRegexp/) {
         debug("Not removing critical package $pkg\n");
       } else {
-        $localtlpdb->remove_package($pkg, 
+        $localtlpdb->remove_package($pkg,
           "remove-warn-files" => \%do_warn_on_move);
       }
       if ($remotetlpdb->install_package($pkg, $localtlpdb)) {
@@ -3457,7 +3460,7 @@ sub action_update {
       }
       info("done\n") unless $::machinereadable;
     } else { # $is_new{$pkg} is true!!!
-      # 
+      #
       # NEW PACKAGES
       #
       if ($opts{"no-auto-install"}) {
@@ -3571,7 +3574,7 @@ sub action_update {
             if ($#found_pkgs == 0 && $found_pkgs[0] =~ m/^$pkg:/) {
               # only one package has been returned and it
               # matches the current package followed by a colon
-              # remember the TLPDB->find_file returns 
+              # remember the TLPDB->find_file returns
               #   $pkg:$file
               # in this case we can ignore it
               $bad_file = 0;
@@ -3596,7 +3599,7 @@ sub action_update {
         #unlink("$Master/$f");
         debug("removing disappearing file $f\n");
       }
-    } 
+    }
   } # end of if ($opts{"list"}) ... else part
 
   # check if any additional updates are asked for
@@ -3626,7 +3629,7 @@ sub action_update {
     for my $f (@infra_files_to_be_removed) {
       debug("file scheduled for removal $f\n");
     }
-    my $ret = write_w32_updater($restart_tlmgr, 
+    my $ret = write_w32_updater($restart_tlmgr,
                                 \@infra_files_to_be_removed, @critical);
     if ($ret) {
       tlwarn ("$prg: Aborting infrastructure update.\n");
@@ -3647,8 +3650,8 @@ sub action_update {
     return($F_ERROR);
   }
 
-  # for --dry-run we cannot restart tlmgr (no way to fake successful 
-  # infra update) instead we call action_update() again and signal this 
+  # for --dry-run we cannot restart tlmgr (no way to fake successful
+  # infra update) instead we call action_update() again and signal this
   # by $opts{"dry-run"} = -1
   if ($opts{"dry-run"} && !$opts{"list"} && $restart_tlmgr) {
     $opts{"self"} = 0;
@@ -3659,7 +3662,7 @@ sub action_update {
     $ret |= action_update();
     return ($ret);
   }
-  
+
   # if a real update from default disk location didn't find anything,
   # warn if nothing is updated.  Unless they said --self, in which case
   # we've already reported it.
@@ -3691,7 +3694,7 @@ sub check_announce_format_triggers {
 
 
 sub check_announce_format_triggers {
-  # we treat new and updated packages the same as updated 
+  # we treat new and updated packages the same as updated
   # when it comes to triggers
   my %updpacks = map { $_ => 1 } @_;
 
@@ -3875,7 +3878,7 @@ sub action_install {
   defined($sizes{'__TOTAL__'}) || ($sizes{'__TOTAL__'} = 0);
   my $totalsize = $sizes{'__TOTAL__'};
   my $donesize = 0;
-  
+
   print "total-bytes\t$sizes{'__TOTAL__'}\n" if $::machinereadable;
   print "end-of-header\n" if $::machinereadable;
 
@@ -3986,7 +3989,7 @@ sub show_one_package_json {
   my $tlp = ($is_installed ? $loctlp : $remtlp);
   #my $tlp = ($is_available ? $remtlp : $loctlp);
   # add available, installed, lrev, rrev fields and remove revision field
-  my $str = $tlp->as_json(available => ($is_available ? TeXLive::TLUtils::True() : TeXLive::TLUtils::False()), 
+  my $str = $tlp->as_json(available => ($is_available ? TeXLive::TLUtils::True() : TeXLive::TLUtils::False()),
                           installed => ($is_installed ? TeXLive::TLUtils::True() : TeXLive::TLUtils::False()),
                           lrev      => ($is_installed ? $loctlp->revision : 0),
                           rrev      => ($is_available ? $remtlp->revision : 0),
@@ -4288,14 +4291,14 @@ sub show_one_package_detail {
   my $sizestr = "";
   if ($tlp->category ne "Collection" && $tlp->category ne "Scheme") {
     my $srcsize = $tlp->srcsize * $TeXLive::TLConfig::BlockSize;
-    $sizestr = sprintf("%ssrc: %dk", $sizestr, int($srcsize / 1024) + 1) 
+    $sizestr = sprintf("%ssrc: %dk", $sizestr, int($srcsize / 1024) + 1)
       if ($srcsize > 0);
     my $docsize = $tlp->docsize * $TeXLive::TLConfig::BlockSize;
-    $sizestr .= sprintf("%sdoc: %dk", 
+    $sizestr .= sprintf("%sdoc: %dk",
       ($sizestr ? ", " : ""), int($docsize / 1024) + 1)
         if ($docsize > 0);
     my $runsize = $tlp->runsize * $TeXLive::TLConfig::BlockSize;
-    $sizestr .= sprintf("%srun: %dk", 
+    $sizestr .= sprintf("%srun: %dk",
       ($sizestr ? ", " : ""), int($runsize / 1024) + 1)
         if ($runsize > 0);
     # check for .ARCH expansions
@@ -4624,7 +4627,7 @@ sub action_repository {
       return ($F_ERROR);
     }
     # check if it is either url or absolute path
-    if (($p !~ m!^(https?|ftp)://!i) && ($p !~ m!$TeXLive::TLUtils::SshURIRegex!) && 
+    if (($p !~ m!^(https?|ftp)://!i) && ($p !~ m!$TeXLive::TLUtils::SshURIRegex!) &&
         !File::Spec->file_name_is_absolute($p)) {
       tlwarn("$prg: neither https?/ftp/ssh/scp/file URI nor absolute path, no action: $p\n");
       return ($F_ERROR);
@@ -4697,7 +4700,7 @@ sub action_repository {
     }
     if (!$remotetlpdb->is_virtual) {
       my $verstat = $remotetlpdb->verification_status;
-      print "main ", $remotetlpdb->location, " ", 
+      print "main ", $remotetlpdb->location, " ",
         ($::machinereadable ? "$verstat " : ""),
         $VerificationStatusDescription{$verstat}, "\n";
       return ($F_OK);
@@ -5179,7 +5182,7 @@ sub action_generate {
                      ("fmtutil-sys $common_fmtutil_args --byhyphen \"$dest\"");
       } else {
         info("To make the newly-generated language.dat.lua take effect,"
-             . " run fmtutil-sys --byhyphen $dest.\n"); 
+             . " run fmtutil-sys --byhyphen $dest.\n");
       }
     }
     if ($what =~ m/^language(\.dat)?$/i) {
@@ -5195,7 +5198,7 @@ sub action_generate {
                      ("fmtutil-sys $common_fmtutil_args --byhyphen \"$dest\"");
       } else {
         info("To make the newly-generated language.dat take effect,"
-             . " run fmtutil-sys --byhyphen $dest.\n"); 
+             . " run fmtutil-sys --byhyphen $dest.\n");
       }
     }
     if ($what =~ m/^language(\.def)?$/i) {
@@ -5230,7 +5233,7 @@ sub action_generate {
       do_cmd_and_check("fmtutil-sys $common_fmtutil_args --all");
     } else {
       info("To make the newly-generated fmtutil.cnf take effect,"
-           . " run fmtutil-sys --all.\n"); 
+           . " run fmtutil-sys --all.\n");
     }
 
   } elsif ($what =~ m/^updmap$/i) {
@@ -5320,7 +5323,7 @@ Error message from creating MainWindow:
 
 #  UNINSTALL
 # Return zero if successful, nonzero if failure.
-# 
+#
 sub uninstall_texlive {
   if (wndws()) {
     printf STDERR "Please use \"Add/Remove Programs\" from the Control Panel "
@@ -5348,7 +5351,7 @@ sub uninstall_texlive {
     }
   }
   print "Ok, removing the whole TL installation under: $tlroot\n";
-  
+
   # Must use kpsewhich before removing it.
   chomp (my $texmfsysconfig = `kpsewhich -var-value=TEXMFSYSCONFIG`);
   chomp (my $texmfsysvar = `kpsewhich -var-value=TEXMFSYSVAR`);
@@ -5372,24 +5375,23 @@ sub uninstall_texlive {
   system("rm", "-rf", "$Master/bin");
 
   # In case SYS{VAR,CONFIG} were configured with different values.
-  # Above we remove the hardwired $Master/texmf-{config,var} 
+  # Above we remove the hardwired $Master/texmf-{config,var}
   # if present, assuming the user did not pathologically configure things.
   system("rm", "-rf", "$texmfsysconfig");
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
-  
+
   # don't remove user dirs, which may have been abused.
   if (-d $texmfconfig || -d $texmfvar) {
     print <<NOT_REMOVED;
@@ -5405,7 +5407,7 @@ NOT_REMOVED
     print "\nSorry, something did not get removed under: $Master\n";
     $remnants = 1;
   } else {
-    $remnants = 0; 
+    $remnants = 0;
   }
   return $remnants;
 }
@@ -5504,7 +5506,7 @@ sub init_tltree {
 sub init_tltree {
   my ($svn) = @_;
 
-  # if we are on W32, die (no find).  
+  # if we are on W32, die (no find).
   my $arch = $localtlpdb->platform();
   if ($arch eq "windows") {
     tldie("$prg: sorry, cannot check this on Windows.\n");
@@ -5656,7 +5658,7 @@ sub check_files {
 }
 
 # Check for runtime files with the same name but different contents.
-# 
+#
 sub check_runfiles {
   my $Master = $localtlpdb->root;
 
@@ -5673,7 +5675,7 @@ sub check_runfiles {
     my $tlp = $localtlpdb->get_package($tlpn);
     my @files = $tlp->runfiles;
     if ($tlp->relocated) {
-      for (@files) { 
+      for (@files) {
         s!^$TeXLive::TLConfig::RelocPrefix/!$TeXLive::TLConfig::RelocTree/!;
       }
     }
@@ -5909,7 +5911,7 @@ sub check_executes {
     if (",$TeXLive::TLConfig::PartialEngineSupport," =~ /,$engine,/) {
       # luajit[hb]tex is special since it is not available on all architectures
       #   due to inherent reasons (machine code);
-      # 
+      #
       # We do not want to have error messages here, so we do the following:
       # * if tlpkg/tlpsrc/luajittex.tlpsrc is available, then load it
       #   and filter away those archs that are excluded with f/!...
@@ -6146,10 +6148,10 @@ sub check_texmfdbs {
 }
 
 #  POSTACTION
-# 
+#
 # explicitly run the various post actions, e.g.,
 # on a client system or overriding global settings.
-# 
+#
 # tlmgr postaction [--windowsmode=user|admin] [--fileassocmode=1|2] [--all]
 #    [install|remove] [shortcut|fileassoc|script] [<pkg>...]
 
@@ -6256,7 +6258,7 @@ sub action_postaction {
 
 
 #  INIT-USERTREE
-# 
+#
 # sets up the user tree for tlmgr in user mode
 sub action_init_usertree {
   # init_local_db but do not die if localtlpdb is not found!
@@ -6300,7 +6302,7 @@ sub action_init_usertree {
 
 
 #  CONF
-# 
+#
 # tries to mimic texconfig conf but can also set values for both tlmgr
 # and texmf conf files.
 #
@@ -6325,7 +6327,7 @@ sub action_conf {
       $fn || ( $fn = "$TEXMFCONFIG/tlmgr/config" ) ;
       $cf = TeXLive::TLConfFile->new($fn, "#", "=");
     } elsif ($arg eq "texmf" || $arg eq "auxtrees") {
-      $fn || ( $fn = "$Master/texmf.cnf" ) ;
+      $fn || ( $fn = "$Master/tlpkg/texmf.cnf" ) ;
       $cf = TeXLive::TLConfFile->new($fn, "[%#]", "=");
     } elsif ($arg eq "updmap") {
       $fn || ( chomp ($fn = `kpsewhich updmap.cfg`) ) ;
@@ -6437,7 +6439,7 @@ sub action_conf {
         if (defined($opts{'delete'})) {
           if (defined($cf->value($key))) {
             info("$prg: removing setting $arg $key value: " . $cf->value($key)
-                 . "from $fn\n"); 
+                 . "from $fn\n");
             $cf->delete_key($key);
           } else {
             info("$prg: $arg $key not defined, cannot remove ($fn)\n");
@@ -6535,7 +6537,7 @@ sub texconfig_conf_mimic {
 # tlmgr key list
 # tlmgr key add <filename>
 # tlmgr key remove <keyid>
-# 
+#
 sub action_key {
   my $arg = shift @ARGV;
 
@@ -6569,7 +6571,7 @@ sub action_key {
         return $F_ERROR;
       }
       debug("running: $::gpg --primary-keyring repository-keys.gpg  --delete-key $what\n");
-      my ($out, $ret) = 
+      my ($out, $ret) =
           TeXLive::TLUtils::run_cmd("$::gpg --primary-keyring repository-keys.gpg --delete-key \"$what\" 2>&1");
       if ($ret == 0) {
         info("$prg: key successfully removed\n");
@@ -6578,7 +6580,7 @@ sub action_key {
         tlwarn("$prg: key removal failed, output:\n$out\n");
         return $F_ERROR;
       }
-      
+
     } elsif ($arg eq 'add') {
       my $what = shift @ARGV;
       if (!$what) {
@@ -6591,7 +6593,7 @@ sub action_key {
         close(FOO);
       }
       debug("running: $::gpg --primary-keyring repository-keys.gpg  --import $what\n");
-      my ($out, $ret) = 
+      my ($out, $ret) =
           TeXLive::TLUtils::run_cmd("$::gpg --primary-keyring repository-keys.gpg  --import \"$what\" 2>&1");
       if ($ret == 0) {
         info("$prg: key successfully imported\n");
@@ -6603,7 +6605,7 @@ sub action_key {
     } else {
       tldie("$prg: should not be reached: tlmgr key $arg\n");
     }
-    
+
   } else {
     tlwarn("$prg: unknown directive `$arg' to action `key'\n");
     return $F_ERROR;
@@ -6614,14 +6616,14 @@ sub action_key {
 
 #  SHELL
 # interactive shell.
-# 
+#
 sub action_shell {
   my $protocol = 1;
   my $default_prompt = "tlmgr>";
   # keys which can be set/get and are also settable via global cmdline opts
   my @valid_bool_keys
     = qw/debug-translation machine-readable no-execute-actions
-         verify-repo json/;  
+         verify-repo json/;
   my @valid_string_keys = qw/repository prompt/;
   my @valid_keys = (@valid_bool_keys, @valid_string_keys);
   # set auto flush unconditionally in action shell
@@ -6931,7 +6933,7 @@ sub init_local_db {
   # we normalize the path only if it is
   # - a url starting with neither http or ftp
   # - if we are on Windows, it does not start with Drive:[\/]
-  if (! ( $location =~ m!^(https?|ftp)://!i  || 
+  if (! ( $location =~ m!^(https?|ftp)://!i  ||
           $location =~ m!$TeXLive::TLUtils::SshURIRegex!i ||
           (wndws() && (!(-e $location) || ($location =~ m!^.:[\\/]!) ) ) ) ) {
     # seems to be a local path, try to normalize it
@@ -7102,7 +7104,7 @@ END_NO_CHECKSUMS
     $verstat = ": ";
     $verstat .= $VerificationStatusDescription{$remotetlpdb->virtual_get_tlpdb('main')->verification_status};
   }
-  info("\tmain = " . $repos{'main'} . " (" . 
+  info("\tmain = " . $repos{'main'} . " (" .
     ($remotetlpdb->virtual_get_tlpdb('main')->is_verified ? "" : "not ") .
     "verified$verstat)\n");
   for my $t (@tags) {
@@ -7132,7 +7134,7 @@ sub _init_tlmedia {
   my $silent = shift;
   # if we are already initialized to the same location, nothing
   # needs to be done.
-  # if we are initialized to a virtual tlpdb, then we have to 
+  # if we are initialized to a virtual tlpdb, then we have to
   # do in any case an initialization
   if (defined($remotetlpdb) && !$remotetlpdb->is_virtual &&
       ($remotetlpdb->root eq $location)) {
@@ -7167,7 +7169,7 @@ sub _init_tlmedia {
       $verstat = ": ";
       $verstat .= $VerificationStatusDescription{$remotetlpdb->verification_status};
     }
-    info("$prg: package repository $location (" . 
+    info("$prg: package repository $location (" .
       ($remotetlpdb->is_verified ? "" : "not ") . "verified$verstat)\n");
   }
   return 1;
@@ -7204,7 +7206,7 @@ sub setup_one_remotetlpdb {
     # first check that the saved tlpdb is present at all
     my $loc_digest = TeXLive::TLCrypto::tl_short_digest($location);
     my $loc_copy_of_remote_tlpdb =
-      ($is_main ? 
+      ($is_main ?
         "$Master/$InfraLocation/texlive.tlpdb.main.$loc_digest" :
         "$Master/$InfraLocation/texlive.tlpdb.$loc_digest");
     ddebug("loc_digest = $loc_digest\n");
@@ -7369,7 +7371,7 @@ FROZEN
   if (!$local_copy_tlpdb_used && $location =~ m;^(https?|ftp)://;) {
     my $loc_digest = TeXLive::TLCrypto::tl_short_digest($location);
     my $loc_copy_of_remote_tlpdb =
-      ($is_main ? 
+      ($is_main ?
         "$Master/$InfraLocation/texlive.tlpdb.main.$loc_digest" :
         "$Master/$InfraLocation/texlive.tlpdb.$loc_digest");
     my $tlfh;
@@ -7439,7 +7441,7 @@ sub load_config_file {
   chomp (my $TEXMFSYSCONFIG = `kpsewhich -var-value=TEXMFSYSCONFIG`);
   my $fnsys = "$TEXMFSYSCONFIG/tlmgr/config";
   my $tlmgr_sys_config_file = TeXLive::TLConfFile->new($fnsys, "#", "=");
-  load_options_from_config($tlmgr_sys_config_file, 'sys') 
+  load_options_from_config($tlmgr_sys_config_file, 'sys')
     if $tlmgr_sys_config_file;
 
   chomp (my $TEXMFCONFIG = `kpsewhich -var-value=TEXMFCONFIG`);
@@ -7652,12 +7654,12 @@ sub logcommand {
 }
 
 
-# resolve relative paths from tlpdb wrt tlroot 
+# resolve relative paths from tlpdb wrt tlroot
 sub norm_tlpdb_path {
   my ($path) = @_;
   return if (!defined($path));
   $path =~ s!\\!/!;
-  # just return if absolute path 
+  # just return if absolute path
   return $path if ($path =~ m!^/|:!);
   init_local_db() unless defined($localtlpdb);
   return $localtlpdb->root . "/$path";
@@ -7960,7 +7962,7 @@ If the repository is on the network, trailing C</> cha
 =back
 
 If the repository is on the network, trailing C</> characters and/or
-trailing C</tlpkg> and/or C</archive> components are ignored.  
+trailing C</tlpkg> and/or C</archive> components are ignored.
 
 =item B<--gui> [I<action>]
 
@@ -7979,7 +7981,7 @@ TeX Live's Perl distribution for Windows. You may find
 
 However, the native GUI requires Perl/TK, which is no longer included in
 TeX Live's Perl distribution for Windows. You may find C<tlshell> or
-C<tlcockpit> easier to work with. 
+C<tlcockpit> easier to work with.
 
 
 =for comment Keep language list in sync with install-tl.
@@ -8246,7 +8248,7 @@ out).
 the given configuration file is entirely removed (not just commented
 out).
 
-If I<value> is given in addition, I<key> is set to I<value> in the 
+If I<value> is given in addition, I<key> is set to I<value> in the
 respective file.  I<No error checking is done!>
 
 The C<PATH> value shown by C<conf> is as used by C<tlmgr>.  The
@@ -8256,7 +8258,7 @@ enabled during installation, you can disable it afterw
 Here is a practical example of changing configuration values. If the
 execution of (some or all) system commands via C<\write18> was left
 enabled during installation, you can disable it afterwards:
-  
+
   tlmgr conf texmf shell_escape 0
 
 The subcommand C<auxtrees> allows adding and removing arbitrary
@@ -8371,7 +8373,7 @@ one of these:
   %!NAME
   --!NAME
 
-where C<language.dat> and C<language.def> use C<%>, 
+where C<language.dat> and C<language.def> use C<%>,
 and C<language.dat.lua> use C<-->.  In all cases, the I<name> is
 the respective format name or hyphenation pattern identifier.
 Examples:
@@ -8502,7 +8504,7 @@ C<--only-installed> and C<--only-remote> cannot both b
 
 =item B<--data C<item1,item2,...>>
 
-If the option C<--data> is given, its argument must be a comma or colon 
+If the option C<--data> is given, its argument must be a comma or colon
 separated list of field names from: C<name>, C<category>, C<localrev>,
 C<remoterev>, C<shortdesc>, C<longdesc>, C<installed>, C<size>,
 C<relocatable>, C<depends>, C<cat-version>, C<cat-date>, C<cat-license>,
@@ -8827,7 +8829,7 @@ is issued that the caller does not have enough privile
 
 =back
 
-=head2 pinning 
+=head2 pinning
 
 The C<pinning> action manages the pinning file, see L</Pinning> below.
 
@@ -8870,8 +8872,8 @@ I<platform> to the installation from the repository.
 C<platform add> I<platform>... adds the executables for each given platform
 I<platform> to the installation from the repository.
 
-C<platform remove> I<platform>... removes the executables for each given 
-platform I<platform> from the installation, but keeps the currently 
+C<platform remove> I<platform>... removes the executables for each given
+platform I<platform> from the installation, but keeps the currently
 running platform in any case.
 
 C<platform set> I<platform> switches TeX Live to always use the given
@@ -8879,7 +8881,7 @@ C<platform set auto> switches TeX Live to auto detecti
 
 C<platform set auto> switches TeX Live to auto detection mode for platform.
 
-Platform detection is needed to select the proper C<xz> and 
+Platform detection is needed to select the proper C<xz> and
 C<wget> binaries that are shipped with TeX Live.
 
 C<arch> is a synonym for C<platform>.
@@ -9061,7 +9063,7 @@ extending to the end of line.
 = a textual description of the verification status, as the last field
 extending to the end of line.
 
-=back 
+=back
 
 That is, in normal (not machine-readable) output, the third field
 (numeric verification status) is not present.
@@ -9081,7 +9083,7 @@ Restore a package from a previously-made backup.
 
 Restore a package from a previously-made backup.
 
-If C<--all> is given, try to restore the latest revision of all 
+If C<--all> is given, try to restore the latest revision of all
 package backups found in the backup directory.
 
 Otherwise, if neither I<pkg> nor I<rev> are given, list the available
@@ -9314,7 +9316,7 @@ Concisely list the packages which would be updated, ne
 =item B<--list> [I<pkg>]
 
 Concisely list the packages which would be updated, newly installed, or
-removed, without actually changing anything. 
+removed, without actually changing anything.
 If C<--all> is also given, all available updates are listed.
 If C<--self> is given, but not C<--all>, only updates to the
 critical packages (tlmgr, texlive infrastructure, perl on Windows, etc.)
@@ -9343,7 +9345,7 @@ supported in these circumstances.
 removed package, C<tlmgr> quits with an error message.  Excludes are not
 supported in these circumstances.
 
-This option can also be set permanently in the tlmgr config file with 
+This option can also be set permanently in the tlmgr config file with
 the key C<update-exclude>.
 
 =item B<--no-auto-remove> [I<pkg>...]
@@ -9426,7 +9428,7 @@ See above under L<install|/install [I<option>...] I<pk
 
 =item B<--force>
 
-Force update of normal packages, without updating C<tlmgr> itself 
+Force update of normal packages, without updating C<tlmgr> itself
 (unless the C<--self> option is also given).  Not recommended.
 
 Also, C<update --list> is still performed regardless of this option.
@@ -9658,7 +9660,7 @@ just as in normal mode.
 In user mode, these actions check that all packages to be acted on are
 installed in the user tree before proceeding; otherwise, they behave
 just as in normal mode.
- 
+
 =head2 User mode generate, option, paper
 
 In user mode, these actions operate only on the user tree's
@@ -9666,7 +9668,7 @@ configuration files and/or C<texlive.tlpdb>.
 
 =head2 User mode logs
 
-In user mode, C<tlmgr.log> and <tlmgr-commands.log> are written in the 
+In user mode, C<tlmgr.log> and <tlmgr-commands.log> are written in the
 C<TEXMFVAR/web2c/> directlry instead of C<TEXMFSYSVAR/web2c/>.
 
 =head1 MULTIPLE REPOSITORIES
@@ -10006,7 +10008,7 @@ information it needs by reading stdout.
 written to stdout).  The idea is that a program can get all the
 information it needs by reading stdout.
 
-Currently this option only applies to the 
+Currently this option only applies to the
 L<update|/update [I<option>...] [I<pkg>...]>,
 L<install|/install [I<option>...] I<pkg>...>, and
 L</option> actions.
@@ -10031,7 +10033,7 @@ downloaded, i.e., the size of the compressed tar file 
 revision numbers in the local installation and server repository,
 respectively.  The I<size> field is the number of bytes to be
 downloaded, i.e., the size of the compressed tar file for a network
-installation, not the unpacked size. The runtime and esttot fields 
+installation, not the unpacked size. The runtime and esttot fields
 are only present for updated and auto-install packages, and contain
 the currently passed time since start of installation/updates
 and the estimated total time.
@@ -10179,7 +10181,7 @@ If xz is available (either from the system or TL) and 
 =item 4.
 
 If xz is available (either from the system or TL) and working, use that.
-  
+
 =back
 
 lz4 and gzip are faster in creating tlmgr's local backups, hence they
