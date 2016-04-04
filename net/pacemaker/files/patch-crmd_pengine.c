On FreeBSD the maximum IPC buffer size is defined by the kern.ipc.maxsockbuf
sysctl which defaults to 2M.  This patch simply lowers the max message size
in pengine from 5M to 1M to work out of the box without requiring any tuning.

--- crmd/pengine.c.orig	2016-01-14 21:43:08 UTC
+++ crmd/pengine.c
@@ -163,7 +163,7 @@ do_pe_control(long long action,
 
             pe_subsystem->source =
                 mainloop_add_ipc_client(CRM_SYSTEM_PENGINE, G_PRIORITY_DEFAULT,
-                                        5 * 1024 * 1024 /* 5Mb */ , NULL, &pe_callbacks);
+                                        1024 * 1024 /* 1Mb */ , NULL, &pe_callbacks);
 
             if (pe_subsystem->source == NULL) {
                 crm_warn("Setup of client connection failed, not adding channel to mainloop");
