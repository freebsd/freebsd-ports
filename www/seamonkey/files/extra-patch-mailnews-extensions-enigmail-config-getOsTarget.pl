commit 49a1daf
Author: Patrick Brunschwig <patrick@enigmail.net>
Date:   Tue Jan 28 18:10:54 2014 +0100

    fixed detection of compiler type for better supporting cross-compilers
---
 config/getOsTarget.pl | 8 +++++---
 1 file changed, 5 insertions(+), 3 deletions(-)

diff --git config/getOsTarget.pl config/getOsTarget.pl
index 91285cd..cf4a233 100755
--- mailnews/extensions/enigmail/config/getOsTarget.pl
+++ mailnews/extensions/enigmail/config/getOsTarget.pl
@@ -9,13 +9,15 @@
 # -c : CPU and compiler type
 # -o : OS type
 
+use File::Basename;
+
 if ($#ARGV != 3) {
   exit (1);
 }
 
 my $srcOs = $ARGV[1];
 my $srcCpu = $ARGV[2];
-my $srcComp = $ARGV[3];
+my $srcComp = basename($ARGV[3]);
 
 my $targetOs = "";
 my $targetCpu = "";
@@ -95,10 +97,10 @@ else {
 if ($targetOs eq "WINNT") {
   $targetComp = "msvc";
 }
-if ($srcComp =~ /^gcc/) {
+elsif ($srcComp =~ /gcc/ || $srcComp =~ /clang/) {
   $targetComp = "gcc3";
 }
-elsif ($srcComp =~ /^cc/) {
+elsif ($srcComp =~ /cc/) {
   if ($targetOs eq "SunOS") {
     $targetComp = "sunc";
   }
@@ -107,6 +109,9 @@ elsif ($srcComp =~ /cc/) {
   elsif ($targetOs eq "AIX") {
     $targetComp = "ibmc";
   }
+  else {
+    $targetComp = "gcc3";
+  }
 }
 else {
   $targetComp = $srcComp;
