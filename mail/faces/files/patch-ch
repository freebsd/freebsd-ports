*** compface/file.c	Tue Jan 15 23:58:46 2002
--- /home/lkoeller/tmp/ports/mail/faces/work/faces/compface/file.c	Sun Jan 19 19:35:35 2003
***************
*** 16,147 ****
  
  #include "compface.h"
  
  void
! BigRead(char *fbuf)
  {
!     int c;
  
!     while (*fbuf != '\0') {
          c = *(fbuf++);
!         if ((c < FIRSTPRINT) || (c > LASTPRINT)) {
              continue;
-         }
          BigMul(NUMPRINTS);
          BigAdd((WORD)(c - FIRSTPRINT));
      }
  }
  
- 
  void
! BigWrite(char *fbuf)
  {
      static WORD tmp;
      static char buf[DIGITS];
!     char *s;
!     int i;
  
      s = buf;
!     while (B.b_words > 0) {
          BigDiv(NUMPRINTS, &tmp);
          *(s++) = tmp + FIRSTPRINT;
      }
!     i = 7;              /* Leave room for the field name on the first line */
      *(fbuf++) = ' ';
!     while (s-- > buf) {
!         if (i == 0) {
              *(fbuf++) = ' ';
-         }
          *(fbuf++) = *s;
!         if (++i >= MAXLINELEN) {
              *(fbuf++) = '\n';
              i = 0;
          }
      }
!     if (i > 0) {
          *(fbuf++) = '\n';
-     }
      *(fbuf++) = '\0';
  }
  
- 
  void
! ReadFace(char *fbuf)
  {
!     int c, i;
!     char *s, *t;
  
      t = s = fbuf;
!     for (i = strlen(s); i > 0; i--) {
!         c = (int) *(s++);
!         if ((c >= '0') && (c <= '9')) {
!             if (t >= fbuf + DIGITS) {
                  status = ERR_EXCESS;
                  break;
              }
              *(t++) = c - '0';
!         } else if ((c >= 'A') && (c <= 'F')) {
!             if (t >= fbuf + DIGITS) {
                  status = ERR_EXCESS;
                  break;
              }
              *(t++) = c - 'A' + 10;
!         } else if ((c >= 'a') && (c <= 'f')) {
!             if (t >= fbuf + DIGITS) {
                  status = ERR_EXCESS;
                  break;
              }
              *(t++) = c - 'a' + 10;
-         } else if (((c == 'x') || (c == 'X')) && (t > fbuf) && (*(t-1) == 0)) {
-             t--;
          }
      }
!     if (t < fbuf + DIGITS) {
          longjmp(comp_env, ERR_INSUFF);
-     }
      s = fbuf;
      t = F;
      c = 1 << (BITSPERDIG - 1);
!     while (t < F + PIXELS) {
          *(t++) = (*s & c) ? 1 : 0;
!         if ((c >>= 1) == 0) {
              s++;
              c = 1 << (BITSPERDIG - 1);
          }
      }
  }
  
- 
  void
! WriteFace(char *fbuf)
  {
!     char *s, *t;
!     int i, bits, digits, words;
  
      s = F;
      t = fbuf;
      bits = digits = words = i = 0;
!     while (s < F + PIXELS) {
!         if ((bits == 0) && (digits == 0)) {
              *(t++) = '0';
              *(t++) = 'x';
          }
!         if (*(s++)) {
              i = i * 2 + 1;
!         } else {
              i *= 2;
          }
!         if (++bits == BITSPERDIG) {
!             *(t++) = *(i + HexDigits);
              bits = i = 0;
!             if (++digits == DIGSPERWORD) {
                  *(t++) = ',';
                  digits = 0;
!                 if (++words == WORDSPERLINE) {
                      *(t++) = '\n';
                      words = 0;
                  }
              }
          }
      }
      *(t++) = '\0';
  }
--- 15,191 ----
  
  #include "compface.h"
  
+ int xbitmap=0;
+ 
  void
! BigRead(fbuf)
! register char *fbuf;
  {
! 	register int c;
  
! 	while (*fbuf != '\0')
! 	{
  		c = *(fbuf++);
! 		if ((c < FIRSTPRINT) || (c > LASTPRINT))
  			continue;
  		BigMul(NUMPRINTS);
  		BigAdd((WORD)(c - FIRSTPRINT));
  	}
  }
  
  void
