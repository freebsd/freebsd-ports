--- linux_dvbwrapper.c.orig	2024-01-02 18:20:10 UTC
+++ linux_dvbwrapper.c
@@ -37,11 +37,8 @@
 #include <sys/sysproto.h>
 #include <sys/mman.h>
 #include <sys/resourcevar.h>
+#include <sys/capsicum.h>
 
-#if __FreeBSD_version > 900040
-#include <sys/capability.h>
-#endif
-
 #include <vm/vm.h>
 #include <vm/pmap.h>
 #include <vm/vm_extern.h>
@@ -299,7 +296,9 @@ linux_ioctl_dvb(struct thread *td, struct linux_ioctl_
 		error = copyout_map(td, &uvp, propsiz);
 		if (error)
 			goto out2;
-		copyout(vp, (void *)uvp, propsiz);
+		error = copyout(vp, (void *)uvp, propsiz);
+		if (error)
+			goto out2;
 
 #if __FreeBSD_version > 1000051
 		error = fget(td, args->fd,
@@ -330,7 +329,7 @@ linux_ioctl_dvb(struct thread *td, struct linux_ioctl_
 		for (i = vps.num, l_p = l_vp, p = vp; i--; ++l_p, ++p)
 			bsd_to_linux_dtv_property(p, l_p);
 		linux_to_bsd_dtv_properties(&l_vps, &vps);
-		copyout(l_vp, (void *)vps.props, l_propsiz);
+		error = copyout(l_vp, (void *)vps.props, l_propsiz);
 
 	out:
 		fdrop(fp, td);
