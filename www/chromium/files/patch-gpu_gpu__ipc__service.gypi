--- gpu/gpu_ipc_service.gypi.orig	2016-05-27 10:20:52.022966000 -0400
+++ gpu/gpu_ipc_service.gypi	2016-05-27 10:21:13.721757000 -0400
@@ -82,7 +82,7 @@
         ],
       },
     }],
-    ['OS=="linux"', {
+    ['OS=="linux" or os_bsd==1', {
       'sources': [ 'ipc/service/image_transport_surface_linux.cc' ],
     }],
     ['use_x11 == 1 and (target_arch != "arm" or chromeos == 0)', {
