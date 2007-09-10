--- scripts/localnetMAC.pl.in.orig	Sat Jul 14 00:01:55 2007
+++ scripts/localnetMAC.pl.in	Sat Jul 14 00:03:48 2007
@@ -50,10 +50,10 @@
 
 my $fh;
 if ($args{r} and $args{r}=~/gz$/){
-    open (IN, "$decomp $args{r} |../aux/adtrace/adtrace -|") or die "cannot execute $decomp $args{r} |../aux/adtrace/adtrace - : $!\n";
+    open (IN, "$decomp $args{r} |@prefix@/bin/adtrace -|") or die "cannot execute $decomp $args{r} |@prefix@/bin/adtrace - : $!\n";
     $fh = *IN;
 }elsif($args{r}){
-    open (IN, "../aux/adtrace/adtrace $args{r}|") or die "cannot execute ./adtrace/adtrace $args{r}: $!\n";
+    open (IN, "@prefix@/bin/adtrace $args{r}|") or die "cannot execute @prefix@/bin/adtrace $args{r}: $!\n";
     $fh = *IN;
 }elsif($args{t} and $args{t}=~/gz$/){
     open (IN, "$decomp $args{t} |") or die "cannot execute $decomp $args{t} | : $!\n";
