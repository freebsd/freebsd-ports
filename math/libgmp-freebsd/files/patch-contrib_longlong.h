--- contrib/longlong.h.orig	Sat Jul 19 02:31:07 2003
+++ contrib/longlong.h	Sat Jul 19 02:31:09 2003
@@ -106,8 +106,8 @@
 
 #if (defined (__a29k__) || defined (_AM29K)) && W_TYPE_SIZE == 32
 #define add_ssaaaa(sh, sl, ah, al, bh, bl) \
-  __asm__ ("add %1,%4,%5
-	addc %0,%2,%3"							\
+  __asm__ ("add %1,%4,%5 \n\t"						\
+	"addc %0,%2,%3"							\
 	   : "=r" ((USItype)(sh)),					\
 	    "=&r" ((USItype)(sl))					\
 	   : "%r" ((USItype)(ah)),					\
@@ -115,8 +115,8 @@
 	     "%r" ((USItype)(al)),					\
 	     "rI" ((USItype)(bl)))
 #define sub_ddmmss(sh, sl, ah, al, bh, bl) \
-  __asm__ ("sub %1,%4,%5
-	subc %0,%2,%3"							\
+  __asm__ ("sub %1,%4,%5 \n\t"						\
+	"subc %0,%2,%3"							\
 	   : "=r" ((USItype)(sh)),					\
 	     "=&r" ((USItype)(sl))					\
 	   : "r" ((USItype)(ah)),					\
@@ -173,8 +173,8 @@
 
 #if defined (__arm__) && W_TYPE_SIZE == 32
 #define add_ssaaaa(sh, sl, ah, al, bh, bl) \
-  __asm__ ("adds	%1, %4, %5
-	adc	%0, %2, %3"						\
+  __asm__ ("adds	%1, %4, %5 \n\t"					\
+	"adc	%0, %2, %3"						\
 	   : "=r" ((USItype)(sh)),					\
 	     "=&r" ((USItype)(sl))					\
 	   : "%r" ((USItype)(ah)),					\
@@ -182,8 +182,8 @@
 	     "%r" ((USItype)(al)),					\
 	     "rI" ((USItype)(bl)))
 #define sub_ddmmss(sh, sl, ah, al, bh, bl) \
-  __asm__ ("subs	%1, %4, %5
-	sbc	%0, %2, %3"						\
+  __asm__ ("subs	%1, %4, %5 \n\t"					\
+	"sbc	%0, %2, %3"						\
 	   : "=r" ((USItype)(sh)),					\
 	     "=&r" ((USItype)(sl))					\
 	   : "r" ((USItype)(ah)),					\
@@ -191,19 +191,19 @@
 	     "r" ((USItype)(al)),					\
 	     "rI" ((USItype)(bl)))
 #define umul_ppmm(xh, xl, a, b) \
-  __asm__ ("%@ Inlined umul_ppmm
-	mov	%|r0, %2, lsr #16
-	mov	%|r2, %3, lsr #16
-	bic	%|r1, %2, %|r0, lsl #16
-	bic	%|r2, %3, %|r2, lsl #16
-	mul	%1, %|r1, %|r2
-	mul	%|r2, %|r0, %|r2
-	mul	%|r1, %0, %|r1
-	mul	%0, %|r0, %0
-	adds	%|r1, %|r2, %|r1
-	addcs	%0, %0, #65536
-	adds	%1, %1, %|r1, lsl #16
-	adc	%0, %0, %|r1, lsr #16"					\
+  __asm__ ("%@ Inlined umul_ppmm \n\t"					\
+	"mov	%|r0, %2, lsr #16 \n\t"					\
+	"mov	%|r2, %3, lsr #16 \n\t"					\
+	"bic	%|r1, %2, %|r0, lsl #16 \n\t"				\
+	"bic	%|r2, %3, %|r2, lsl #16 \n\t"				\
+	"mul	%1, %|r1, %|r2 \n\t"				\
+	"mul	%|r2, %|r0, %|r2 \n\t"				\
+	"mul	%|r1, %0, %|r1 \n\t"				\
+	"mul	%0, %|r0, %0 \n\t"				\
+	"adds	%|r1, %|r2, %|r1 \n\t"				\
+	"addcs	%0, %0, #65536 \n\t"				\
+	"adds	%1, %1, %|r1, lsl #16 \n\t"				\
+	"adc	%0, %0, %|r1, lsr #16 \n\t"					\
 	   : "=&r" ((USItype)(xh)),					\
 	     "=r" ((USItype)(xl))					\
 	   : "r" ((USItype)(a)),					\
@@ -243,8 +243,8 @@
 
 #if defined (__gmicro__) && W_TYPE_SIZE == 32
 #define add_ssaaaa(sh, sl, ah, al, bh, bl) \
-  __asm__ ("add.w %5,%1
-	addx %3,%0"							\
+  __asm__ ("add.w %5,%1 \n\t"						\
+	"addx %3,%0"							\
 	   : "=g" ((USItype)(sh)),					\
 	     "=&g" ((USItype)(sl))					\
 	   : "%0" ((USItype)(ah)),					\
@@ -252,8 +252,8 @@
 	     "%1" ((USItype)(al)),					\
 	     "g" ((USItype)(bl)))
 #define sub_ddmmss(sh, sl, ah, al, bh, bl) \
-  __asm__ ("sub.w %5,%1
-	subx %3,%0"							\
+  __asm__ ("sub.w %5,%1 \n\t"						\
+	"subx %3,%0"							\
 	   : "=g" ((USItype)(sh)),					\
 	     "=&g" ((USItype)(sl))					\
 	   : "0" ((USItype)(ah)),					\
@@ -282,8 +282,8 @@
 
 #if defined (__hppa) && W_TYPE_SIZE == 32
 #define add_ssaaaa(sh, sl, ah, al, bh, bl) \
-  __asm__ ("add %4,%5,%1
-	addc %2,%3,%0"							\
+  __asm__ ("add %4,%5,%1 \n\t"						\
+	"addc %2,%3,%0"							\
 	   : "=r" ((USItype)(sh)),					\
 	     "=&r" ((USItype)(sl))					\
 	   : "%rM" ((USItype)(ah)),					\
@@ -291,8 +291,8 @@
 	     "%rM" ((USItype)(al)),					\
 	     "rM" ((USItype)(bl)))
 #define sub_ddmmss(sh, sl, ah, al, bh, bl) \
-  __asm__ ("sub %4,%5,%1
-	subb %2,%3,%0"							\
+  __asm__ ("sub %4,%5,%1 \n\t"						\
+	"subb %2,%3,%0"							\
 	   : "=r" ((USItype)(sh)),					\
 	     "=&r" ((USItype)(sl))					\
 	   : "rM" ((USItype)(ah)),					\
@@ -330,22 +330,22 @@
   do {									\
     USItype __tmp;							\
     __asm__ (								\
-       "ldi		1,%0
-	extru,=		%1,15,16,%%r0		; Bits 31..16 zero?
-	extru,tr	%1,15,16,%1		; No.  Shift down, skip add.
-	ldo		16(%0),%0		; Yes.  Perform add.
-	extru,=		%1,23,8,%%r0		; Bits 15..8 zero?
-	extru,tr	%1,23,8,%1		; No.  Shift down, skip add.
-	ldo		8(%0),%0		; Yes.  Perform add.
-	extru,=		%1,27,4,%%r0		; Bits 7..4 zero?
-	extru,tr	%1,27,4,%1		; No.  Shift down, skip add.
-	ldo		4(%0),%0		; Yes.  Perform add.
-	extru,=		%1,29,2,%%r0		; Bits 3..2 zero?
-	extru,tr	%1,29,2,%1		; No.  Shift down, skip add.
-	ldo		2(%0),%0		; Yes.  Perform add.
-	extru		%1,30,1,%1		; Extract bit 1.
-	sub		%0,%1,%0		; Subtract it.
-	" : "=r" (count), "=r" (__tmp) : "1" (x));			\
+       "ldi		1,%0 \n\t"						\
+	"extru,=		%1,15,16,%%r0		; Bits 31..16 zero? \n\t"\
+	"extru,tr	%1,15,16,%1		; No.  Shift down, skip add. \n\t"\
+	"ldo		16(%0),%0		; Yes.  Perform add. \n\t"\
+	"extru,=		%1,23,8,%%r0		; Bits 15..8 zero? \n\t"\
+	"extru,tr	%1,23,8,%1		; No.  Shift down, skip add. \n\t"\
+	"ldo		8(%0),%0		; Yes.  Perform add. \n\t"\
+	"extru,=		%1,27,4,%%r0		; Bits 7..4 zero? \n\t"\
+	"extru,tr	%1,27,4,%1		; No.  Shift down, skip add. \n\t"\
+	"ldo		4(%0),%0		; Yes.  Perform add. \n\t"\
+	"extru,=		%1,29,2,%%r0		; Bits 3..2 zero? \n\t"\
+	"extru,tr	%1,29,2,%1		; No.  Shift down, skip add. \n\t"\
+	"ldo		2(%0),%0		; Yes.  Perform add. \n\t"\
+	"extru		%1,30,1,%1		; Extract bit 1. \n\t"\
+	"sub		%0,%1,%0		; Subtract it."\
+	: "=r" (count), "=r" (__tmp) : "1" (x));			\
   } while (0)
 #endif /* hppa */
 
@@ -392,8 +392,8 @@
 
 #if (defined (__i386__) || defined (__i486__)) && W_TYPE_SIZE == 32
 #define add_ssaaaa(sh, sl, ah, al, bh, bl) \
-  __asm__ ("addl %5,%1
-	adcl %3,%0"							\
+  __asm__ ("addl %5,%1 \n\t"							\
+	"adcl %3,%0"							\
 	   : "=r" ((USItype)(sh)),					\
 	     "=&r" ((USItype)(sl))					\
 	   : "%0" ((USItype)(ah)),					\
@@ -401,8 +401,8 @@
 	     "%1" ((USItype)(al)),					\
 	     "g" ((USItype)(bl)))
 #define sub_ddmmss(sh, sl, ah, al, bh, bl) \
-  __asm__ ("subl %5,%1
-	sbbl %3,%0"							\
+  __asm__ ("subl %5,%1 \n\t"							\
+	"sbbl %3,%0"							\
 	   : "=r" ((USItype)(sh)),					\
 	     "=&r" ((USItype)(sl))					\
 	   : "0" ((USItype)(ah)),					\
@@ -514,8 +514,8 @@
 
 #if (defined (__mc68000__) || defined (__mc68020__) || defined (__NeXT__) || defined(mc68020)) && W_TYPE_SIZE == 32
 #define add_ssaaaa(sh, sl, ah, al, bh, bl) \
-  __asm__ ("add%.l %5,%1
-	addx%.l %3,%0"							\
+  __asm__ ("add%.l %5,%1 \n\t"						\
+	"addx%.l %3,%0"							\
 	   : "=d" ((USItype)(sh)),					\
 	     "=&d" ((USItype)(sl))					\
 	   : "%0" ((USItype)(ah)),					\
@@ -523,8 +523,8 @@
 	     "%1" ((USItype)(al)),					\
 	     "g" ((USItype)(bl)))
 #define sub_ddmmss(sh, sl, ah, al, bh, bl) \
-  __asm__ ("sub%.l %5,%1
-	subx%.l %3,%0"							\
+  __asm__ ("sub%.l %5,%1 \n\t"						\
+	"subx%.l %3,%0"							\
 	   : "=d" ((USItype)(sh)),					\
 	     "=&d" ((USItype)(sl))					\
 	   : "0" ((USItype)(ah)),					\
@@ -562,28 +562,28 @@
 #else /* not mc68020 */
 #define umul_ppmm(xh, xl, a, b) \
   do { USItype __umul_tmp1, __umul_tmp2;				\
-	__asm__ ("| Inlined umul_ppmm
-	move%.l	%5,%3
-	move%.l	%2,%0
-	move%.w	%3,%1
-	swap	%3
-	swap	%0
-	mulu	%2,%1
-	mulu	%3,%0
-	mulu	%2,%3
-	swap	%2
-	mulu	%5,%2
-	add%.l	%3,%2
-	jcc	1f
-	add%.l	%#0x10000,%0
-1:	move%.l	%2,%3
-	clr%.w	%2
-	swap	%2
-	swap	%3
-	clr%.w	%3
-	add%.l	%3,%1
-	addx%.l	%2,%0
-	| End inlined umul_ppmm"					\
+	__asm__ ("| Inlined umul_ppmm \n\t"					\
+	"move%.l	%5,%3 \n\t"					\
+	"move%.l	%2,%0 \n\t"					\
+	"move%.w	%3,%1 \n\t"					\
+	"swap	%3 \n\t"					\
+	"swap	%0 \n\t"					\
+	"mulu	%2,%1 \n\t"					\
+	"mulu	%3,%0 \n\t"					\
+	"mulu	%2,%3 \n\t"					\
+	"swap	%2 \n\t"					\
+	"mulu	%5,%2 \n\t"					\
+	"add%.l	%3,%2 \n\t"					\
+	"jcc	1f \n\t"					\
+	"add%.l	%#0x10000,%0 \n"					\
+"1:	move%.l	%2,%3 \n\t"					\
+	"clr%.w	%2 \n\t"					\
+	"swap	%2 \n\t"					\
+	"swap	%3 \n\t"					\
+	"clr%.w	%3 \n\t"					\
+	"add%.l	%3,%1 \n\t"					\
+	"addx%.l	%2,%0 \n\t"					\
+	"| End inlined umul_ppmm"					\
 	      : "=&d" ((USItype)(xh)), "=&d" ((USItype)(xl)),		\
 	        "=d" (__umul_tmp1), "=&d" (__umul_tmp2)			\
 	      : "%2" ((USItype)(a)), "d" ((USItype)(b)));		\
@@ -595,8 +595,8 @@
 
 #if defined (__m88000__) && W_TYPE_SIZE == 32
 #define add_ssaaaa(sh, sl, ah, al, bh, bl) \
-  __asm__ ("addu.co %1,%r4,%r5
-	addu.ci %0,%r2,%r3"						\
+  __asm__ ("addu.co %1,%r4,%r5 \n\t"						\
+	"addu.ci %0,%r2,%r3"						\
 	   : "=r" ((USItype)(sh)),					\
 	     "=&r" ((USItype)(sl))					\
 	   : "%rJ" ((USItype)(ah)),					\
@@ -604,8 +604,8 @@
 	     "%rJ" ((USItype)(al)),					\
 	     "rJ" ((USItype)(bl)))
 #define sub_ddmmss(sh, sl, ah, al, bh, bl) \
-  __asm__ ("subu.co %1,%r4,%r5
-	subu.ci %0,%r2,%r3"						\
+  __asm__ ("subu.co %1,%r4,%r5 \n\t"						\
+	"subu.ci %0,%r2,%r3"						\
 	   : "=r" ((USItype)(sh)),					\
 	     "=&r" ((USItype)(sl))					\
 	   : "rJ" ((USItype)(ah)),					\
@@ -663,9 +663,9 @@
 	     "d" ((USItype)(v)))
 #else
 #define umul_ppmm(w1, w0, u, v) \
-  __asm__ ("multu %2,%3
-	mflo %0
-	mfhi %1"							\
+  __asm__ ("multu %2,%3 \n\t"						\
+	"mflo %0 \n\t"							\
+	"mfhi %1"							\
 	   : "=d" ((USItype)(w0)),					\
 	     "=d" ((USItype)(w1))					\
 	   : "d" ((USItype)(u)),					\
@@ -685,9 +685,9 @@
 	     "d" ((UDItype)(v)))
 #else
 #define umul_ppmm(w1, w0, u, v) \
-  __asm__ ("dmultu %2,%3
-	mflo %0
-	mfhi %1"							\
+  __asm__ ("dmultu %2,%3 \n\t"						\
+	"mflo %0 \n\t"							\
+	"mfhi %1"							\
 	   : "=d" ((UDItype)(w0)),					\
 	     "=d" ((UDItype)(w1))					\
 	   : "d" ((UDItype)(u)),					\
@@ -855,8 +855,8 @@
 
 #if defined (__pyr__) && W_TYPE_SIZE == 32
 #define add_ssaaaa(sh, sl, ah, al, bh, bl) \
-  __asm__ ("addw	%5,%1
-	addwc	%3,%0"							\
+  __asm__ ("addw	%5,%1 \n\t"						\
+	"addwc	%3,%0"							\
 	   : "=r" ((USItype)(sh)),					\
 	     "=&r" ((USItype)(sl))					\
 	   : "%0" ((USItype)(ah)),					\
@@ -864,8 +864,8 @@
 	     "%1" ((USItype)(al)),					\
 	     "g" ((USItype)(bl)))
 #define sub_ddmmss(sh, sl, ah, al, bh, bl) \
-  __asm__ ("subw	%5,%1
-	subwb	%3,%0"							\
+  __asm__ ("subw	%5,%1 \n\t"						\
+	"subwb	%3,%0"							\
 	   : "=r" ((USItype)(sh)),					\
 	     "=&r" ((USItype)(sl))					\
 	   : "0" ((USItype)(ah)),					\
@@ -877,8 +877,8 @@
   ({union {UDItype __ll;						\
 	   struct {USItype __h, __l;} __i;				\
 	  } __xx;							\
-  __asm__ ("movw %1,%R0
-	uemul %2,%0"							\
+  __asm__ ("movw %1,%R0 \n\t"						\
+	"uemul %2,%0"							\
 	   : "=&r" (__xx.__ll)						\
 	   : "g" ((USItype) (u)),					\
 	     "g" ((USItype)(v)));					\
@@ -887,8 +887,8 @@
 
 #if defined (__ibm032__) /* RT/ROMP */  && W_TYPE_SIZE == 32
 #define add_ssaaaa(sh, sl, ah, al, bh, bl) \
-  __asm__ ("a %1,%5
-	ae %0,%3"							\
+  __asm__ ("a %1,%5 \n\t"							\
+	"ae %0,%3"							\
 	   : "=r" ((USItype)(sh)),					\
 	     "=&r" ((USItype)(sl))					\
 	   : "%0" ((USItype)(ah)),					\
@@ -896,8 +896,8 @@
 	     "%1" ((USItype)(al)),					\
 	     "r" ((USItype)(bl)))
 #define sub_ddmmss(sh, sl, ah, al, bh, bl) \
-  __asm__ ("s %1,%5
-	se %0,%3"							\
+  __asm__ ("s %1,%5 \n\t"							\
+	"se %0,%3"							\
 	   : "=r" ((USItype)(sh)),					\
 	     "=&r" ((USItype)(sl))					\
 	   : "0" ((USItype)(ah)),					\
@@ -908,26 +908,26 @@
   do {									\
     USItype __m0 = (m0), __m1 = (m1);					\
     __asm__ (								\
-       "s	r2,r2
-	mts	r10,%2
-	m	r2,%3
-	m	r2,%3
-	m	r2,%3
-	m	r2,%3
-	m	r2,%3
-	m	r2,%3
-	m	r2,%3
-	m	r2,%3
-	m	r2,%3
-	m	r2,%3
-	m	r2,%3
-	m	r2,%3
-	m	r2,%3
-	m	r2,%3
-	m	r2,%3
-	m	r2,%3
-	cas	%0,r2,r0
-	mfs	r10,%1"							\
+       "\t s	r2,r2 \n\t"							\
+	"mts	r10,%2 \n\t"							\
+	"m	r2,%3 \n\t"							\
+	"m	r2,%3 \n\t"							\
+	"m	r2,%3 \n\t"							\
+	"m	r2,%3 \n\t"							\
+	"m	r2,%3 \n\t"							\
+	"m	r2,%3 \n\t"							\
+	"m	r2,%3 \n\t"							\
+	"m	r2,%3 \n\t"							\
+	"m	r2,%3 \n\t"							\
+	"m	r2,%3 \n\t"							\
+	"m	r2,%3 \n\t"							\
+	"m	r2,%3 \n\t"							\
+	"m	r2,%3 \n\t"							\
+	"m	r2,%3 \n\t"							\
+	"m	r2,%3 \n\t"							\
+	"m	r2,%3 \n\t"							\
+	"cas	%0,r2,r0 \n\t"						\
+	"mfs	r10,%1"							\
 	     : "=r" ((USItype)(ph)),					\
 	       "=r" ((USItype)(pl))					\
 	     : "%r" (__m0),						\
@@ -957,9 +957,9 @@
 #if defined (__sh2__) && W_TYPE_SIZE == 32
 #define umul_ppmm(w1, w0, u, v) \
   __asm__ (								\
-       "dmulu.l	%2,%3
-	sts	macl,%1
-	sts	mach,%0"						\
+       "dmulu.l	%2,%3 \n\t"							\
+	"sts	macl,%1 \n\t"						\
+	"sts	mach,%0"						\
 	   : "=r" ((USItype)(w1)),					\
 	     "=r" ((USItype)(w0))					\
 	   : "r" ((USItype)(u)),					\
@@ -970,8 +970,8 @@
 
 #if defined (__sparc__) && W_TYPE_SIZE == 32
 #define add_ssaaaa(sh, sl, ah, al, bh, bl) \
-  __asm__ ("addcc %r4,%5,%1
-	addx %r2,%3,%0"							\
+  __asm__ ("addcc %r4,%5,%1 \n\t"						\
+	"addx %r2,%3,%0 \n\t"							\
 	   : "=r" ((USItype)(sh)),					\
 	     "=&r" ((USItype)(sl))					\
 	   : "%rJ" ((USItype)(ah)),					\
@@ -980,8 +980,8 @@
 	     "rI" ((USItype)(bl))					\
 	   __CLOBBER_CC)
 #define sub_ddmmss(sh, sl, ah, al, bh, bl) \
-  __asm__ ("subcc %r4,%5,%1
-	subx %r2,%3,%0"							\
+  __asm__ ("subcc %r4,%5,%1 \n\t"						\
+	"subx %r2,%3,%0"							\
 	   : "=r" ((USItype)(sh)),					\
 	     "=&r" ((USItype)(sl))					\
 	   : "rJ" ((USItype)(ah)),					\
@@ -1027,45 +1027,45 @@
 	     "r" ((USItype)(v)))
 #define UMUL_TIME 5
 #define udiv_qrnnd(q, r, n1, n0, d) \
-  __asm__ ("! Inlined udiv_qrnnd
-	wr	%%g0,%2,%%y	! Not a delayed write for sparclite
-	tst	%%g0
-	divscc	%3,%4,%%g1
-	divscc	%%g1,%4,%%g1
-	divscc	%%g1,%4,%%g1
-	divscc	%%g1,%4,%%g1
-	divscc	%%g1,%4,%%g1
-	divscc	%%g1,%4,%%g1
-	divscc	%%g1,%4,%%g1
-	divscc	%%g1,%4,%%g1
-	divscc	%%g1,%4,%%g1
-	divscc	%%g1,%4,%%g1
-	divscc	%%g1,%4,%%g1
-	divscc	%%g1,%4,%%g1
-	divscc	%%g1,%4,%%g1
-	divscc	%%g1,%4,%%g1
-	divscc	%%g1,%4,%%g1
-	divscc	%%g1,%4,%%g1
-	divscc	%%g1,%4,%%g1
-	divscc	%%g1,%4,%%g1
-	divscc	%%g1,%4,%%g1
-	divscc	%%g1,%4,%%g1
-	divscc	%%g1,%4,%%g1
-	divscc	%%g1,%4,%%g1
-	divscc	%%g1,%4,%%g1
-	divscc	%%g1,%4,%%g1
-	divscc	%%g1,%4,%%g1
-	divscc	%%g1,%4,%%g1
-	divscc	%%g1,%4,%%g1
-	divscc	%%g1,%4,%%g1
-	divscc	%%g1,%4,%%g1
-	divscc	%%g1,%4,%%g1
-	divscc	%%g1,%4,%%g1
-	divscc	%%g1,%4,%0
-	rd	%%y,%1
-	bl,a 1f
-	add	%1,%4,%1
-1:	! End of inline udiv_qrnnd"					\
+  __asm__ ("! Inlined udiv_qrnnd \n\t"					\
+	"wr	%%g0,%2,%%y	! Not a delayed write for sparclite \n\t" 	\
+	"tst	%%g0 \n\t"							\
+	"divscc	%3,%4,%%g1 \n\t"						\
+	"divscc	%%g1,%4,%%g1 \n\t"						\
+	"divscc	%%g1,%4,%%g1 \n\t"						\
+	"divscc	%%g1,%4,%%g1 \n\t"						\
+	"divscc	%%g1,%4,%%g1 \n\t"						\
+	"divscc	%%g1,%4,%%g1 \n\t"						\
+	"divscc	%%g1,%4,%%g1 \n\t"						\
+	"divscc	%%g1,%4,%%g1 \n\t"						\
+	"divscc	%%g1,%4,%%g1 \n\t"						\
+	"divscc	%%g1,%4,%%g1 \n\t"						\
+	"divscc	%%g1,%4,%%g1 \n\t"						\
+	"divscc	%%g1,%4,%%g1 \n\t"						\
+	"divscc	%%g1,%4,%%g1 \n\t"						\
+	"divscc	%%g1,%4,%%g1 \n\t"						\
+	"divscc	%%g1,%4,%%g1 \n\t"						\
+	"divscc	%%g1,%4,%%g1 \n\t"						\
+	"divscc	%%g1,%4,%%g1 \n\t"						\
+	"divscc	%%g1,%4,%%g1 \n\t"						\
+	"divscc	%%g1,%4,%%g1 \n\t"						\
+	"divscc	%%g1,%4,%%g1 \n\t"						\
+	"divscc	%%g1,%4,%%g1 \n\t"						\
+	"divscc	%%g1,%4,%%g1 \n\t"						\
+	"divscc	%%g1,%4,%%g1 \n\t"						\
+	"divscc	%%g1,%4,%%g1 \n\t"						\
+	"divscc	%%g1,%4,%%g1 \n\t"						\
+	"divscc	%%g1,%4,%%g1 \n\t"						\
+	"divscc	%%g1,%4,%%g1 \n\t"						\
+	"divscc	%%g1,%4,%%g1 \n\t"						\
+	"divscc	%%g1,%4,%%g1 \n\t"						\
+	"divscc	%%g1,%4,%%g1 \n\t"						\
+	"divscc	%%g1,%4,%%g1 \n\t"						\
+	"divscc	%%g1,%4,%0 \n\t"						\
+	"rd	%%y,%1 \n\t"						\
+	"bl,a 1f \n\t"							\
+	"add	%1,%4,%1 \n"						\
+"1:	! End of inline udiv_qrnnd"					\
 	   : "=r" ((USItype)(q)),					\
 	     "=r" ((USItype)(r))					\
 	   : "r" ((USItype)(n1)),					\
@@ -1085,46 +1085,46 @@
 /* Default to sparc v7 versions of umul_ppmm and udiv_qrnnd.  */
 #ifndef umul_ppmm
 #define umul_ppmm(w1, w0, u, v) \
-  __asm__ ("! Inlined umul_ppmm
-	wr	%%g0,%2,%%y	! SPARC has 0-3 delay insn after a wr
-	sra	%3,31,%%g2	! Don't move this insn
-	and	%2,%%g2,%%g2	! Don't move this insn
-	andcc	%%g0,0,%%g1	! Don't move this insn
-	mulscc	%%g1,%3,%%g1
-	mulscc	%%g1,%3,%%g1
-	mulscc	%%g1,%3,%%g1
-	mulscc	%%g1,%3,%%g1
-	mulscc	%%g1,%3,%%g1
-	mulscc	%%g1,%3,%%g1
-	mulscc	%%g1,%3,%%g1
-	mulscc	%%g1,%3,%%g1
-	mulscc	%%g1,%3,%%g1
-	mulscc	%%g1,%3,%%g1
-	mulscc	%%g1,%3,%%g1
-	mulscc	%%g1,%3,%%g1
-	mulscc	%%g1,%3,%%g1
-	mulscc	%%g1,%3,%%g1
-	mulscc	%%g1,%3,%%g1
-	mulscc	%%g1,%3,%%g1
-	mulscc	%%g1,%3,%%g1
-	mulscc	%%g1,%3,%%g1
-	mulscc	%%g1,%3,%%g1
-	mulscc	%%g1,%3,%%g1
-	mulscc	%%g1,%3,%%g1
-	mulscc	%%g1,%3,%%g1
-	mulscc	%%g1,%3,%%g1
-	mulscc	%%g1,%3,%%g1
-	mulscc	%%g1,%3,%%g1
-	mulscc	%%g1,%3,%%g1
-	mulscc	%%g1,%3,%%g1
-	mulscc	%%g1,%3,%%g1
-	mulscc	%%g1,%3,%%g1
-	mulscc	%%g1,%3,%%g1
-	mulscc	%%g1,%3,%%g1
-	mulscc	%%g1,%3,%%g1
-	mulscc	%%g1,0,%%g1
-	add	%%g1,%%g2,%0
-	rd	%%y,%1"							\
+  __asm__ ("! Inlined umul_ppmm \n\t"					\
+	"wr	%%g0,%2,%%y	! SPARC has 0-3 delay insn after a wr \n\t"	\
+	"sra	%3,31,%%g2	! Don't move this insn \n\t"			\
+	"and	%2,%%g2,%%g2	! Don't move this insn \n\t"			\
+	"andcc	%%g0,0,%%g1	! Don't move this insn \n\t"			\
+	"mulscc	%%g1,%3,%%g1 \n\t"						\
+	"mulscc	%%g1,%3,%%g1 \n\t"						\
+	"mulscc	%%g1,%3,%%g1 \n\t"						\
+	"mulscc	%%g1,%3,%%g1 \n\t"						\
+	"mulscc	%%g1,%3,%%g1 \n\t"						\
+	"mulscc	%%g1,%3,%%g1 \n\t"						\
+	"mulscc	%%g1,%3,%%g1 \n\t"						\
+	"mulscc	%%g1,%3,%%g1 \n\t"						\
+	"mulscc	%%g1,%3,%%g1 \n\t"						\
+	"mulscc	%%g1,%3,%%g1 \n\t"						\
+	"mulscc	%%g1,%3,%%g1 \n\t"						\
+	"mulscc	%%g1,%3,%%g1 \n\t"						\
+	"mulscc	%%g1,%3,%%g1 \n\t"						\
+	"mulscc	%%g1,%3,%%g1 \n\t"						\
+	"mulscc	%%g1,%3,%%g1 \n\t"						\
+	"mulscc	%%g1,%3,%%g1 \n\t"						\
+	"mulscc	%%g1,%3,%%g1 \n\t"						\
+	"mulscc	%%g1,%3,%%g1 \n\t"						\
+	"mulscc	%%g1,%3,%%g1 \n\t"						\
+	"mulscc	%%g1,%3,%%g1 \n\t"						\
+	"mulscc	%%g1,%3,%%g1 \n\t"						\
+	"mulscc	%%g1,%3,%%g1 \n\t"						\
+	"mulscc	%%g1,%3,%%g1 \n\t"						\
+	"mulscc	%%g1,%3,%%g1 \n\t"						\
+	"mulscc	%%g1,%3,%%g1 \n\t"						\
+	"mulscc	%%g1,%3,%%g1 \n\t"						\
+	"mulscc	%%g1,%3,%%g1 \n\t"						\
+	"mulscc	%%g1,%3,%%g1 \n\t"						\
+	"mulscc	%%g1,%3,%%g1 \n\t"						\
+	"mulscc	%%g1,%3,%%g1 \n\t"						\
+	"mulscc	%%g1,%3,%%g1 \n\t"						\
+	"mulscc	%%g1,%3,%%g1 \n\t"						\
+	"mulscc	%%g1,0,%%g1 \n\t"						\
+	"add	%%g1,%%g2,%0 \n\t"						\
+	"rd	%%y,%1"							\
 	   : "=r" ((USItype)(w1)),					\
 	     "=r" ((USItype)(w0))					\
 	   : "%rI" ((USItype)(u)),					\
@@ -1147,8 +1147,8 @@
 
 #if defined (__vax__) && W_TYPE_SIZE == 32
 #define add_ssaaaa(sh, sl, ah, al, bh, bl) \
-  __asm__ ("addl2 %5,%1
-	adwc %3,%0"							\
+  __asm__ ("addl2 %5,%1 \n\t"						\
+	"adwc %3,%0"							\
 	   : "=g" ((USItype)(sh)),					\
 	     "=&g" ((USItype)(sl))					\
 	   : "%0" ((USItype)(ah)),					\
@@ -1156,8 +1156,8 @@
 	     "%1" ((USItype)(al)),					\
 	     "g" ((USItype)(bl)))
 #define sub_ddmmss(sh, sl, ah, al, bh, bl) \
-  __asm__ ("subl2 %5,%1
-	sbwc %3,%0"							\
+  __asm__ ("subl2 %5,%1 \n\t"						\
+	"sbwc %3,%0"							\
 	   : "=g" ((USItype)(sh)),					\
 	     "=&g" ((USItype)(sl))					\
 	   : "0" ((USItype)(ah)),					\
