diff --git a/src/tools/rbd_ggate/main.cc b/src/tools/rbd_ggate/main.cc
index 67fe81942b4f..5ed582fbf81c 100644
--- src/tools/rbd_ggate/main.cc
+++ src/tools/rbd_ggate/main.cc
@@ -102,14 +102,13 @@ static int do_map(int argc, const char *argv[])
       std::cerr << err << std::endl;
       return r;
     }
-
     if (forker.is_parent()) {
-      global_init_postfork_start(g_ceph_context);
       if (forker.parent_wait(err) != 0) {
         return -ENXIO;
       }
       return 0;
     }
+    global_init_postfork_start(g_ceph_context);
   }
 
   common_init_finish(g_ceph_context);
@@ -204,9 +203,8 @@ static int do_map(int argc, const char *argv[])
   std::cout << "/dev/" << drv->get_devname() << std::endl;
 
   if (g_conf()->daemonize) {
-    forker.daemonize();
-    global_init_postfork_start(g_ceph_context);
     global_init_postfork_finish(g_ceph_context);
+    forker.daemonize();
   }
 
   init_async_signal_handler();
