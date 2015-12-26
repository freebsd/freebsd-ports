--- Xvnc/programs/Xserver/hw/xfree86/common/compiler.h.orig	2015-12-23 13:48:48.097424000 +0800
+++ Xvnc/programs/Xserver/hw/xfree86/common/compiler.h	2015-12-23 13:49:19.871472000 +0800
@@ -371,7 +371,7 @@
 #define mem_barrier()   /* NOP */
 #define write_mem_barrier()   /* NOP */
 
-#if !defined(FAKEIT) && !defined(__mc68000__)
+#if !defined(FAKEIT) && !defined(__mc68000__) && !defined(__arm__)
 #ifdef GCCUSESGAS
 
 /*