! BigWrite(fbuf)
! register char *fbuf;
  {
  	static WORD tmp;
  	static char buf[DIGITS];
! 	register char *s;
! 	register int i;
  
  	s = buf;
! 	while (B.b_words > 0)
! 	{
  		BigDiv(NUMPRINTS, &tmp);
  		*(s++) = tmp + FIRSTPRINT;
  	}
! 	i = 7;	/* leave room for the field name on the first line */
  	*(fbuf++) = ' ';
! 	while (s-- > buf)
! 	{
! 		if (i == 0)
  			*(fbuf++) = ' ';
  		*(fbuf++) = *s;
! 		if (++i >= MAXLINELEN)
! 		{
  			*(fbuf++) = '\n';
  			i = 0;
  		}
  	}
! 	if (i > 0)
  		*(fbuf++) = '\n';
  	*(fbuf++) = '\0';
  }
  
  void
! ReadFace(fbuf)
! char *fbuf;
  {
! 	register int c, i;
! 	register char *s, *t;
  
  	t = s = fbuf;
! 	for(i = strlen(s); i > 0; i--)
! 	{
! 		c = (int)*(s++);
! 		if ((c >= '0') && (c <= '9'))
! 		{
! 			if (t >= fbuf + DIGITS)
! 			{
  				status = ERR_EXCESS;
  				break;
  			}
  			*(t++) = c - '0';
! 		}
! 		else if ((c >= 'A') && (c <= 'F'))
! 		{
! 			if (t >= fbuf + DIGITS)
! 			{
  				status = ERR_EXCESS;
  				break;
  			}
  			*(t++) = c - 'A' + 10;
! 		}
! 		else if ((c >= 'a') && (c <= 'f'))
! 		{
! 			if (t >= fbuf + DIGITS)
! 			{
  				status = ERR_EXCESS;
  				break;
  			}
  			*(t++) = c - 'a' + 10;
  		}
+ 		else if (((c == 'x') || (c == 'X')) && (t > fbuf) && (*(t-1) == 0))
+ 			t--;
  	}
! 	if (t < fbuf + DIGITS)
  		longjmp(comp_env, ERR_INSUFF);
  	s = fbuf;
  	t = F;
  	c = 1 << (BITSPERDIG - 1);
! 	while (t < F + PIXELS)
! 	{
  		*(t++) = (*s & c) ? 1 : 0;
! 		if ((c >>= 1) == 0)
! 		{
  			s++;
  			c = 1 << (BITSPERDIG - 1);
  		}
  	}
  }
  
  void
! WriteFace(fbuf)
! char *fbuf;
  {
! 	register char *s, *t;
! 	register int i, bits, digits, words;
! 	extern int xbitmap;
! 	int digsperword = DIGSPERWORD;
! 	int wordsperline = WORDSPERLINE;
  
  	s = F;
  	t = fbuf;
  	bits = digits = words = i = 0;
! 	if (xbitmap) {
! 		sprintf(t,"#define noname_width 48\n#define noname_height 48\nstatic char noname_bits[] = {\n ");
! 		while (*t) t++;
! 		digsperword = 2;
! 		wordsperline = 15;
! 	}
! 	while (s < F + PIXELS)
! 	{
! 		if ((bits == 0) && (digits == 0))
! 		{
  			*(t++) = '0';
  			*(t++) = 'x';
  		}
! 		if (xbitmap) {
! 			if (*(s++))
! 				i = (i >> 1) | 0x8;
! 			else
! 				i >>= 1;
! 		}
! 		else {
! 			if (*(s++))
  				i = i * 2 + 1;
! 			else
  				i *= 2;
  		}
! 		if (++bits == BITSPERDIG)
! 		{
! 			if (xbitmap) {
! 				t++;
! 				t[-(digits & 1) * 2] = *(i + HexDigits);
! 			}
! 			else *(t++) = *(i + HexDigits);
  			bits = i = 0;
! 			if (++digits == digsperword)
! 			{
! 				if (xbitmap && (s >= F + PIXELS)) break;
  				*(t++) = ',';
  				digits = 0;
! 				if (++words == wordsperline)
! 				{
  					*(t++) = '\n';
+ 					if (xbitmap) *(t++) = ' ';
  					words = 0;
  				}
  			}
  		}
  	}
+ 	if (xbitmap) {
+ 		sprintf(t, "}\n");
+ 		while (*t) t++;
+ 	}
  	*(t++) = '\0';
  }
