--- scan.c.orig	2016-06-20 13:13:56 UTC
+++ scan.c
@@ -1816,7 +1816,11 @@ static int set_frontend(int frontend_fd,
                                 case SCAN_TERRESTRIAL:
                                         set_cmd_sequence(DTV_DELIVERY_SYSTEM,   t->param.u.terr.delivery_system);
                                         if (t->param.u.terr.delivery_system == SYS_DVBT2) {
+#ifndef DTV_DVBT2_PLP_ID
+                                           set_cmd_sequence(DTV_DVBT2_PLP_ID_LEGACY, t->pids.plp_id);
+#else
                                            set_cmd_sequence(DTV_DVBT2_PLP_ID, t->pids.plp_id);
+#endif
                                            }
                                         set_cmd_sequence(DTV_FREQUENCY,         t->param.frequency);
                                         set_cmd_sequence(DTV_INVERSION,         t->param.inversion);
@@ -3010,8 +3014,8 @@ int main (int argc, char **argv)
                 cleanup();
                 return -1;
                 }
-        if  (((adapter > 7) && (adapter != 999)) || (adapter < 0)) {
-                info("Invalid adapter: out of range (0..7)\n");
+        if  (((adapter > 255) && (adapter != 999)) || (adapter < 0)) {
+                info("Invalid adapter: out of range (0..255)\n");
                 bad_usage(argv[0]);
                 cleanup();
                 return -1;
