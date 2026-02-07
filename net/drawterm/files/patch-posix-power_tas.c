--- posix-power/tas.c.orig	2024-01-26 17:52:14 UTC
+++ posix-power/tas.c
@@ -15,16 +15,16 @@ tas(int *x)
 	 * r4 (x) and r5 (temp).
 	 */
 	__asm__("\n	sync\n"
-	"	li	r0,0\n"
-	"	mr	r4,%1		/* &l->val */\n"
-	"	lis	r5,0xdead	/* assemble constant 0xdeaddead */\n"
-	"	ori	r5,r5,0xdead	/* \" */\n"
+	"	li	0,0\n"
+	"	mr	4,%1		/* &l->val */\n"
+	"	lis	5,0xdead	/* assemble constant 0xdeaddead */\n"
+	"	ori	5,5,0xdead	/* \" */\n"
 	"tas1:\n"
-	"	dcbf	r4,r0	/* cache flush; \"fix for 603x bug\" */\n"
-	"	lwarx	%0,r4,r0	/* v = l->val with reservation */\n"
-	"	cmp	cr0,0,%0,r0	/* v == 0 */\n"
+	"	dcbf	4,0	/* cache flush; \"fix for 603x bug\" */\n"
+	"	lwarx	%0,4,0	/* v = l->val with reservation */\n"
+	"	cmp	cr0,0,%0,0	/* v == 0 */\n"
 	"	bne	tas0\n"
-	"	stwcx.	r5,r4,r0   /* if (l->val same) l->val = 0xdeaddead */\n"
+	"	stwcx.	5,4,0   /* if (l->val same) l->val = 0xdeaddead */\n"
 	"	bne	tas1\n"
 	"tas0:\n"
 	"	sync\n"
