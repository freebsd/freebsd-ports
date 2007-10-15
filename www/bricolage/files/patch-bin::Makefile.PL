*** bin/Makefile.PL.orig	Thu Oct 19 09:16:18 2006
--- bin/Makefile.PL	Tue Oct  9 06:17:34 2007
***************
*** 33,48 ****
  # Write out the Makefile
  WriteMakefile(NAME           => 'bric_bin',
  	      EXE_FILES      => \@EXE,
! 	      ( exists $CONFIG->{MODULE_DIR} ? 
! 		( INSTALLSITELIB => $CONFIG->{MODULE_DIR} ) :
! 		()),
! 	      ( exists $CONFIG->{BIN_DIR} ? 
! 		( INSTALLSCRIPT => $CONFIG->{BIN_DIR},
!                   INSTALLSITESCRIPT => $CONFIG->{BIN_DIR},
!                   INSTALLSITEBIN => $CONFIG->{BIN_DIR} ) :
! 		()),
! 	      ( exists $CONFIG->{MAN_DIR} ? 
! 		( INSTALLMAN1DIR => "$CONFIG->{MAN_DIR}/man1",
!                   INSTALLSITEMAN1DIR => "$CONFIG->{MAN_DIR}/man1") :
! 		()));
  
--- 33,37 ----
  # Write out the Makefile
  WriteMakefile(NAME           => 'bric_bin',
  	      EXE_FILES      => \@EXE,
! 		);
  
