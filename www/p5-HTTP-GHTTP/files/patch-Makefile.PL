*** Makefile.PL.orig	Sun Apr 29 18:31:49 2001
--- Makefile.PL	Sun Apr 29 18:32:01 2001
***************
*** 14,20 ****
  }
  
  my $DEBUG = delete $config{DEBUG};
! 
  # get libs and inc from gnome-config
  eval {
      print "running gnome-config... ";
--- 14,20 ----
  }
  
  my $DEBUG = delete $config{DEBUG};
! =item
  # get libs and inc from gnome-config
  eval {
      print "running gnome-config... ";
***************
*** 57,63 ****
  }
  
  have_library("ghttp", "ghttp_get_header_names");
! 
  WriteMakefile(
      'NAME'	=> 'HTTP::GHTTP',
      'VERSION_FROM' => 'GHTTP.pm', # finds $VERSION
--- 57,63 ----
  }
  
  have_library("ghttp", "ghttp_get_header_names");
! =cut
  WriteMakefile(
      'NAME'	=> 'HTTP::GHTTP',
      'VERSION_FROM' => 'GHTTP.pm', # finds $VERSION
