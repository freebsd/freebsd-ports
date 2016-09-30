--- setup.S.orig	2013-08-10 02:01:58 UTC
+++ setup.S
@@ -50,7 +50,7 @@ reload:
      	jz	alt_a20_done
      	
      	/* set or clear bit1, the ALT_A20_GATE bit */
-     	movb	4(%esp), %ah
+     	addr32 movb	4(%esp), %ah
      	testb	%ah, %ah
      	jz	alt_a20_cont1
      	orb	$2, %al
