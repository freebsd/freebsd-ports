--- sens_winbond.c.orig	2004-07-09 05:34:41 UTC
+++ sens_winbond.c
@@ -245,6 +245,8 @@ printf("DEBUG 49:0x%02X 58:0x%02X 4Fl:0x
 		case 0x20:	/* 0x20 (or 0x21) 627HF */
 		case 0x90:	/* 0x90 (or 0x91?) 627THF */
 		case 0x1A:	/* 0x1A (??)  627THF-A */
+		case 0xA0:	/* 0xA0 (or 0xA1) */
+		case 0xC0:	/* 0xC0 (or 0xC1) 627DHG */
 			wbdchipid = W83627HF;
 			break;
 		case 0x30:	/* 0x30 (or 0x31) */
