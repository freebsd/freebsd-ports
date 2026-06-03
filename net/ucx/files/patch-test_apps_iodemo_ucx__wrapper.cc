--- test/apps/iodemo/ucx_wrapper.cc.orig	2026-02-04 09:52:46 UTC
+++ test/apps/iodemo/ucx_wrapper.cc
@@ -118,10 +118,14 @@ UcxContext::UcxContext(size_t iomsg_size, double conne
     _iomsg_buffer(iomsg_size), _connect_timeout(connect_timeout),
     _use_am(use_am), _worker_fd(-1), _epoll_fd(-1), _client_id(client_id)
 {
+#if defined(__linux__)
     if (use_epoll) {
         _epoll_fd = epoll_create(1);
         assert(_epoll_fd >= 0);
     }
+#else
+    (void)use_epoll; /* epoll is Linux-only */
+#endif
 }
 
 UcxContext::~UcxContext()
@@ -359,6 +363,7 @@ int UcxContext::is_timeout_elapsed(struct timeval cons
     return ((elapsed.tv_sec + (elapsed.tv_usec * 1e-6)) > timeout);
 }
 
+#if defined(__linux__)
 ucs_status_t UcxContext::epoll_init()
 {
     ucs_status_t status;
@@ -414,6 +419,17 @@ bool UcxContext::progress_worker_event()
     assert(ev.data.fd == _worker_fd);
     return false;
 }
+#else
+ucs_status_t UcxContext::epoll_init()
+{
+    return UCS_OK;
+}
+
+bool UcxContext::progress_worker_event()
+{
+    return ucp_worker_progress(_worker) != 0;
+}
+#endif
 
 void UcxContext::progress_timed_out_conns()
 {
