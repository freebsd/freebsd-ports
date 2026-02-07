--- src/fmm.c.orig	2018-11-19 01:35:23 UTC
+++ src/fmm.c
@@ -37,7 +37,9 @@
 #include <sys/time.h>
 #include <errno.h>
 #include <pci/pci.h>
+#ifdef __linux__
 #include <numaif.h>
+#endif
 #ifndef MPOL_F_STATIC_NODES
 /* Bug in numaif.h, this should be defined in there. Definition copied
  * from linux/mempolicy.h.
@@ -1207,7 +1209,9 @@ static void *fmm_allocate_host_gpu(uint32_t node_id, u
 	if (!flags.ui32.NonPaged && svm.userptr_for_paged_mem) {
 		const unsigned int bits_per_long = sizeof(unsigned long) * 8;
 		unsigned long node_mask[node_id / bits_per_long + 1];
+#ifdef __linux__
 		int mode = MPOL_F_STATIC_NODES;
+#endif
 
 		/* Allocate address space */
 		pthread_mutex_lock(&aperture->fmm_mutex);
@@ -1219,10 +1223,12 @@ static void *fmm_allocate_host_gpu(uint32_t node_id, u
 		/* Bind to NUMA node */
 		memset(node_mask, 0, sizeof(node_mask));
 		node_mask[node_id / bits_per_long] = 1UL << (node_id % bits_per_long);
+#ifdef __linux__
 		mode |= flags.ui32.NoSubstitute ? MPOL_BIND : MPOL_PREFERRED;
 		if (mbind(mem, MemorySizeInBytes, mode, node_mask, node_id+1, 0))
 			pr_warn("Failed to set NUMA policy for %lu pages at %p\n",
 				MemorySizeInBytes >> 12, mem);
+#endif
 
 		/* Map anonymous pages */
 		if (mmap(mem, MemorySizeInBytes, PROT_READ | PROT_WRITE,
@@ -1334,7 +1340,9 @@ static void __fmm_release(void *address, manageable_ap
 	if (address >= dgpu_shared_aperture_base &&
 	    address <= dgpu_shared_aperture_limit) {
 		/* Reset NUMA policy */
+#ifdef __linux__
 		mbind(address, object->size, MPOL_DEFAULT, NULL, 0, 0);
+#endif
 		munmap_and_reserve_address(address, object->size);
 	}
 
