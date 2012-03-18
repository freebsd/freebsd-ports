--- asmon/asmon.c.bak	2012-03-13 19:03:06.795252708 +0600
+++ asmon/asmon.c	2012-03-13 19:04:16.395242371 +0600
@@ -990,7 +990,11 @@
 
 	kproc = kvm_getprocs(kd, KERN_PROC_PID, Xpid, &kcnt);
 
-	Xsize = kproc->kp_eproc.e_vm.vm_map.size / 1024;
+	#if __FreeBSD_version < 500000
+		Xsize = kproc->kp_eproc.e_vm.vm_map.size / 1024;
+	#else
+		Xsize = kproc->ki_size / 1024;
+	#endif
 #endif
         if(old_Xsize!=Xsize)
 	{
