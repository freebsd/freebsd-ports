diff -crN Sablotron/Makefile.PL.orig Sablotron/Makefile.PL
*** Sablotron/Makefile.PL.orig	Sun Jun 17 15:10:21 2001
--- Sablotron/Makefile.PL	Sun Jun 17 15:11:07 2001
***************
*** 5,11 ****
      'NAME'		=> 'XML::Sablotron::DOM',
      'VERSION_FROM'	=> 'DOM.pm', # finds $VERSION
      'PREREQ_PM'		=> {}, # e.g., Module::Name => 1.1
!     'LIBS'		=> ['-L/home/pavel/sablot/lib -lsablot'], # e.g., '-lm'
      'DEFINE'		=> '', # e.g., '-DHAVE_SOMETHING'
!     'INC'		=> '', # e.g., '-I/usr/include/other'
  );
--- 5,11 ----
      'NAME'		=> 'XML::Sablotron::DOM',
      'VERSION_FROM'	=> 'DOM.pm', # finds $VERSION
      'PREREQ_PM'		=> {}, # e.g., Module::Name => 1.1
!     'LIBS'		=> ['-L%%PREFIX%%/lib -lsablot'],
      'DEFINE'		=> '', # e.g., '-DHAVE_SOMETHING'
!     'INC'		=> '-I%%PREFIX%%/include',
  );
