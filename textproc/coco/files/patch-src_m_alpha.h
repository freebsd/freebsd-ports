diff -rBbc src/m/alpha.h src/m/alpha.h
*** src/m/alpha.h	Sat Aug 10 07:03:36 1996
--- src/m/alpha.h	Sat Dec 29 03:49:32 2001
***************
*** 234,240 ****
--- 234,244 ----
  
  #ifndef NOT_C_CODE
  /* We need these because pointers are larger than the default ints.  */
+ #if !defined(__FreeBSD__) && !defined(__NetBSD__) && !defined(__OpenBSD__)
  #include <alloca.h>
+ #else
+ #include <stdlib.h>
+ #endif
  
  /* Hack alert!  For reasons unknown to mankind the string.h file insists
     on defining bcopy etc. as taking char pointers as arguments.  With
***************
*** 299,308 ****
     termio and struct termios are mutually incompatible.  */
  #define NO_TERMIO
  
! #ifdef LINUX
  # define TEXT_END ({ extern int _etext; &_etext; })
  # ifndef __ELF__
  #  define COFF
  #  define DATA_END ({ extern int _EDATA; &_EDATA; })
  # endif /* notdef __ELF__ */
  #endif
--- 303,320 ----
     termio and struct termios are mutually incompatible.  */
  #define NO_TERMIO
  
! #if defined(LINUX) || \
! 	defined(__FreeBSD__) || defined (__NetBSD__) || defined (__OpenBSD__)
  # define TEXT_END ({ extern int _etext; &_etext; })
  # ifndef __ELF__
  #  define COFF
  #  define DATA_END ({ extern int _EDATA; &_EDATA; })
  # endif /* notdef __ELF__ */
  #endif
+ 
+ #if (defined (__FreeBSD__) || defined (__NetBSD__) || defined (__OpenBSD__)) \
+ 	&& defined (__ELF__)
+ #define HAVE_TEXT_START
+ #endif
+ 
+ 
