--- asmon/asmon.c.orig	2000-07-20 11:08:47 UTC
+++ asmon/asmon.c
@@ -990,7 +990,7 @@ void DrawXmem(int Xpid, float total) 
 
 	kproc = kvm_getprocs(kd, KERN_PROC_PID, Xpid, &kcnt);
 
-	Xsize = kproc->kp_eproc.e_vm.vm_map.size / 1024;
+	Xsize = kproc->ki_size / 1024;
 #endif
         if(old_Xsize!=Xsize)
 	{
