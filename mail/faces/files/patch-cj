*** compface/uncmain.c	Thu Feb 21 16:42:54 2002
--- /home/lkoeller/tmp/ports/mail/faces/work/faces/compface/uncmain.c	Sun Jan 19 19:35:35 2003
***************
*** 13,28 ****
   *  to me, then an attempt will be made to fix them.
   */
  
- #include <stdlib.h>
- #include <unistd.h>
  #include <fcntl.h>
  #include "compface.h"
  
! #define  STRCAT        (void) strcat
! #define  STRCPY        (void) strcpy
! #define  WRITE         (void) write
  
! /* The buffer is longer than needed to handle sparse input formats */
  #define FACEBUFLEN 2048
  char fbuf[FACEBUFLEN];
  
--- 15,26 ----
   *  to me, then an attempt will be made to fix them.
   */
  
  #include <fcntl.h>
  #include "compface.h"
  
! extern int xbitmap;
  
! /* the buffer is longer than needed to handle sparse input formats */
  #define FACEBUFLEN 2048
  char fbuf[FACEBUFLEN];
  
***************
*** 32,87 ****
  int outfile   = 1;
  char *outname = "<stdout>";
  
! char *cmdname;                 /* Basename of executable */
  
! /* Error handling definitions follow */
  
  extern int errno, sys_nerr;
  extern char *sys_errlist[];
  
  #define ERR         ((errno < sys_nerr) ? sys_errlist[errno] : "")
! #define INITERR(s)  { \
!                         STRCPY(fbuf, cmdname); \
!                         STRCAT(fbuf, ": "); \
!                         STRCAT(fbuf, (s));\
!                     }
! #define ADDERR(s)   STRCAT(fbuf, (s));
! #define ERROR       { \
!                         STRCAT(fbuf, "\n"); \
!                         WRITE(2, fbuf, strlen(fbuf)); \
!                         exit(1); \
!                     }
! #define INITWARN(s) { \
!                         STRCPY(fbuf, cmdname); \
!                         STRCAT(fbuf, ": (warning) "); \
!                         STRCAT(fbuf, (s)); \
!                     }
! #define ADDWARN(s)  STRCAT(fbuf, (s));
! #define WARN        { \
!                         STRCAT(fbuf, "\n"); \
!                         WRITE(2, fbuf, strlen(fbuf)); \
!                     }
  
  int
! main(int argc, char *argv[])
  {
      cmdname = *argv;
!     while (**argv) {
!         if (*((*argv)++) == '/') {
              cmdname = *argv;               /* find the command's basename */
!         }
      }
  
!     if (argc > 3) {
          INITERR("usage: ")
          ADDERR(cmdname)
          ADDERR(" [infile [outfile]]")
          ERROR
      }
  
!     if ((argc > 1) && strcmp(*++argv, "-")) {
          inname = *argv;
!         if ((infile = open(inname, O_RDONLY)) == -1) {
              INITERR(inname)
              ADDERR(": ")
              ADDERR(ERR)
--- 30,87 ----
  int outfile   = 1;
  char *outname = "<stdout>";
  
! /* basename of executable */
! char *cmdname;
  
! /* error handling definitions follow */
  
  extern int errno, sys_nerr;
  extern char *sys_errlist[];
  
+ extern void exit P((int)) ;
+ 
  #define ERR ((errno < sys_nerr) ? sys_errlist[errno] : "")
! #define INITERR(s) {(void)strcpy(fbuf, cmdname); (void)strcat(fbuf, ": ");\
! 					(void)strcat(fbuf, (s));}
! #define ADDERR(s) (void)strcat(fbuf, (s));
! #define ERROR {(void)strcat(fbuf, "\n");\
! 				(void)write(2, fbuf, strlen(fbuf)); exit(1);}
! #define INITWARN(s) {(void)strcpy(fbuf, cmdname);\
! 					(void)strcat(fbuf, ": (warning) ");\
! 					(void)strcat(fbuf, (s));}
! #define ADDWARN(s) (void)strcat(fbuf, (s));
! #define WARN {(void)strcat(fbuf, "\n"); (void)write(2, fbuf, strlen(fbuf));}
  
  int
