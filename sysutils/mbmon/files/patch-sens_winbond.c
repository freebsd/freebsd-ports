--- sens_winbond.c	Fri Jul  9 07:34:41 2004
+++ sens_winbond.c	Wed May  3 16:43:40 2006
@@ -245,6 +244,7 @@
 		case 0x20:	/* 0x20 (or 0x21) 627HF */
 		case 0x90:	/* 0x90 (or 0x91?) 627THF */
 		case 0x1A:	/* 0x1A (??)  627THF-A */
+		case 0xA0:	/* 0xA0 (or 0xA1) */
 			wbdchipid = W83627HF;
 			break;
 		case 0x30:	/* 0x30 (or 0x31) */
