--- src/freebsd_sysctl.c.orig	2017-01-22 19:49:22 UTC
+++ src/freebsd_sysctl.c
@@ -828,7 +828,11 @@ int do_freebsd_sysctl(int update_every, 
         if (unlikely(GETSYSCTL("vm.stats.vm.v_active_count",    vmmeter_data.v_active_count) ||
                      GETSYSCTL("vm.stats.vm.v_inactive_count",  vmmeter_data.v_inactive_count) ||
                      GETSYSCTL("vm.stats.vm.v_wire_count",      vmmeter_data.v_wire_count) ||
+#if (__FreeBSD__ >= 12) && (__FreeBSD_version >= 1200016)
+                     0 ||
+#else
                      GETSYSCTL("vm.stats.vm.v_cache_count",     vmmeter_data.v_cache_count) ||
+#endif
                      GETSYSCTL("vfs.bufspace",                  vfs_bufspace_count) ||
                      GETSYSCTL("vm.stats.vm.v_free_count",      vmmeter_data.v_free_count))) {
             do_ram = 0;
@@ -850,7 +854,11 @@ int do_freebsd_sysctl(int update_every, 
             rrddim_set(st, "active",    vmmeter_data.v_active_count);
             rrddim_set(st, "inactive",  vmmeter_data.v_inactive_count);
             rrddim_set(st, "wired",     vmmeter_data.v_wire_count);
+#if (__FreeBSD__ >= 12) && (__FreeBSD_version >= 1200016)
+            rrddim_set(st, "cache",     0);
+#else
             rrddim_set(st, "cache",     vmmeter_data.v_cache_count);
+#endif
             rrddim_set(st, "buffers",   vfs_bufspace_count);
             rrddim_set(st, "free",      vmmeter_data.v_free_count);
             rrdset_done(st);
