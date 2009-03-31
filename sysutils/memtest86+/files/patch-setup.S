--- setup.S	2008-11-16 02:18:14.000000000 +0200
+++ setup.S	2009-02-18 00:28:02.000000000 +0200
@@ -42,7 +42,7 @@ start:
 	jz	alt_a20_done
 	
 	/* set or clear bit1, the ALT_A20_GATE bit */
-	movb	4(%esp), %ah
+	addr32 movb	4(%esp), %ah
 	testb	%ah, %ah
 	jz	alt_a20_cont1
 	orb	$2, %al
