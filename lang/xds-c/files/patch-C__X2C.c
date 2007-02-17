--- C/X2C.c.orig	2001-09-25 07:56:48.000000000 +0000
+++ C/X2C.c	2007-01-24 15:29:52.000000000 +0000
@@ -700,7 +700,7 @@
 	iprocs[3]=iproc3;
 	iprocs_cnt=4;
 
-#if defined(__linux__) && defined(__i386__) && defined(X2C_native_library)
+#if (defined(__linux__) || defined(__FreeBSD__) || defined(__DragonFly__)) && defined(__i386__) && defined(X2C_native_library)
         stk_up  = 0;
         ss_offs = -1;
         sp_offs = (int) &((*(X2C_jmp_buf*)(0))[0].esp) / 4;
