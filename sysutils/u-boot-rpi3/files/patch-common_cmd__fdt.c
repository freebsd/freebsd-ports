--- common/cmd_fdt.c.orig	2015-04-13 14:53:03 UTC
+++ common/cmd_fdt.c
@@ -44,7 +44,7 @@ void set_working_fdt_addr(ulong addr)
 
 	buf = map_sysmem(addr, 0);
 	working_fdt = buf;
-	setenv_ulong("fdtaddr", addr);
+	setenv_hex("fdtaddr", addr);
 }
 
 /*
