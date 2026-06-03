--- src/ucm/util/replace.c.orig	2026-02-04 09:52:46 UTC
+++ src/ucm/util/replace.c
@@ -55,8 +55,10 @@ UCM_DEFINE_REPLACE_FUNC(shmdt,   int,   -1,         co
 #endif
 UCM_DEFINE_REPLACE_FUNC(shmat,   void*, MAP_FAILED, int, const void*, int)
 UCM_DEFINE_REPLACE_FUNC(shmdt,   int,   -1,         const void*)
+#ifdef HAVE_BRK_SBRK
 UCM_DEFINE_REPLACE_FUNC(sbrk,    void*, MAP_FAILED, intptr_t)
 UCM_DEFINE_REPLACE_FUNC(brk,     int,   -1,         void*)
+#endif
 UCM_DEFINE_REPLACE_FUNC(madvise, int,   -1,         void*, size_t, int)
 
 UCM_DEFINE_SELECT_FUNC(mmap, void*, SYS_mmap, void*, size_t, int, int, int,
@@ -122,6 +124,7 @@ int ucm_orig_shmdt(const void *shmaddr)
 
 #endif
 
+#ifdef HAVE_BRK_SBRK
 _UCM_DEFINE_DLSYM_FUNC(brk, ucm_orig_dlsym_brk, ucm_override_brk, int, void*)
 
 int ucm_orig_brk(void *addr)
@@ -156,7 +159,32 @@ void *ucm_orig_sbrk(intptr_t increment)
                (void*)-1 : prev;
     }
 }
+#else
+int ucm_orig_brk(void *addr)
+{
+    (void)addr;
+    errno = ENOSYS;
+    return -1;
+}
 
+void *ucm_orig_sbrk(intptr_t increment)
+{
+    (void)increment;
+    errno = ENOSYS;
+    return MAP_FAILED;
+}
+
+int ucm_override_brk(void *addr)
+{
+    return ucm_orig_brk(addr);
+}
+
+void *ucm_override_sbrk(intptr_t increment)
+{
+    return ucm_orig_sbrk(increment);
+}
+#endif
+
 #else /* UCM_BISTRO_HOOKS */
 
 UCM_DEFINE_DLSYM_FUNC(brk, int, void*)
@@ -168,9 +196,13 @@ void *ucm_get_current_brk()
 
 void *ucm_get_current_brk()
 {
+#ifdef HAVE_BRK_SBRK
 #if HAVE___CURBRK
     return __curbrk;
 #else
     return ucm_brk_syscall(0);
+#endif
+#else
+    return NULL;
 #endif
 }
