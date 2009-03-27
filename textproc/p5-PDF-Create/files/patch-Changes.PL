--- Changes.PL.orig	2009-03-23 23:50:18.000000000 +0000
+++ Changes.PL	2009-03-27 09:12:48.000000000 +0000
@@ -3,12 +3,39 @@
 # Changes.PL
 #
 # Create the 'Changes' file automatically from git commit messages
-# and versioning tags in the repository
+# and versioning tags in the repository.
+#
+# This script is designed to be run only on the PDF::Create maintainers
+# workstation and is not needed to install PDF::Create.
+#
 
 use strict;
 
-open(OUT, ">Changes") or die "Can not open 'Changes' for writing\n";
-open(IN,"git log --abbrev-commit --pretty |") or die "Can not run git\n";
+#
+# Bail out with non-alarming error message if git ot the correct repository
+# is missing.
+#
+
+my $user;
+my $git=`which git`;
+chomp $git;
+if (! (-f $git)) {
+  printf "Skipping... (git not found/installed)\n";
+  exit (0);
+}
+
+if (! ($user=`git config --get user.name 2>/dev/null`)) {
+  printf "Skipping... (git not found/installed)\n";
+  exit (0);
+}
+chop $user;
+if ("$user" ne "Markus Baertschi") {
+  printf "Skipping... (not on maintainers workstation)\n";
+  exit (0);
+}
+
+open(OUT,">Changes") or die "Can not open 'Changes' for writing\n";
+open(IN,"git log --abbrev-commit --pretty |") or die "Problem running git log\n";
 while(<IN>){
   # read the change log
   if (/^commit /) {
