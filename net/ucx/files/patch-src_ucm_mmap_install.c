--- src/ucm/mmap/install.c.orig	2026-02-04 09:52:46 UTC
+++ src/ucm/mmap/install.c
@@ -86,8 +86,10 @@ static ucm_mmap_func_t ucm_mmap_funcs[] = {
 #endif
     { UCM_MMAP_RELOC_ENTRY(shmat),   UCM_EVENT_SHMAT,   UCM_EVENT_NONE},
     { UCM_MMAP_RELOC_ENTRY(shmdt),   UCM_EVENT_SHMDT,   UCM_EVENT_SHMAT},
+#ifdef HAVE_BRK_SBRK
     { UCM_MMAP_RELOC_ENTRY(sbrk),    UCM_EVENT_SBRK,    UCM_EVENT_NONE},
     { UCM_MMAP_RELOC_ENTRY(brk),     UCM_EVENT_BRK,     UCM_EVENT_NONE},
+#endif
     { UCM_MMAP_RELOC_ENTRY(madvise), UCM_EVENT_MADVISE, UCM_EVENT_NONE},
     { {NULL, NULL, NULL}, UCM_EVENT_NONE}
 };
@@ -135,6 +137,7 @@ static void ucm_mmap_event_test_callback(ucm_event_typ
     }
 }
 
+#ifdef HAVE_BRK_SBRK
 /* Call brk() and check return value, to avoid compile error of unused result */
 static void ucm_brk_checked(void *addr)
 {
@@ -143,6 +146,7 @@ static void ucm_brk_checked(void *addr)
         ucm_diag("brk(addr=%p) failed: %m", addr);
     }
 }
+#endif
 
 /* Fire events with pre/post action. The problem is in call sequence: we
  * can't just fire single event - most of the system calls require set of
@@ -199,6 +203,7 @@ ucm_fire_mmap_events_internal(int events, ucm_mmap_tes
     }
 
     if (exclusive && !RUNNING_ON_VALGRIND) {
+#ifdef HAVE_BRK_SBRK
         sbrk_size = ucm_get_page_size();
         if (events & (UCM_EVENT_BRK|UCM_EVENT_VM_MAPPED|UCM_EVENT_VM_UNMAPPED)) {
             p = ucm_get_current_brk();
@@ -213,14 +218,17 @@ ucm_fire_mmap_events_internal(int events, ucm_mmap_tes
             UCM_FIRE_EVENT(events, UCM_EVENT_SBRK|UCM_EVENT_VM_UNMAPPED,
                            data, (void)sbrk(-sbrk_size));
         }
+#endif
     } else {
         /* To avoid side effects on other threads and valgrind heap corruption,
          * pass invalid parameters. We assume that if the natives events are
          * delivered, it means VM_MAPPED/UNMAPPED would be delivered as well.
          */
+#ifdef HAVE_BRK_SBRK
         if (events & UCM_EVENT_BRK) {
             UCM_FIRE_EVENT(events, UCM_EVENT_BRK, data, ucm_brk_checked(NULL));
         }
+#endif
     }
 
     if (events & (UCM_EVENT_MADVISE|UCM_EVENT_VM_UNMAPPED)) {
