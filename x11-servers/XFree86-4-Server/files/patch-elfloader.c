--- programs/Xserver/hw/xfree86/loader/elfloader.c.orig	Fri Jan 24 12:26:35 2003
+++ programs/Xserver/hw/xfree86/loader/elfloader.c	Tue May 20 15:18:44 2003
@@ -1150,6 +1150,7 @@
 #endif
 #if defined(__sparc__)
     unsigned char *dest8;	/* address of the 8 bit place being modified */
+    unsigned long *dest64;
 #endif
 #if defined(__alpha__) 
     unsigned int *dest32h;	/* address of the high 32 bit place being modified */
@@ -1960,7 +1961,6 @@
 		break;
 
 	case R_SPARC_32:	/*  3 */
-	case R_SPARC_GLOB_DAT:	/* 20 */
 	case R_SPARC_UA32:	/* 23 */
 		dest32 = (unsigned int *)(secp + rel->r_offset);
 		symval += rel->r_addend;
@@ -1970,29 +1970,36 @@
 		((unsigned char *)dest32)[3] = (unsigned char)(symval      );
 		break;
 
+	case R_SPARC_GLOB_DAT:	/* 20 */
+	case R_SPARC_64:	/* 32 */
+		dest64 = (unsigned long *)(secp + rel->r_offset);
+		symval += rel->r_addend;
+		*dest64 = symval;
+		break;
+
 	case R_SPARC_DISP8:	/*  4 */
 		dest8 = (unsigned char *)(secp + rel->r_offset);
 		symval += rel->r_addend;
-		*dest8 = (symval - (Elf32_Addr) dest8);
+		*dest8 = (symval - (Elf_Addr) dest8);
 		break;
 
 	case R_SPARC_DISP16:	/*  5 */
 		dest16 = (unsigned short *)(secp + rel->r_offset);
 		symval += rel->r_addend;
-		*dest16 = (symval - (Elf32_Addr) dest16);
+		*dest16 = (symval - (Elf_Addr) dest16);
 		break;
 
 	case R_SPARC_DISP32:	/*  6 */
 		dest32 = (unsigned int *)(secp + rel->r_offset);
 		symval += rel->r_addend;
-		*dest32 = (symval - (Elf32_Addr) dest32);
+		*dest32 = (symval - (Elf_Addr) dest32);
 		break;
 
 	case R_SPARC_WDISP30:	/*  7 */
 		dest32 = (unsigned int *)(secp + rel->r_offset);
 		symval += rel->r_addend;
 		*dest32 = ((*dest32 & 0xc0000000) |
-			   ((symval - (Elf32_Addr) dest32) >> 2));
+			   (((symval - (Elf_Addr) dest32) >> 2) & 0x3fffffff));
 		break;
 
 	case R_SPARC_HI22:	/*  9 */
@@ -2038,8 +2045,8 @@
 		break;
 
 	case R_SPARC_RELATIVE:	/* 22 */
-		dest32 = (unsigned int *)(secp + rel->r_offset);
-		*dest32 += (unsigned int)secp + rel->r_addend;
+		dest64 = (unsigned long *)(secp + rel->r_offset);
+		*dest64 = (unsigned long)secp + rel->r_addend;
 		break;
 #endif /*__sparc__*/
 #ifdef __ia64__