! main(argc, argv)
! int argc;
! char *argv[];
  {
    cmdname = *argv;
!   while (**argv)
!     if (*((*argv)++) == '/')
        cmdname = *argv;               /* find the command's basename */
! 
!   if (argc > 1 && !strcmp(argv[1], "-X"))
!     {
!       xbitmap++;
!       argc--;
!       argv++;
      }
  
!   if (argc > 3)
!     {
        INITERR("usage: ")
        ADDERR(cmdname)
        ADDERR(" [infile [outfile]]")
        ERROR
      }
  
!   if ((argc > 1) && strcmp(*++argv, "-"))
!     {
        inname = *argv;
!       if ((infile = open(inname, O_RDONLY)) == -1)
!         {
            INITERR(inname)
            ADDERR(": ")
            ADDERR(ERR)
***************
*** 89,98 ****
          }
      }
  
!     if (argc > 2) {
          outname = *++argv;
!         if ((outfile = open(outname, O_WRONLY | O_CREAT | 
!                                      O_TRUNC, 0644)) == -1) {
              INITERR(outname)
              ADDERR(": ")
              ADDERR(ERR)
--- 89,99 ----
          }
      }
  
!   if (argc > 2)
!     {
        outname = *++argv;
!       if ((outfile = open(outname, O_WRONLY | O_CREAT | O_TRUNC, 0644)) == -1)
!         {
            INITERR(outname)
            ADDERR(": ")
            ADDERR(ERR)
***************
*** 101,107 ****
      }
  
      (void) ReadBuf();
!     switch (uncompface(fbuf)) {
          case -2 : INITERR("internal error")
                    ERROR
          case -1 : INITERR(inname)
--- 102,109 ----
      }
  
    (void) ReadBuf();
!   switch (uncompface(fbuf))
!     {
        case -2 : INITERR("internal error")
                  ERROR
        case -1 : INITERR(inname)
***************
*** 121,133 ****
  int
  WriteBuf()
  {
!     char *s, *t;
!     int len;
  
      s = fbuf;
      t = s + strlen(s);
!     while (s < t) {
!         if ((len = write(outfile, s, t - s)) == -1) {
              INITERR(outname)
              ADDERR(": ")
              ADDERR(ERR)
--- 123,137 ----
  int
  WriteBuf()
  {
! 	register char *s, *t;
! 	register int len;
  
  	s = fbuf;
  	t = s + strlen(s);
! 	while (s < t)
! 	{
! 		if ((len = write(outfile, s, t - s)) == -1)
! 		{
  			INITERR(outname)
  			ADDERR(": ")
  			ADDERR(ERR)
***************
*** 135,161 ****
          }
          s += len;
      }
!     return(0);
  }
  
  
  int
  ReadBuf()
  {
!     int count, len;
!     char *t;
  
      count = 0;
      t = fbuf;
!     while ((len = read(infile, t, FACEBUFLEN - count))) {
!         if (len == -1) {
              INITERR(inname)
              ADDERR(": ")
              ADDERR(ERR)
              ERROR
          }
          t += len;
!         if ((count += len) >= FACEBUFLEN) {
              INITWARN(inname)
              ADDWARN(" exceeds internal buffer size.  Data may be lost")
              WARN
--- 139,168 ----
  		}
  		s += len;
  	}
! 	return 0;
  }
  
  
  int
  ReadBuf()
  {
! 	register int count, len;
! 	register char *t;
  
  	count = 0;
  	t = fbuf;
! 	while (len = read(infile, t, FACEBUFLEN - count))
! 	{
! 		if (len == -1)
! 		{
  			INITERR(inname)
  			ADDERR(": ")
  			ADDERR(ERR)
  			ERROR
  		}
  		t += len;
! 		if ((count += len) >= FACEBUFLEN)
! 		{
  			INITWARN(inname)
  			ADDWARN(" exceeds internal buffer size.  Data may be lost")
  			WARN
***************
*** 163,167 ****
          }
      }
      *t = '\0';
!     return(count);
  }
--- 170,174 ----
  		}
  	}
  	*t = '\0';
! 	return count;
  }
