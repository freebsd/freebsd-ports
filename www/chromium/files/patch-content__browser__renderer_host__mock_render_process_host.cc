--- content/browser/renderer_host/mock_render_process_host.cc.orig	2010-12-16 02:11:57.000000000 +0100
+++ content/browser/renderer_host/mock_render_process_host.cc	2010-12-20 20:15:08.000000000 +0100
@@ -106,7 +106,7 @@
   DuplicateHandle(GetCurrentProcess(), dib_id.handle, GetCurrentProcess(),
                   &duped, 0, TRUE, DUPLICATE_SAME_ACCESS);
   transport_dib_ = TransportDIB::Map(duped);
-#elif defined(OS_MACOSX)
+#elif defined(OS_MACOSX) || defined(OS_FREEBSD)
   // On Mac, TransportDIBs are always created in the browser, so we cannot map
   // one from a dib_id.
   transport_dib_ = TransportDIB::Create(100 * 100 * 4, 0);
