*** compface/compface.h	Thu Feb 21 16:42:54 2002
--- /home/lkoeller/tmp/ports/mail/faces/work/faces/compface/compface.h	Thu Sep  5 07:24:42 1991
***************
*** 14,45 ****
   *  to me, then an attempt will be made to fix them.
   */
  
  #include <string.h>
  #include <fcntl.h>
  #include <setjmp.h>
  
! /* Need to know how many bits per hexadecimal digit for io */
  #define BITSPERDIG 4
! extern char HexDigits[];
  
! /* Define the face size - 48x48x1 */
  #define WIDTH  48
  #define HEIGHT WIDTH
  
! /* Total number of pixels and digits */
  #define PIXELS (WIDTH * HEIGHT)
  #define DIGITS (PIXELS / BITSPERDIG)
  
! extern char F[PIXELS];
  
! /* Output formatting word lengths and line lengths */
  #define DIGSPERWORD  4
  #define WORDSPERLINE (WIDTH / DIGSPERWORD / BITSPERDIG)
  
! /* Compressed output uses the full range of printable characters.
   * in ascii these are in a contiguous block so we just need to know
!  * the first and last.  The total number of printables is needed too.
!  */
  #define FIRSTPRINT '!'
  #define LASTPRINT  '~'
  #define NUMPRINTS  (LASTPRINT - FIRSTPRINT + 1)
--- 13,64 ----
   *  to me, then an attempt will be made to fix them.
   */
  
+ #if defined(SYSV32) || defined(hpux)
  #include <string.h>
+ #else
+ #include <strings.h>
+ #endif /* SYSV32 || hpux */
  #include <fcntl.h>
  #include <setjmp.h>
  
! /* For all function declarations, if ANSI then use a prototype. */
! 
! #if  defined(__STDC__)
! #define P(args)  args
! #else  /* ! __STDC__ */
! #define P(args)  ()
! #endif  /* STDC */
! 
! #ifdef MAIN
! #define EXTERN
! #define INIT(x) = x
! #else
! #define EXTERN extern
! #define INIT(x)
! #endif
! 
! /* need to know how many bits per hexadecimal digit for io */
  #define BITSPERDIG 4
! EXTERN char HexDigits[] INIT("0123456789ABCDEF");
  
! /* define the face size - 48x48x1 */
  #define WIDTH 48
  #define HEIGHT WIDTH
  
! /* total number of pixels and digits */
  #define PIXELS (WIDTH * HEIGHT)
  #define DIGITS (PIXELS / BITSPERDIG)
  
! /* internal face representation - 1 char per pixel is faster */
! EXTERN char F[PIXELS];
  
! /* output formatting word lengths and line lengths */
  #define DIGSPERWORD 4
  #define WORDSPERLINE (WIDTH / DIGSPERWORD / BITSPERDIG)
  
! /* compressed output uses the full range of printable characters.
   * in ascii these are in a contiguous block so we just need to know
!  * the first and last.  The total number of printables is needed too */
  #define FIRSTPRINT '!'
  #define LASTPRINT '~'
  #define NUMPRINTS (LASTPRINT - FIRSTPRINT + 1)
***************
*** 49,56 ****
  
  /* Portable, very large unsigned integer arithmetic is needed.
   * Implementation uses arrays of WORDs.  COMPs must have at least
!  * twice as many bits as WORDs to handle intermediate results.
!  */
  #define WORD        unsigned char
  #define COMP        unsigned long
  #define BITSPERWORD 8
--- 68,74 ----
  
  /* Portable, very large unsigned integer arithmetic is needed.
   * Implementation uses arrays of WORDs.  COMPs must have at least
!  * twice as many bits as WORDs to handle intermediate results */
  #define WORD unsigned char
  #define COMP unsigned long
  #define BITSPERWORD 8
***************
*** 64,76 ****
      WORD b_word[MAXWORDS];
  } BigInt;
  
! extern BigInt B;
  
  /* This is the guess the next pixel table.  Normally there are 12 neighbour
   * pixels used to give 1<<12 cases but in the upper left corner lesser
!  * numbers of neighbours are available, leading to 6231 different guesses.
!  */
! typedef struct guesses {
      char g_00[1<<12];
      char g_01[1<<7];
      char g_02[1<<2];
--- 82,94 ----
  	WORD b_word[MAXWORDS];
  } BigInt;
  
! EXTERN BigInt B;
  
  /* This is the guess the next pixel table.  Normally there are 12 neighbour
   * pixels used to give 1<<12 cases but in the upper left corner lesser
!  * numbers of neighbours are available, leading to 6231 different guesses */
! typedef struct guesses
! {
  	char g_00[1<<12];
  	char g_01[1<<7];
  	char g_02[1<<2];
***************
*** 88,155 ****
      char g_42[1<<2];
  } Guesses;
  
! extern Guesses G;
  
  /* Data of varying probabilities are encoded by a value in the range 0 - 255.
   * The probability of the data determines the range of possible encodings.
!  * Offset gives the first possible encoding of the range.
!  */
! typedef struct prob {
      WORD p_range;
      WORD p_offset;
  } Prob;
  
