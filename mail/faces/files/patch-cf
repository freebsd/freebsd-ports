*** compface/compress.c	Tue Jan 15 23:58:46 2002
--- /home/lkoeller/tmp/ports/mail/faces/work/faces/compface/compress.c	Wed Jun 19 08:29:13 1991
***************
*** 17,113 ****
  #include "compface.h"
  
  int
! Same(char *f, int wid, int hei)
  {
! 	char val, *row;
! 	int x;
  
  	val = *f;
! 	while (hei--) {
  		row = f;
  		x = wid;
! 		while (x--) {
! 			if (*(row++) != val) {
  				return(0);
-             }
-         }
  		f += WIDTH;
  	}
! 	return(1);
  }
  
- 
  int
! AllBlack(char *f, int wid, int hei)
  {
! 	if (wid > 3) {
  		wid /= 2;
  		hei /= 2;
! 		return(AllBlack(f, wid, hei) && AllBlack(f + wid, wid, hei) &&
  		       AllBlack(f + WIDTH * hei, wid, hei) &&
  		       AllBlack(f + WIDTH * hei + wid, wid, hei));
- 	} else {
- 		return(*f || *(f + 1) || *(f + WIDTH) || *(f + WIDTH + 1));
      }
  }
  
- 
  int
! AllWhite(char *f, int wid, int hei)
  {
! 	return((*f == 0) && Same(f, wid, hei));
  }
  
- 
  void
! PopGreys(char *f, int wid, int hei)
  {
! 	if (wid > 3) {
  		wid /= 2;
  		hei /= 2;
  		PopGreys(f, wid, hei);
  		PopGreys(f + wid, wid, hei);
  		PopGreys(f + WIDTH * hei, wid, hei);
  		PopGreys(f + WIDTH * hei + wid, wid, hei);
! 	} else {
  		wid = BigPop(freqs);
! 		if (wid & 1) {
  			*f = 1;
!         }
! 		if (wid & 2) {
  			*(f + 1) = 1;
!         }
! 		if (wid & 4) {
  			*(f + WIDTH) = 1;
!         }
! 		if (wid & 8) {
  			*(f + WIDTH + 1) = 1;
          }
- 	}
  }
  
- 
  void
! PushGreys(char *f, int wid, int hei)
  {
! 	if (wid > 3) {
  		wid /= 2;
  		hei /= 2;
  		PushGreys(f, wid, hei);
  		PushGreys(f + wid, wid, hei);
  		PushGreys(f + WIDTH * hei, wid, hei);
  		PushGreys(f + WIDTH * hei + wid, wid, hei);
- 	} else {
- 		RevPush(freqs + *f + 2 * *(f + 1) + 
-                 4 * *(f + WIDTH) + 8 * *(f + WIDTH + 1));
      }
  }
  
- 
  void
