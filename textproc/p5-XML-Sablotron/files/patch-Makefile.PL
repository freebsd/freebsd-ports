*** Makefile.PL.orig	Sun Apr 29 14:54:12 2001
--- Makefile.PL	Sun Apr 29 14:55:07 2001
***************
*** 45,50 ****
--- 45,51 ----
  
  my $DEBUG = delete $config{DEBUG};
  
+ =item
  if (delete $config{CHARLIE}) {
      $config{LIBS} = "-L$ENV{CHARLIE_HOME}/lib -lsablot -lexpat";
      $config{INC} = '-I$(CHARLIE_HOME)/include';
***************
*** 96,101 ****
--- 97,103 ----
    \$ $^X Makefile.PL LIBS='-L/path/to/sablot/lib -lexpat -lsablot'
  
  DEATH
+ =cut
  
  WriteMakefile(
      NAME	=> 'XML::Sablotron',