! extern Prob *ProbBuf[PIXELS * 2];
! extern int NumProbs;
  
  /* Each face is encoded using 9 octrees of 16x16 each.  Each level of the
   * trees has varying probabilities of being white, grey or black.
!  * The table below is based on sampling many faces.
!  */
  
  #define BLACK 0
  #define GREY  1
  #define WHITE 2
  
! extern Prob levels[4][3];
! extern Prob freqs[16];
  
  #define ERR_OK        0     /* successful completion */
  #define ERR_EXCESS    1     /* completed OK but some input was ignored */
  #define ERR_INSUFF    -1    /* insufficient input.  Bad face format? */
  #define ERR_INTERNAL  -2    /* Arithmetic overflow or buffer overflow */
  
! extern int status;
  
! extern jmp_buf comp_env;
  
! int AllBlack(char *, int, int);
! int AllWhite(char *, int, int);
! int BigPop(Prob *);
! int compface(char *);
! int main(int, char *[]);
! int ReadBuf();
! int Same(char *, int, int);
! int uncompface(char *);
! int WriteBuf();
! 
! void BigAdd(WORD);
! void BigClear();
! void BigDiv(WORD, WORD *);
! void BigMul(WORD);
! void BigPrint();
! void BigPush(Prob *);
! void BigRead(char *);
! void BigSub(WORD);
! void BigWrite(char *);
! void CompAll(char *);
! void Compress(char *, int, int, int);
! void GenFace();
! void PopGreys(char *, int, int);
! void PushGreys(char *, int, int);
! void ReadFace(char *);
! void RevPush(Prob *);
! void UnCompAll(char *);
! void UnCompress(char *, int, int, int);
! void UnGenFace();
! void WriteFace(char *);
--- 106,204 ----
  	char g_42[1<<2];
  } Guesses;
  
! /* data.h was established by sampling over 1000 faces and icons */
! EXTERN Guesses G
! #ifdef MAIN
! =
! #include "data.h"
! #endif
! ;
  
  /* Data of varying probabilities are encoded by a value in the range 0 - 255.
   * The probability of the data determines the range of possible encodings.
!  * Offset gives the first possible encoding of the range */
! typedef struct prob
! {
  	WORD p_range;
  	WORD p_offset;
  } Prob;
  
! /* A stack of probability values */
! EXTERN Prob *ProbBuf[PIXELS * 2];
! EXTERN int NumProbs INIT(0);
  
  /* Each face is encoded using 9 octrees of 16x16 each.  Each level of the
   * trees has varying probabilities of being white, grey or black.
!  * The table below is based on sampling many faces */
  
  #define BLACK 0
  #define GREY 1
  #define WHITE 2
  
! EXTERN Prob levels[4][3]
! #ifdef MAIN
! =
! {
! 	{{1, 255},	{251, 0},	{4, 251}},	/* Top of tree almost always grey */
! 	{{1, 255},	{200, 0},	{55, 200}},
! 	{{33, 223},	{159, 0},	{64, 159}},
! 	{{131, 0},	{0, 0}, 	{125, 131}}	/* Grey disallowed at bottom */
! }
! #endif
! ;
! 
! /* At the bottom of the octree 2x2 elements are considered black if any
!  * pixel is black.  The probabilities below give the distribution of the
!  * 16 possible 2x2 patterns.  All white is not really a possibility and
!  * has a probability range of zero.  Again, experimentally derived data */
! EXTERN Prob freqs[16]
! #ifdef MAIN
! =
! {
! 	{0, 0}, 	{38, 0},	{38, 38},	{13, 152},
! 	{38, 76},	{13, 165},	{13, 178},	{6, 230},
! 	{38, 114},	{13, 191},	{13, 204},	{6, 236},
! 	{13, 217},	{6, 242},	{5, 248},	{3, 253}
! }
! #endif
! ;
  
  #define ERR_OK		0	/* successful completion */
  #define ERR_EXCESS	1	/* completed OK but some input was ignored */
  #define ERR_INSUFF	-1	/* insufficient input.  Bad face format? */
  #define ERR_INTERNAL	-2	/* Arithmetic overflow or buffer overflow */
  
! EXTERN int status;
  
! EXTERN jmp_buf comp_env;
  
! int AllBlack P((char *, int, int)) ;
! int AllWhite P((char *, int, int)) ;
! int BigPop P((Prob *)) ;
! int compface P((char *)) ;
! int main P((int, char *[])) ;
! int ReadBuf P(()) ;
! int Same P((char *, int, int)) ;
! int uncompface P((char *)) ;
! int WriteBuf P(()) ;
! 
! void BigAdd P((unsigned char)) ;
! void BigClear P(()) ;
! void BigDiv P((unsigned char, unsigned char *)) ;
! void BigMul P((unsigned char)) ;
! void BigPrint P(()) ;
! void BigPush P((Prob *)) ;
! void BigRead P((char *)) ;
! void BigSub P((unsigned int)) ;
! void BigWrite P((char *)) ;
! void CompAll P((char *)) ;
! void Compress P((char *, int, int, int)) ;
! void GenFace P(()) ;
! void PopGreys P((char *, int, int)) ;
! void PushGreys P((char *, int, int)) ;
! void ReadFace P((char *)) ;
! void RevPush P((Prob *)) ;
! void UnCompAll P((char *)) ;
! void UnCompress P((char *, int, int, int)) ;
! void UnGenFace P(()) ;
! void WriteFace P((char *)) ;
