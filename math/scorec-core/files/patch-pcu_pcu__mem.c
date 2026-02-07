- use of linux-specific function mallinfo(): https://github.com/SCOREC/core/issues/409

--- pcu/pcu_mem.c.orig	2023-12-24 18:38:48 UTC
+++ pcu/pcu_mem.c
@@ -44,6 +44,8 @@ double PCU_GetMem() {
   task_info(current_task(), TASK_BASIC_INFO, (task_info_t)&t_info, &t_info_count);
   size_t size = (resident ? t_info.resident_size : t_info.virtual_size);
   return (double)size/M;
+#elif defined(__FreeBSD__)
+  return (double)20000.; // TODO default to 20GB for now
 #elif defined(__bgq__)
   size_t heap;
   Kernel_GetMemorySize(KERNEL_MEMSIZE_HEAP, &heap);
