--- test/gtest/ucm/malloc_hook.cc.orig	2026-02-04 09:52:46 UTC
+++ test/gtest/ucm/malloc_hook.cc
@@ -14,6 +14,7 @@
 #include <common/test_helpers.h>
 #include <pthread.h>
 #include <sstream>
+#include <sys/wait.h>
 #include <stdint.h>
 #include <dlfcn.h>
 #include <libgen.h>
@@ -244,7 +245,9 @@ class malloc_hook : public ucs::test { (protected)
 
         m_got_event = 0;
         ucm_malloc_state_reset(128 * 1024, 128 * 1024);
-        malloc_trim(0);
+#ifdef __linux__
+	malloc_trim(0);
+#endif
         status = event.set(UCM_EVENT_VM_MAPPED);
         ASSERT_UCS_OK(status);
 
@@ -483,7 +486,9 @@ void test_thread::test() {
     new_ptrs.clear();
 
     /* Call several malloc routines */
+#ifdef __linux__
     malloc_trim(0);
+#endif
 
     ptr = malloc(large_alloc_size);
 
@@ -514,6 +519,7 @@ void test_thread::test() {
     }
 
     /* mremap(FIXED) */
+#ifdef __linux__
     {
         ptr = mmap(NULL, shm_seg_size, PROT_READ | PROT_WRITE,
                    MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
@@ -538,6 +544,7 @@ void test_thread::test() {
         /* coverity[pass_freed_arg] */
         EXPECT_TRUE(is_ptr_in_range(ptr2, shm_seg_size, m_unmap_ranges));
     }
+#endif
 
     /* Print results */
     pthread_mutex_lock(&lock);
@@ -569,7 +576,9 @@ UCS_TEST_SKIP_COND_F(malloc_hook, multi_threads,
     ucs::ptr_vector<thread_t> threads;
     pthread_barrier_t barrier;
 
+#ifdef __linux__
     malloc_trim(0);
+#endif
 
     pthread_barrier_init(&barrier, NULL, num_threads);
     for (int i = 0; i < num_threads; ++i) {
@@ -849,8 +858,10 @@ class mmap_hooks { (public)
                 /* sbrk call is used to extend/cut memory heap,
                  * don't add any evaluations between calls sbrk+/sbrk- - it
                  * may break heap */
+#ifdef HAVE_SBRK
                 sbrk(size);
                 sbrk(-size);
+#endif
 
                 EXPECT_INCREASED(m_mapped_size, mapped_size, size, m_name);
                 EXPECT_INCREASED(m_unmapped_size, unmapped_size, size, m_name);
@@ -895,13 +906,16 @@ UCS_TEST_F(malloc_hook_cplusplus, new_delete) {
         std::vector<char> vec3(size, 0);
     }
 
+#ifdef __linux__
     malloc_trim(0);
+#endif
 
     EXPECT_GE(m_unmapped_size, size);
 
     unset();
 }
 
+#ifdef __linux__
 UCS_TEST_SKIP_COND_F(malloc_hook_cplusplus, dynamic_mmap_enable,
                      RUNNING_ON_VALGRIND || skip_on_bistro()) {
     EXPECT_TRUE(ucm_global_opts.enable_dynamic_mmap_thresh);
@@ -1044,6 +1058,7 @@ UCS_TEST_SKIP_COND_F(malloc_hook_cplusplus, mmap_ptrs,
     unset();
 
 }
+#endif
 
 UCS_TEST_F(malloc_hook_cplusplus, remap_override_single_thread) {
     pthread_barrier_t barrier;
