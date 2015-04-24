--- common/cmd_fdt.c.orig	2015-04-23 20:55:46.193272000 -0300
+++ common/cmd_fdt.c
@@ -44,7 +44,7 @@
 
 	buf = map_sysmem(addr, 0);
 	working_fdt = buf;
-	setenv_ulong("fdtaddr", addr);
+	setenv_hex("fdtaddr", addr);
 }
 
 /*
