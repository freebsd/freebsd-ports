Invalid integer/pointer conversion.  Already fixed upstream:
https://github.com/c-icap/c-icap-server/commit/8ef8966237865ec699ab16d208ff56edaac4ff7b

Index: mpmt_server.c
--- mpmt_server.c.orig	2021-09-02 14:45:30 UTC
+++ mpmt_server.c
@@ -75,7 +75,7 @@ server_decl_t **threads_list = NULL;
 
 ci_thread_mutex_t threads_list_mtx;
 server_decl_t **threads_list = NULL;
-ci_thread_t listener_thread_id = -1;
+ci_thread_t listener_thread_id;
 int listener_running = 0;
 
 ci_thread_cond_t free_server_cond;
