--- Xvnc/programs/Xserver/hw/xfree86/common/compiler.h.orig	2000-06-11 12:00:51 UTC
+++ Xvnc/programs/Xserver/hw/xfree86/common/compiler.h
@@ -371,7 +371,7 @@ static __inline__ unsigned long ldw_u(unsigned short *
 #define mem_barrier()   /* NOP */
 #define write_mem_barrier()   /* NOP */
 
-#if !defined(FAKEIT) && !defined(__mc68000__)
+#if !defined(FAKEIT) && !defined(__mc68000__) && !defined(__arm__)
 #ifdef GCCUSESGAS
 
 /*