! UnCompress(char *f, int wid, int hei, int lev)
  {
! 	switch (BigPop(&levels[lev][0])) {
  		case WHITE :
  			return;
  		case BLACK :
--- 16,120 ----
  #include "compface.h"
  
  int
! Same(f, wid, hei)
! register char *f;
! register int wid, hei;
  {
! 	register char val, *row;
! 	register int x;
  
  	val = *f;
! 	while (hei--)
! 	{
  		row = f;
  		x = wid;
! 		while (x--)
! 			if (*(row++) != val)
  				return(0);
  		f += WIDTH;
  	}
! 	return 1;
  }
  
  int
! AllBlack(f, wid, hei)
! char *f;
! int wid, hei;
  {
! 	if (wid > 3)
! 	{
  		wid /= 2;
  		hei /= 2;
! 		return (AllBlack(f, wid, hei) && AllBlack(f + wid, wid, hei) &&
  		  AllBlack(f + WIDTH * hei, wid, hei) &&
  		  AllBlack(f + WIDTH * hei + wid, wid, hei));
  	}
+ 	else
+ 		return (*f || *(f + 1) || *(f + WIDTH) || *(f + WIDTH + 1));
  }
  
  int
! AllWhite(f, wid, hei)
! char *f;
! int wid, hei;
  {
! 	return ((*f == 0) && Same(f, wid, hei));
  }
  
  void
! PopGreys(f, wid, hei)
! char *f;
! int wid, hei;
  {
! 	if (wid > 3)
! 	{
  		wid /= 2;
  		hei /= 2;
  		PopGreys(f, wid, hei);
  		PopGreys(f + wid, wid, hei);
  		PopGreys(f + WIDTH * hei, wid, hei);
  		PopGreys(f + WIDTH * hei + wid, wid, hei);
! 	}
! 	else
! 	{
  		wid = BigPop(freqs);
! 		if (wid & 1)
  			*f = 1;
! 		if (wid & 2)
  			*(f + 1) = 1;
! 		if (wid & 4)
  			*(f + WIDTH) = 1;
! 		if (wid & 8)
  			*(f + WIDTH + 1) = 1;
  	}
  }
  
  void
! PushGreys(f, wid, hei)
! char *f;
! int wid, hei;
  {
! 	if (wid > 3)
! 	{
  		wid /= 2;
  		hei /= 2;
  		PushGreys(f, wid, hei);
  		PushGreys(f + wid, wid, hei);
  		PushGreys(f + WIDTH * hei, wid, hei);
  		PushGreys(f + WIDTH * hei + wid, wid, hei);
  	}
+ 	else
+ 		RevPush(freqs + *f + 2 * *(f + 1) + 4 * *(f + WIDTH) +
+ 		  8 * *(f + WIDTH + 1));
  }
  
  void
! UnCompress(f, wid, hei, lev)
! register char *f;
! register int wid, hei, lev;
  {
! 	switch (BigPop(&levels[lev][0]))
! 	{
  		case WHITE :
  			return;
  		case BLACK :
***************
*** 125,139 ****
  	}
  }
  
- 
  void
! Compress(char *f, int wid, int hei, int lev)
  {
! 	if (AllWhite(f, wid, hei)) {
  		RevPush(&levels[lev][WHITE]);
  		return;
  	}
! 	if (AllBlack(f, wid, hei)) {
  		RevPush(&levels[lev][BLACK]);
  		PushGreys(f, wid, hei);
  		return;
--- 132,149 ----
  	}
  }
  
  void
! Compress(f, wid, hei, lev)
! register char *f;
! register int wid, hei, lev;
  {
! 	if (AllWhite(f, wid, hei))
! 	{
  		RevPush(&levels[lev][WHITE]);
  		return;
  	}
! 	if (AllBlack(f, wid, hei))
! 	{
  		RevPush(&levels[lev][BLACK]);
  		PushGreys(f, wid, hei);
  		return;
***************
*** 149,164 ****
  }
  
  void
! UnCompAll(char *fbuf)
  {
! 	char *p;
  
  	BigClear();
  	BigRead(fbuf);
  	p = F;
! 	while (p < F + PIXELS) {
  		*(p++) = 0;
-     }
  	UnCompress(F, 16, 16, 0);
  	UnCompress(F + 16, 16, 16, 0);
  	UnCompress(F + 32, 16, 16, 0);
--- 159,174 ----
  }
  
  void
! UnCompAll(fbuf)
! char *fbuf;
  {
! 	register char *p;
  
  	BigClear();
  	BigRead(fbuf);
  	p = F;
! 	while (p < F + PIXELS)
  		*(p++) = 0;
  	UnCompress(F, 16, 16, 0);
  	UnCompress(F + 16, 16, 16, 0);
  	UnCompress(F + 32, 16, 16, 0);
***************
*** 171,177 ****
  }
  
  void
! CompAll(char *fbuf)
  {
  	Compress(F, 16, 16, 0);
  	Compress(F + 16, 16, 16, 0);
--- 181,188 ----
  }
  
  void
! CompAll(fbuf)
! char *fbuf;
  {
  	Compress(F, 16, 16, 0);
  	Compress(F + 16, 16, 16, 0);
***************
*** 183,190 ****
  	Compress(F + WIDTH * 32 + 16, 16, 16, 0);
  	Compress(F + WIDTH * 32 + 32, 16, 16, 0);
  	BigClear();
! 	while (NumProbs > 0) {
  		BigPush(ProbBuf[--NumProbs]);
-     }
  	BigWrite(fbuf);
  }
--- 194,200 ----
  	Compress(F + WIDTH * 32 + 16, 16, 16, 0);
  	Compress(F + WIDTH * 32 + 32, 16, 16, 0);
  	BigClear();
! 	while (NumProbs > 0)
  		BigPush(ProbBuf[--NumProbs]);
  	BigWrite(fbuf);
  }
