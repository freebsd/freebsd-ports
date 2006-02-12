*** inst/db_upgrade.pl.orig	Fri Sep 16 19:50:20 2005
--- inst/db_upgrade.pl	Fri Feb  3 19:47:06 2006
***************
*** 73,79 ****
      next unless -d $dir;
  
      opendir(DIR, $dir) or die "can't opendir $dir: $!";
!     my @scripts = grep { -f $_ } map { catfile($dir, $_) } sort readdir(DIR);
      closedir DIR;
  
      foreach my $script (@scripts) {
--- 73,79 ----
      next unless -d $dir;
  
      opendir(DIR, $dir) or die "can't opendir $dir: $!";
!     my @scripts = grep { -f $_ and $_ =~ /\.pl$/ } map { catfile($dir, $_) } sort readdir(DIR);
      closedir DIR;
  
      foreach my $script (@scripts) {
