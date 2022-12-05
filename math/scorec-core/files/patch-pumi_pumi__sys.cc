--- pumi/pumi_sys.cc.orig	2022-12-05 09:50:18 UTC
+++ pumi/pumi_sys.cc
@@ -98,6 +98,8 @@ double pumi_getMem()
   task_info(current_task(), TASK_BASIC_INFO, (task_info_t)&t_info, &t_info_count);
   size_t size = (resident ? t_info.resident_size : t_info.virtual_size);
   return (double)size/M;
+#elif defined(__FreeBSD__)
+  return (double)20000.; // TODO default to 20GB for now
 #elif defined(__bgq__)
   size_t heap;
   Kernel_GetMemorySize(KERNEL_MEMSIZE_HEAP, &heap);
