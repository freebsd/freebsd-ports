Index: programs/Xserver/hw/xfree86/int10/generic.c
===================================================================
RCS file: /home/ncvs/xfree/xc/programs/Xserver/hw/xfree86/int10/generic.c,v
retrieving revision 1.25
retrieving revision 1.26
diff -u -u -r1.25 -r1.26
--- programs/Xserver/hw/xfree86/int10/generic.c	4 Apr 2002 14:05:51 -0000	1.25
+++ programs/Xserver/hw/xfree86/int10/generic.c	20 Mar 2003 15:11:26 -0000	1.26
@@ -1,4 +1,4 @@
-/* $XFree86: xc/programs/Xserver/hw/xfree86/int10/generic.c,v 1.23 2001/05/28 14:21:56 eich Exp $ */
+/* $XFree86: xc/programs/Xserver/hw/xfree86/int10/generic.c,v 1.25tsi Exp $ */
 /*
  *                   XFree86 int10 module
  *   execute BIOS int 10h calls in x86 real mode environment
@@ -108,7 +108,7 @@
     MapVRam(pInt);
 #ifdef _PC
     if (!sysMem)
-	sysMem = xf86MapVidMem(screen, VIDMEM_FRAMEBUFFER, V_BIOS,
+	sysMem = xf86MapVidMem(screen, VIDMEM_MMIO, V_BIOS,
 			       BIOS_SIZE + SYS_BIOS - V_BIOS);
     INTPriv(pInt)->sysMem = sysMem;
 
@@ -446,12 +446,14 @@
 #define OFF(addr) ((addr) & 0xffff)
 #if defined _PC
 # define HIGH_OFFSET (INTPriv(pInt)->highMemory)
+# define HIGH_BASE   V_BIOS
 #else
 # define HIGH_OFFSET SYS_BIOS
+# define HIGH_BASE   SYS_BIOS
 #endif
 # define SYS(addr) ((addr) >= HIGH_OFFSET)
 #define V_ADDR(addr) \
-	  (SYS(addr) ? ((char*)INTPriv(pInt)->sysMem) + (addr - HIGH_OFFSET) \
+	  (SYS(addr) ? ((char*)INTPriv(pInt)->sysMem) + (addr - HIGH_BASE) \
 	   : (((char*)(INTPriv(pInt)->base) + addr)))
 #define VRAM_ADDR(addr) (addr - V_RAM)
 #define VRAM_BASE (INTPriv(pInt)->vRam)
