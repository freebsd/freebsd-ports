diff -rBbc src/s/freebsd.h src/s/freebsd.h
*** src/s/freebsd.h	Mon Jun 10 05:14:32 1996
--- src/s/freebsd.h	Sat Dec 29 03:49:32 2001
***************
*** 1,5 ****
--- 1,15 ----
  /* s/ file for freebsd system.  */
  
+ /* Get the correct __FreeBSD_version, even if this is before that was
+    defined. */
+ #ifndef __FreeBSD__
+ #define __FreeBSD_version 199401
+ #elif __FreeBSD__ == 1
+ #define __FreeBSD_version 199405
+ #else
+ #include <osreldate.h>
+ #endif
+ 
  /* '__FreeBSD__' is defined by the preprocessor on FreeBSD-1.1 and up.
     Earlier versions do not have shared libraries, so inhibit them.
     You can inhibit them on newer systems if you wish
***************
*** 32,40 ****
  #define PENDING_OUTPUT_COUNT(FILE) ((FILE)->_p - (FILE)->_bf._base)
  
  #define LIBS_DEBUG
! #define LIBS_SYSTEM -lutil
  #define LIBS_TERMCAP -ltermcap
! #define LIB_GCC -lgcc
  
  #define SYSV_SYSTEM_DIR
  
--- 42,58 ----
  #define PENDING_OUTPUT_COUNT(FILE) ((FILE)->_p - (FILE)->_bf._base)
  
  #define LIBS_DEBUG
! #define LIBS_SYSTEM -lutil -lcrypt
! #if __FreeBSD_version < 400000
  #define LIBS_TERMCAP -ltermcap
! #else
! #ifdef HAVE_LIBNCURSES
! #define TERMINFO
! #define LIBS_TERMCAP -lncurses
! #else
! #define LIBS_TERMCAP -ltermcap
! #endif
! #endif
  
  #define SYSV_SYSTEM_DIR
  
***************
*** 42,53 ****
  #undef BSD_PGRPS
  #define GETPGRP_NO_ARG
  
  #ifndef NO_SHARED_LIBS
  #define LD_SWITCH_SYSTEM -e start -dc -dp
  #define HAVE_TEXT_START		/* No need to define `start_of_text'. */
  #define START_FILES pre-crt0.o /usr/lib/crt0.o
! #define UNEXEC unexsunos4.o
  #define RUN_TIME_REMAP
  
  #ifndef N_TRELOFF
  #define N_PAGSIZ(x) __LDPGSZ
--- 60,92 ----
  #undef BSD_PGRPS
  #define GETPGRP_NO_ARG
  
+ #ifdef __ELF__
+ 
+ #define LD_SWITCH_SYSTEM
+ #ifdef i386
+ #define START_FILES pre-crt0.o /usr/lib/crt1.o /usr/lib/crti.o /usr/lib/crtbegin.o
+ #define LIB_STANDARD -lgcc -lc -lgcc /usr/lib/crtend.o /usr/lib/crtn.o
+ #else
+ #define START_FILES pre-crt0.o /usr/lib/crt1.o /usr/lib/crtbegin.o
+ #define LIB_STANDARD -lgcc -lc -lgcc /usr/lib/crtend.o
+ #endif
+ #define UNEXEC unexelf.o
+ #undef LIB_GCC
+ #define LIB_GCC
+ 
+ #else /* not __ELF__ */
+ 
  #ifndef NO_SHARED_LIBS
  #define LD_SWITCH_SYSTEM -e start -dc -dp
  #define HAVE_TEXT_START		/* No need to define `start_of_text'. */
+ #if __FreeBSD_version >= 300002
+ #define START_FILES pre-crt0.o /usr/lib/aout/crt0.o
+ #else /* __FreeBSD_version < 300002 */
  #define START_FILES pre-crt0.o /usr/lib/crt0.o
! #endif /* __FreeBSD_version < 300002 */
! #define UNEXEC unexfreebsd.o
  #define RUN_TIME_REMAP
+ #define LIB_GCC -lgcc
  
  #ifndef N_TRELOFF
  #define N_PAGSIZ(x) __LDPGSZ
***************
*** 63,68 ****
--- 102,109 ----
  #endif /* __FreeBSD__ */
  #endif /* NO_SHARED_LIBS */
  
+ #endif /* not __ELF__ */
+ 
  #define HAVE_WAIT_HEADER
  #define HAVE_GETLOADAVG
  /*#define HAVE_GETPAGESIZE  /* configure now puts this in config.h */
***************
*** 80,85 ****
--- 121,128 ----
  #define BSD 199103
  #elif __FreeBSD__ == 2
  #define BSD 199306
+ #elif __FreeBSD__ >= 3
+ #define BSD 199506
  #endif
  
  #define WAITTYPE int
***************
*** 97,99 ****
--- 140,145 ----
     It is already a controlling terminal of subprocess, because we did
     ioctl TIOCSCTTY.  */
  #define DONT_REOPEN_PTY
+ 
+ /* XIM does not work very well, so the next is set (by taoka@FreeBSD.org) */
+ #define X_I18N_INHIBITED
