--- src/ucp/core/ucp_worker.h.orig	2026-02-05 12:41:56 UTC
+++ src/ucp/core/ucp_worker.h
@@ -319,6 +319,10 @@ typedef struct ucp_worker {
     int                              event_fd;            /* Allocated (on-demand) event fd for wakeup */
     ucs_sys_event_set_t              *event_set;          /* Allocated UCS event set for wakeup */
     int                              eventfd;             /* Event fd to support signal() calls */
+#if defined(__FreeBSD__)
+    int                              eventfd_write;       /* Write end of wakeup pipe (FreeBSD only).
+                                                           * eventfd holds the read end. */
+#endif
     unsigned                         uct_events;          /* UCT arm events */
     ucs_list_link_t                  arm_ifaces;          /* List of interfaces to arm */
 
