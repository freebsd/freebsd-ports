*** Makefile.PL.orig	Sun Nov 12 19:53:55 2000
--- Makefile.PL	Sun Nov 12 19:54:08 2000
***************
*** 58,64 ****
      VERSION_FROM => 'Sablotron.pm', 
      DEFINE	=> '-DPERL_POLLUTE',
      INC         => $include,
!     LIBS	=> ["$libpth -lsablot -lxmlparse -lxmltok"], 
      clean     => {'FILES' => "log.xsl", },
  );
  
--- 58,64 ----
      VERSION_FROM => 'Sablotron.pm', 
      DEFINE	=> '-DPERL_POLLUTE',
      INC         => $include,
!     LIBS	=> ["$libpth -lsablot -lexpat -lgcc"], 
      clean     => {'FILES' => "log.xsl", },
  );
  
