--- client/freebsd-meminfo.c.orig	2006-08-09 22:09:58.000000000 +0200
+++ client/freebsd-meminfo.c	2008-03-01 04:31:43.000000000 +0100
@@ -23,7 +23,7 @@
 	unsigned long physmem;
 
 	int hw_pagesize[] = { CTL_HW, HW_PAGESIZE };
-	unsigned long pagesize;
+	int pagesize;
 
 	int vm_vmtotal[] = { CTL_VM, VM_METER };
 	struct vmtotal vmdata;
