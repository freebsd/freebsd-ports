Index: programs/Xserver/hw/xfree86/loader/elfloader.c
===================================================================
RCS file: /cvs/xorg/xc/programs/Xserver/hw/xfree86/loader/elfloader.c,v
retrieving revision 1.3
retrieving revision 1.4
diff -u -u -r1.3 -r1.4
--- programs/Xserver/hw/xfree86/loader/elfloader.c	30 Oct 2004 20:33:43 -0000	1.3
+++ programs/Xserver/hw/xfree86/loader/elfloader.c	9 Nov 2004 15:58:41 -0000	1.4
@@ -1,4 +1,4 @@
-/* $XdotOrg: xc/programs/Xserver/hw/xfree86/loader/elfloader.c,v 1.3 2004/10/30 20:33:43 alanc Exp $ */
+/* $XdotOrg: xc/programs/Xserver/hw/xfree86/loader/elfloader.c,v 1.4 2004/11/09 15:58:41 ajax Exp $ */
 /* $XFree86: xc/programs/Xserver/hw/xfree86/loader/elfloader.c,v 1.61tsi Exp $ */
 
 /*
@@ -1609,6 +1609,20 @@
 	    break;
 	}
 
+ 	case R_ALPHA_SREL32:
+ 	    {
+ 		dest32 = (unsigned int *)(secp + rel->r_offset);
+ 		symval += rel->r_addend;
+ 		symval -= (unsigned long) dest32;
+ 		if ((long)symval >= 0x80000000
+ 		    || (long)symval < -(long)0x80000000)
+ 		    FatalError("R_ALPHA_SREL32 overflow for %s: %lx\n",
+ 			       ElfGetSymbolName(elffile, ELF_R_SYM(rel->r_info)),
+ 			       symval);
+ 		*dest32 = symval;
+ 		break;
+ 	    }
+ 
 #endif /* alpha */
 #if defined(__mc68000__)
     case R_68K_32:
