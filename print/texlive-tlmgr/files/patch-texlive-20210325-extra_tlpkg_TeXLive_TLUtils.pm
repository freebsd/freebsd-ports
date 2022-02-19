--- texlive-20210325-extra/tlpkg/TeXLive/TLUtils.pm.orig	2021-03-05 00:26:37 UTC
+++ texlive-20210325-extra/tlpkg/TeXLive/TLUtils.pm
@@ -250,22 +250,14 @@ subsequent calls just return that value.
 
 sub platform {
   unless (defined $::_platform_) {
-    if ($^O =~ /^MSWin/i) {
-      $::_platform_ = "win32";
-    } else {
-      my $config_guess = "$::installerdir/tlpkg/installer/config.guess";
-
-      # We cannot rely on #! in config.guess but have to call /bin/sh
-      # explicitly because sometimes the 'noexec' flag is set in
-      # /etc/fstab for ISO9660 file systems.
-      chomp (my $guessed_platform = `/bin/sh '$config_guess'`);
-
-      # For example, if the disc or reader has hardware problems.
-      die "$0: could not run $config_guess, cannot proceed, sorry"
-        if ! $guessed_platform;
-
-      $::_platform_ = platform_name($guessed_platform);
-    }
+    chomp(my $uname_m = `uname -m`);
+    chomp(my $uname_r = `uname -r`);
+    chomp(my $uname_s = `uname -s`);
+    $uname_r =~ s/-.*$//;
+    $uname_s = lc($uname_s);
+    $guessed_platform = sprintf("%s-unknown-%s%s", $uname_m,
+        $uname_s, $uname_r);
+    $::_platform_ = platform_name($guessed_platform);
   }
   return $::_platform_;
 }
