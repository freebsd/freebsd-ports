diff -rBbc src/unexelf1.c src/unexelf1.c
*** src/unexelf1.c	Sat Aug 10 06:56:52 1996
--- src/unexelf1.c	Sat Dec 29 03:49:32 2001
***************
*** 423,434 ****
  #include <elf.h>
  #include <sys/mman.h>
  
! #ifdef __alpha__
  # include <sym.h>	/* get COFF debugging symbol table declaration */
  #endif
  
  #if __GNU_LIBRARY__ - 0 >= 6
  # include <link.h>	/* get ElfW etc */
  #endif
  
  #ifndef ElfW
--- 423,472 ----
  #include <elf.h>
  #include <sys/mman.h>
  
! #if defined(__alpha__) && defined(__osf__)
  # include <sym.h>	/* get COFF debugging symbol table declaration */
+ #else if defined(__alpha__)
+ typedef struct {
+ 	short magic;
+ 	short vstamp;
+ 	int ilineMax;
+ 	int idnMax;
+ 	int ipdMax;
+ 	int isymMax;
+ 	int ioptMax;
+ 	int iauxMax;
+ 	int issMax;
+ 	int issExtMax;
+ 	int ifdMax;
+ 	int crfd;
+ 	int iextMax;
+ 	long cbLine;
+ 	long cbLineOffset;
+ 	long cbDnOffset;
+ 	long cbPdOffset;
+ 	long cbSymOffset;
+ 	long cbOptOffset;
+ 	long cbAuxOffset;
+ 	long cbSsOffset;
+ 	long cbSsExtOffset;
+ 	long cbFdOffset;
+ 	long cbRfdOffset;
+ 	long cbExtOffset;
+ } HDRR, *pHDRR; 
+ #define cbHDRR sizeof(HDRR)
+ #define hdrNil ((pHDRR)0)
  #endif
  
  #if __GNU_LIBRARY__ - 0 >= 6
  # include <link.h>	/* get ElfW etc */
+ #endif
+ 
+ #ifdef __FreeBSD__
+ # ifdef __STDC__
+ #  define ElfW(type)	Elf_##type
+ # else
+ #  define ElfW(type)	Elf_/**/type
+ # endif
  #endif
  
  #ifndef ElfW
