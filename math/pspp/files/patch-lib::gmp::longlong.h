--- lib/gmp/longlong.h.orig	Wed Oct 15 06:11:33 2003
+++ lib/gmp/longlong.h	Wed Oct 15 06:23:05 2003
@@ -112,7 +112,7 @@
 
 #if (defined (__a29k__) || defined (_AM29K)) && W_TYPE_SIZE == 32
 #define add_ssaaaa(sh, sl, ah, al, bh, bl) \
-  __asm__ ("add %1,%4,%5
+  __asm__ ("add %1,%4,%5						\n\
 	addc %0,%2,%3"							\
 	   : "=r" ((USItype)(sh)),					\
 	    "=&r" ((USItype)(sl))					\
@@ -121,7 +121,7 @@
 	     "%r" ((USItype)(al)),					\
 	     "rI" ((USItype)(bl)))
 #define sub_ddmmss(sh, sl, ah, al, bh, bl) \
-  __asm__ ("sub %1,%4,%5
+  __asm__ ("sub %1,%4,%5 \n\
 	subc %0,%2,%3"							\
 	   : "=r" ((USItype)(sh)),					\
 	     "=&r" ((USItype)(sl))					\
@@ -179,7 +179,7 @@
 
 #if defined (__arm__) && W_TYPE_SIZE == 32
 #define add_ssaaaa(sh, sl, ah, al, bh, bl) \
-  __asm__ ("adds	%1, %4, %5
+  __asm__ ("adds	%1, %4, %5 \n\
 	adc	%0, %2, %3"						\
 	   : "=r" ((USItype)(sh)),					\
 	     "=&r" ((USItype)(sl))					\
@@ -188,7 +188,7 @@
 	     "%r" ((USItype)(al)),					\
 	     "rI" ((USItype)(bl)))
 #define sub_ddmmss(sh, sl, ah, al, bh, bl) \
-  __asm__ ("subs	%1, %4, %5
+  __asm__ ("subs	%1, %4, %5 \n\
 	sbc	%0, %2, %3"						\
 	   : "=r" ((USItype)(sh)),					\
 	     "=&r" ((USItype)(sl))					\
@@ -197,18 +197,18 @@
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
+  __asm__ ("%@ Inlined umul_ppmm \n\
+	mov	%|r0, %2, lsr #16 \n\
+	mov	%|r2, %3, lsr #16 \n\
+	bic	%|r1, %2, %|r0, lsl #16 \n\
+	bic	%|r2, %3, %|r2, lsl #16 \n\
+	mul	%1, %|r1, %|r2 \n\
+	mul	%|r2, %|r0, %|r2 \n\
+	mul	%|r1, %0, %|r1 \n\
+	mul	%0, %|r0, %0 \n\
+	adds	%|r1, %|r2, %|r1 \n\
+	addcs	%0, %0, #65536 \n\
+	adds	%1, %1, %|r1, lsl #16 \n\
 	adc	%0, %0, %|r1, lsr #16"					\
 	   : "=&r" ((USItype)(xh)),					\
 	     "=r" ((USItype)(xl))					\
@@ -249,7 +249,7 @@
 
 #if defined (__gmicro__) && W_TYPE_SIZE == 32
 #define add_ssaaaa(sh, sl, ah, al, bh, bl) \
-  __asm__ ("add.w %5,%1
+  __asm__ ("add.w %5,%1 \n\
 	addx %3,%0"							\
 	   : "=g" ((USItype)(sh)),					\
 	     "=&g" ((USItype)(sl))					\
@@ -258,7 +258,7 @@
 	     "%1" ((USItype)(al)),					\
 	     "g" ((USItype)(bl)))
 #define sub_ddmmss(sh, sl, ah, al, bh, bl) \
-  __asm__ ("sub.w %5,%1
+  __asm__ ("sub.w %5,%1 \n\
 	subx %3,%0"							\
 	   : "=g" ((USItype)(sh)),					\
 	     "=&g" ((USItype)(sl))					\
@@ -288,7 +288,7 @@
 
 #if defined (__hppa) && W_TYPE_SIZE == 32
 #define add_ssaaaa(sh, sl, ah, al, bh, bl) \
-  __asm__ ("add %4,%5,%1
+  __asm__ ("add %4,%5,%1 \n\
 	addc %2,%3,%0"							\
 	   : "=r" ((USItype)(sh)),					\
 	     "=&r" ((USItype)(sl))					\
@@ -297,7 +297,7 @@
 	     "%rM" ((USItype)(al)),					\
 	     "rM" ((USItype)(bl)))
 #define sub_ddmmss(sh, sl, ah, al, bh, bl) \
-  __asm__ ("sub %4,%5,%1
+  __asm__ ("sub %4,%5,%1 \n\
 	subb %2,%3,%0"							\
 	   : "=r" ((USItype)(sh)),					\
 	     "=&r" ((USItype)(sl))					\
@@ -336,21 +336,21 @@
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
+       "ldi		1,%0\n\
+	extru,=		%1,15,16,%%r0		; Bits 31..16 zero?\n\
+	extru,tr	%1,15,16,%1		; No.  Shift down, skip add.\n\
+	ldo		16(%0),%0		; Yes.  Perform add.\n\
+	extru,=		%1,23,8,%%r0		; Bits 15..8 zero?\n\
+	extru,tr	%1,23,8,%1		; No.  Shift down, skip add.\n\
+	ldo		8(%0),%0		; Yes.  Perform add.\n\
+	extru,=		%1,27,4,%%r0		; Bits 7..4 zero?\n\
+	extru,tr	%1,27,4,%1		; No.  Shift down, skip add.\n\
+	ldo		4(%0),%0		; Yes.  Perform add.\n\
+	extru,=		%1,29,2,%%r0		; Bits 3..2 zero?\n\
+	extru,tr	%1,29,2,%1		; No.  Shift down, skip add.\n\
+	ldo		2(%0),%0		; Yes.  Perform add.\n\
+	extru		%1,30,1,%1		; Extract bit 1.\n\
+	sub		%0,%1,%0		; Subtract it.\n\
 	" : "=r" (count), "=r" (__tmp) : "1" (x));			\
   } while (0)
 #endif /* hppa */
@@ -398,7 +398,7 @@
 
 #if (defined (__i386__) || defined (__i486__)) && W_TYPE_SIZE == 32
 #define add_ssaaaa(sh, sl, ah, al, bh, bl) \
-  __asm__ ("addl %5,%1
+  __asm__ ("addl %5,%1 \n\
 	adcl %3,%0"							\
 	   : "=r" ((USItype)(sh)),					\
 	     "=&r" ((USItype)(sl))					\
@@ -407,7 +407,7 @@
 	     "%1" ((USItype)(al)),					\
 	     "g" ((USItype)(bl)))
 #define sub_ddmmss(sh, sl, ah, al, bh, bl) \
-  __asm__ ("subl %5,%1
+  __asm__ ("subl %5,%1 \n\
 	sbbl %3,%0"							\
 	   : "=r" ((USItype)(sh)),					\
 	     "=&r" ((USItype)(sl))					\
@@ -520,7 +520,7 @@
 
 #if (defined (__mc68000__) || defined (__mc68020__) || defined (__NeXT__) || defined(mc68020)) && W_TYPE_SIZE == 32
 #define add_ssaaaa(sh, sl, ah, al, bh, bl) \
-  __asm__ ("add%.l %5,%1
+  __asm__ ("add%.l %5,%1 \n\
 	addx%.l %3,%0"							\
 	   : "=d" ((USItype)(sh)),					\
 	     "=&d" ((USItype)(sl))					\
@@ -529,7 +529,7 @@
 	     "%1" ((USItype)(al)),					\
 	     "g" ((USItype)(bl)))
 #define sub_ddmmss(sh, sl, ah, al, bh, bl) \
-  __asm__ ("sub%.l %5,%1
+  __asm__ ("sub%.l %5,%1 \n\
 	subx%.l %3,%0"							\
 	   : "=d" ((USItype)(sh)),					\
 	     "=&d" ((USItype)(sl))					\
@@ -568,27 +568,27 @@
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
+	__asm__ ("| Inlined umul_ppmm\n\
+	move%.l	%5,%3\n\
+	move%.l	%2,%0\n\
+	move%.w	%3,%1\n\
+	swap	%3\n\
+	swap	%0\n\
+	mulu	%2,%1\n\
+	mulu	%3,%0\n\
+	mulu	%2,%3\n\
+	swap	%2\n\
+	mulu	%5,%2\n\
+	add%.l	%3,%2\n\
+	jcc	1f\n\
+	add%.l	%#0x10000,%0\n\
+1:	move%.l	%2,%3\n\
+	clr%.w	%2\n\
+	swap	%2\n\
+	swap	%3\n\
+	clr%.w	%3\n\
+	add%.l	%3,%1\n\
+	addx%.l	%2,%0\n\
 	| End inlined umul_ppmm"					\
 	      : "=&d" ((USItype)(xh)), "=&d" ((USItype)(xl)),		\
 	        "=d" (__umul_tmp1), "=&d" (__umul_tmp2)			\
@@ -601,7 +601,7 @@
 
 #if defined (__m88000__) && W_TYPE_SIZE == 32
 #define add_ssaaaa(sh, sl, ah, al, bh, bl) \
-  __asm__ ("addu.co %1,%r4,%r5
+  __asm__ ("addu.co %1,%r4,%r5 \n\
 	addu.ci %0,%r2,%r3"						\
 	   : "=r" ((USItype)(sh)),					\
 	     "=&r" ((USItype)(sl))					\
@@ -610,7 +610,7 @@
 	     "%rJ" ((USItype)(al)),					\
 	     "rJ" ((USItype)(bl)))
 #define sub_ddmmss(sh, sl, ah, al, bh, bl) \
-  __asm__ ("subu.co %1,%r4,%r5
+  __asm__ ("subu.co %1,%r4,%r5 \n\
 	subu.ci %0,%r2,%r3"						\
 	   : "=r" ((USItype)(sh)),					\
 	     "=&r" ((USItype)(sl))					\
@@ -669,8 +669,8 @@
 	     "d" ((USItype)(v)))
 #else
 #define umul_ppmm(w1, w0, u, v) \
-  __asm__ ("multu %2,%3
-	mflo %0
+  __asm__ ("multu %2,%3 \n\
+	mflo %0 \n\
 	mfhi %1"							\
 	   : "=d" ((USItype)(w0)),					\
 	     "=d" ((USItype)(w1))					\
@@ -691,8 +691,8 @@
 	     "d" ((UDItype)(v)))
 #else
 #define umul_ppmm(w1, w0, u, v) \
-  __asm__ ("dmultu %2,%3
-	mflo %0
+  __asm__ ("dmultu %2,%3 \n\
+	mflo %0 \n\
 	mfhi %1"							\
 	   : "=d" ((UDItype)(w0)),					\
 	     "=d" ((UDItype)(w1))					\
@@ -861,7 +861,7 @@
 
 #if defined (__pyr__) && W_TYPE_SIZE == 32
 #define add_ssaaaa(sh, sl, ah, al, bh, bl) \
-  __asm__ ("addw	%5,%1
+  __asm__ ("addw	%5,%1 \n\
 	addwc	%3,%0"							\
 	   : "=r" ((USItype)(sh)),					\
 	     "=&r" ((USItype)(sl))					\
@@ -870,7 +870,7 @@
 	     "%1" ((USItype)(al)),					\
 	     "g" ((USItype)(bl)))
 #define sub_ddmmss(sh, sl, ah, al, bh, bl) \
-  __asm__ ("subw	%5,%1
+  __asm__ ("subw	%5,%1 \n\
 	subwb	%3,%0"							\
 	   : "=r" ((USItype)(sh)),					\
 	     "=&r" ((USItype)(sl))					\
@@ -883,7 +883,7 @@
   ({union {UDItype __ll;						\
 	   struct {USItype __h, __l;} __i;				\
 	  } __xx;							\
-  __asm__ ("movw %1,%R0
+  __asm__ ("movw %1,%R0 \n\
 	uemul %2,%0"							\
 	   : "=&r" (__xx.__ll)						\
 	   : "g" ((USItype) (u)),					\
@@ -893,7 +893,7 @@
 
 #if defined (__ibm032__) /* RT/ROMP */  && W_TYPE_SIZE == 32
 #define add_ssaaaa(sh, sl, ah, al, bh, bl) \
-  __asm__ ("a %1,%5
+  __asm__ ("a %1,%5 \n\
 	ae %0,%3"							\
 	   : "=r" ((USItype)(sh)),					\
 	     "=&r" ((USItype)(sl))					\
@@ -902,7 +902,7 @@
 	     "%1" ((USItype)(al)),					\
 	     "r" ((USItype)(bl)))
 #define sub_ddmmss(sh, sl, ah, al, bh, bl) \
-  __asm__ ("s %1,%5
+  __asm__ ("s %1,%5 \n\
 	se %0,%3"							\
 	   : "=r" ((USItype)(sh)),					\
 	     "=&r" ((USItype)(sl))					\
@@ -914,25 +914,25 @@
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
+       "s	r2,r2 \n\
+	mts	r10,%2 \n\
+	m	r2,%3 \n\
+	m	r2,%3 \n\
+	m	r2,%3 \n\
+	m	r2,%3 \n\
+	m	r2,%3 \n\
+	m	r2,%3 \n\
+	m	r2,%3 \n\
+	m	r2,%3 \n\
+	m	r2,%3 \n\
+	m	r2,%3 \n\
+	m	r2,%3 \n\
+	m	r2,%3 \n\
+	m	r2,%3 \n\
+	m	r2,%3 \n\
+	m	r2,%3 \n\
+	m	r2,%3 \n\
+	cas	%0,r2,r0 \n\
 	mfs	r10,%1"							\
 	     : "=r" ((USItype)(ph)),					\
 	       "=r" ((USItype)(pl))					\
@@ -963,8 +963,8 @@
 #if defined (__sh2__) && W_TYPE_SIZE == 32
 #define umul_ppmm(w1, w0, u, v) \
   __asm__ (								\
-       "dmulu.l	%2,%3
-	sts	macl,%1
+       "dmulu.l	%2,%3 \n\
+	sts	macl,%1 \n\
 	sts	mach,%0"						\
 	   : "=r" ((USItype)(w1)),					\
 	     "=r" ((USItype)(w0))					\
@@ -976,7 +976,7 @@
 
 #if defined (__sparc__) && W_TYPE_SIZE == 32
 #define add_ssaaaa(sh, sl, ah, al, bh, bl) \
-  __asm__ ("addcc %r4,%5,%1
+  __asm__ ("addcc %r4,%5,%1 \n\
 	addx %r2,%3,%0"							\
 	   : "=r" ((USItype)(sh)),					\
 	     "=&r" ((USItype)(sl))					\
@@ -986,7 +986,7 @@
 	     "rI" ((USItype)(bl))					\
 	   __CLOBBER_CC)
 #define sub_ddmmss(sh, sl, ah, al, bh, bl) \
-  __asm__ ("subcc %r4,%5,%1
+  __asm__ ("subcc %r4,%5,%1 \n\
 	subx %r2,%3,%0"							\
 	   : "=r" ((USItype)(sh)),					\
 	     "=&r" ((USItype)(sl))					\
@@ -1033,44 +1033,44 @@
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
+  __asm__ ("! Inlined udiv_qrnnd \n\
+	wr	%%g0,%2,%%y	! Not a delayed write for sparclite \n\
+	tst	%%g0 \n\
+	divscc	%3,%4,%%g1 \n\
+	divscc	%%g1,%4,%%g1 \n\
+	divscc	%%g1,%4,%%g1 \n\
+	divscc	%%g1,%4,%%g1 \n\
+	divscc	%%g1,%4,%%g1 \n\
+	divscc	%%g1,%4,%%g1 \n\
+	divscc	%%g1,%4,%%g1 \n\
+	divscc	%%g1,%4,%%g1 \n\
+	divscc	%%g1,%4,%%g1 \n\
+	divscc	%%g1,%4,%%g1 \n\
+	divscc	%%g1,%4,%%g1 \n\
+	divscc	%%g1,%4,%%g1 \n\
+	divscc	%%g1,%4,%%g1 \n\
+	divscc	%%g1,%4,%%g1 \n\
+	divscc	%%g1,%4,%%g1 \n\
+	divscc	%%g1,%4,%%g1 \n\
+	divscc	%%g1,%4,%%g1 \n\
+	divscc	%%g1,%4,%%g1 \n\
+	divscc	%%g1,%4,%%g1 \n\
+	divscc	%%g1,%4,%%g1 \n\
+	divscc	%%g1,%4,%%g1 \n\
+	divscc	%%g1,%4,%%g1 \n\
+	divscc	%%g1,%4,%%g1 \n\
+	divscc	%%g1,%4,%%g1 \n\
+	divscc	%%g1,%4,%%g1 \n\
+	divscc	%%g1,%4,%%g1 \n\
+	divscc	%%g1,%4,%%g1 \n\
+	divscc	%%g1,%4,%%g1 \n\
+	divscc	%%g1,%4,%%g1 \n\
+	divscc	%%g1,%4,%%g1 \n\
+	divscc	%%g1,%4,%%g1 \n\
+	divscc	%%g1,%4,%0 \n\
+	rd	%%y,%1 \n\
+	bl,a 1f \n\
+	add	%1,%4,%1 \n\
 1:	! End of inline udiv_qrnnd"					\
 	   : "=r" ((USItype)(q)),					\
 	     "=r" ((USItype)(r))					\
@@ -1091,45 +1091,45 @@
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
+  __asm__ ("! Inlined umul_ppmm\n\
+	wr	%%g0,%2,%%y	! SPARC has 0-3 delay insn after a wr\n\
+	sra	%3,31,%%g2	! Don't move this insn\n\
+	and	%2,%%g2,%%g2	! Don't move this insn\n\
+	andcc	%%g0,0,%%g1	! Don't move this insn\n\
+	mulscc	%%g1,%3,%%g1\n\
+	mulscc	%%g1,%3,%%g1\n\
+	mulscc	%%g1,%3,%%g1\n\
+	mulscc	%%g1,%3,%%g1\n\
+	mulscc	%%g1,%3,%%g1\n\
+	mulscc	%%g1,%3,%%g1\n\
+	mulscc	%%g1,%3,%%g1\n\
+	mulscc	%%g1,%3,%%g1\n\
+	mulscc	%%g1,%3,%%g1\n\
+	mulscc	%%g1,%3,%%g1\n\
+	mulscc	%%g1,%3,%%g1\n\
+	mulscc	%%g1,%3,%%g1\n\
+	mulscc	%%g1,%3,%%g1\n\
+	mulscc	%%g1,%3,%%g1\n\
+	mulscc	%%g1,%3,%%g1\n\
+	mulscc	%%g1,%3,%%g1\n\
+	mulscc	%%g1,%3,%%g1\n\
+	mulscc	%%g1,%3,%%g1\n\
+	mulscc	%%g1,%3,%%g1\n\
+	mulscc	%%g1,%3,%%g1\n\
+	mulscc	%%g1,%3,%%g1\n\
+	mulscc	%%g1,%3,%%g1\n\
+	mulscc	%%g1,%3,%%g1\n\
+	mulscc	%%g1,%3,%%g1\n\
+	mulscc	%%g1,%3,%%g1\n\
+	mulscc	%%g1,%3,%%g1\n\
+	mulscc	%%g1,%3,%%g1\n\
+	mulscc	%%g1,%3,%%g1\n\
+	mulscc	%%g1,%3,%%g1\n\
+	mulscc	%%g1,%3,%%g1\n\
+	mulscc	%%g1,%3,%%g1\n\
+	mulscc	%%g1,%3,%%g1\n\
+	mulscc	%%g1,0,%%g1\n\
+	add	%%g1,%%g2,%0\n\
 	rd	%%y,%1"							\
 	   : "=r" ((USItype)(w1)),					\
 	     "=r" ((USItype)(w0))					\
@@ -1153,7 +1153,7 @@
 
 #if defined (__vax__) && W_TYPE_SIZE == 32
 #define add_ssaaaa(sh, sl, ah, al, bh, bl) \
-  __asm__ ("addl2 %5,%1
+  __asm__ ("addl2 %5,%1 \n\
 	adwc %3,%0"							\
 	   : "=g" ((USItype)(sh)),					\
 	     "=&g" ((USItype)(sl))					\
@@ -1162,7 +1162,7 @@
 	     "%1" ((USItype)(al)),					\
 	     "g" ((USItype)(bl)))
 #define sub_ddmmss(sh, sl, ah, al, bh, bl) \
-  __asm__ ("subl2 %5,%1
+  __asm__ ("subl2 %5,%1 \n\
 	sbwc %3,%0"							\
 	   : "=g" ((USItype)(sh)),					\
 	     "=&g" ((USItype)(sl))					\
