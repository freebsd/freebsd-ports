--- mpmt_server.c.orig	2014-11-21 23:11:15.384531606 +0100
+++ mpmt_server.c	2014-11-21 23:11:47.359529681 +0100
@@ -49,7 +49,7 @@
 extern int MAX_SECS_TO_LINGER;
 extern int MAX_REQUESTS_BEFORE_REALLOCATE_MEM;
 extern int MAX_REQUESTS_PER_CHILD;
-extern struct ci_server_conf CONF;
+extern struct ci_server_conf CI_CONF;
 
 typedef struct server_decl {
      int srv_id;
@@ -232,13 +232,13 @@
      ci_thread_cond_broadcast(&(con_queue->queue_cond));
      /*wait for a milisecond*/
      ci_usleep(1000);
-     servers_running = CONF.THREADS_PER_CHILD;
+     servers_running = CI_CONF.THREADS_PER_CHILD;
      while (servers_running && wait_for_workers >= 0) {
          /*child_data->to_be_killed, may change while we are inside this loop*/
          if (child_data->to_be_killed == IMMEDIATELY) {
              CHILD_HALT = 1;
          }
-         for (i=0; i<CONF.THREADS_PER_CHILD; i++) {
+         for (i=0; i<CI_CONF.THREADS_PER_CHILD; i++) {
              if (threads_list[i] != NULL) { /* if the i thread is still alive*/
                  if (!threads_list[i]->running) { /*if the i thread is not running any more*/
                      ci_debug_printf(5, "Cancel server %d, thread_id %lu (%d)\n",
@@ -257,7 +257,7 @@
                      }
                  }
              }/*the i thread is still alive*/
-         } /* for(i=0;i< CONF.THREADS_PER_CHILD;i++)*/
+         } /* for(i=0;i< CI_CONF.THREADS_PER_CHILD;i++)*/
 
          /*wait for 1 second for the next round*/
          ci_usleep(999999);
@@ -411,7 +411,7 @@
       */
      old_childs_queue = childs_queue;
      childs_queue = malloc(sizeof(struct childs_queue));
-     if (!create_childs_queue(childs_queue, 2 * CONF.MAX_SERVERS)) {
+     if (!create_childs_queue(childs_queue, 2 * CI_CONF.MAX_SERVERS)) {
           ci_debug_printf(1,
                           "Cannot init shared memory. Fatal error, exiting!\n");
           return 0;              /*It is not enough. We must wait all childs to exit ..... */
@@ -419,10 +419,10 @@
      /*
         Start new childs to handle new requests.
       */
-     if (CONF.START_SERVERS > CONF.MAX_SERVERS)
-          CONF.START_SERVERS = CONF.MAX_SERVERS;
+     if (CI_CONF.START_SERVERS > CI_CONF.MAX_SERVERS)
+          CI_CONF.START_SERVERS = CI_CONF.MAX_SERVERS;
 
-     for (i = 0; i < CONF.START_SERVERS; i++) {
+     for (i = 0; i < CI_CONF.START_SERVERS; i++) {
           start_child(LISTEN_SOCKET);
      }
 
@@ -851,11 +851,11 @@
      ci_stat_attach_mem(child_data->stats, child_data->stats_size, NULL);
 
      threads_list =
-         (server_decl_t **) malloc((CONF.THREADS_PER_CHILD + 1) *
+         (server_decl_t **) malloc((CI_CONF.THREADS_PER_CHILD + 1) *
                                    sizeof(server_decl_t *));
-     con_queue = init_queue(CONF.THREADS_PER_CHILD);
+     con_queue = init_queue(CI_CONF.THREADS_PER_CHILD);
 
-     for (i = 0; i < CONF.THREADS_PER_CHILD; i++) {
+     for (i = 0; i < CI_CONF.THREADS_PER_CHILD; i++) {
           if ((threads_list[i] = newthread(con_queue)) == NULL) {
                exit(-1);        // FATAL error.....
           }
@@ -864,7 +864,7 @@
                                (void *) threads_list[i]);
           threads_list[i]->srv_pthread = thread;
      }
-     threads_list[CONF.THREADS_PER_CHILD] = NULL;
+     threads_list[CI_CONF.THREADS_PER_CHILD] = NULL;
      /*Now start the listener thread.... */
      ret = ci_thread_create(&thread, (void *(*)(void *)) listener_thread,
                             (void *) &sockfd);
@@ -957,7 +957,7 @@
           MY_PROC_PID = getpid();
           attach_childs_queue(childs_queue);
           child_data =
-              register_child(childs_queue, getpid(), CONF.THREADS_PER_CHILD, pfd[1]);
+              register_child(childs_queue, getpid(), CI_CONF.THREADS_PER_CHILD, pfd[1]);
           close(pfd[1]);
           child_main(fd, pfd[0]);
           exit(0);
@@ -1026,11 +1026,11 @@
      char command_buffer[COMMANDS_BUFFER_SIZE];
      int user_informed = 0;
 
-     ctl_socket = ci_named_pipe_create(CONF.COMMANDS_SOCKET);
+     ctl_socket = ci_named_pipe_create(CI_CONF.COMMANDS_SOCKET);
      if (ctl_socket < 0) {
           ci_debug_printf(1,
                           "Error opening control socket %s. Fatal error, exiting!\n",
-                          CONF.COMMANDS_SOCKET);
+                          CI_CONF.COMMANDS_SOCKET);
           exit(0);
      }
 
@@ -1040,7 +1040,7 @@
           exit(0);
      }
      childs_queue = malloc(sizeof(struct childs_queue));
-     if (!create_childs_queue(childs_queue, 2 * CONF.MAX_SERVERS)) {
+     if (!create_childs_queue(childs_queue, 2 * CI_CONF.MAX_SERVERS)) {
           ci_proc_mutex_destroy(&accept_mutex);
           ci_debug_printf(1,
                           "Can't init shared memory. Fatal error, exiting!\n");
@@ -1050,10 +1050,10 @@
      init_commands();
      pid = 1;
 #ifdef MULTICHILD
-     if (CONF.START_SERVERS > CONF.MAX_SERVERS)
-          CONF.START_SERVERS = CONF.MAX_SERVERS;
+     if (CI_CONF.START_SERVERS > CI_CONF.MAX_SERVERS)
+          CI_CONF.START_SERVERS = CI_CONF.MAX_SERVERS;
 
-     for (i = 0; i < CONF.START_SERVERS; i++) {
+     for (i = 0; i < CI_CONF.START_SERVERS; i++) {
           if (pid)
                pid = start_child(LISTEN_SOCKET);
      }
@@ -1068,7 +1068,7 @@
                }
                if (ret < 0) {  /*Eof received on pipe. Going to reopen ... */
                     ci_named_pipe_close(ctl_socket);
-                    ctl_socket = ci_named_pipe_open(CONF.COMMANDS_SOCKET);
+                    ctl_socket = ci_named_pipe_open(CI_CONF.COMMANDS_SOCKET);
                     if (ctl_socket < 0) {
                          ci_debug_printf(1,
                                          "Error opening control socket. We are unstable and going down!");
@@ -1100,16 +1100,16 @@
                     kill(childs_queue->childs[child_indx].pid, SIGTERM);
 
                }
-               else if ((freeservers <= CONF.MIN_SPARE_THREADS && childs < CONF.MAX_SERVERS)
-                        || childs < CONF.START_SERVERS) {
+               else if ((freeservers <= CI_CONF.MIN_SPARE_THREADS && childs < CI_CONF.MAX_SERVERS)
+                        || childs < CI_CONF.START_SERVERS) {
                     ci_debug_printf(8,
                                     "Free Servers: %d, children: %d. Going to start a child .....\n",
                                     freeservers, childs);
                     pid = start_child(LISTEN_SOCKET);
                }
-               else if (freeservers >= CONF.MAX_SPARE_THREADS &&
-                        childs > CONF.START_SERVERS &&
-                        (freeservers - CONF.THREADS_PER_CHILD) > CONF.MIN_SPARE_THREADS) {
+               else if (freeservers >= CI_CONF.MAX_SPARE_THREADS &&
+                        childs > CI_CONF.START_SERVERS &&
+                        (freeservers - CI_CONF.THREADS_PER_CHILD) > CI_CONF.MIN_SPARE_THREADS) {
 
                     if ((child_indx = find_an_idle_child(childs_queue)) >= 0) {
                          childs_queue->childs[child_indx].father_said =
@@ -1124,7 +1124,7 @@
 			 user_informed = 0;
                     }
                }
-               else if (childs == CONF.MAX_SERVERS && freeservers < CONF.MIN_SPARE_THREADS) {
+               else if (childs == CI_CONF.MAX_SERVERS && freeservers < CI_CONF.MIN_SPARE_THREADS) {
 		 if(! user_informed) {
 		         ci_debug_printf(1,
 					 "ATTENTION!!!! Not enough available servers (children %d, free servers %d, used servers %d)!!!!! "
@@ -1155,7 +1155,7 @@
 #else
      child_data = (child_shared_data_t *) malloc(sizeof(child_shared_data_t));
      child_data->pid = 0;
-     child_data->freeservers = CONF.THREADS_PER_CHILD;
+     child_data->freeservers = CI_CONF.THREADS_PER_CHILD;
      child_data->usedservers = 0;
      child_data->requests = 0;
      child_data->connections = 0;
