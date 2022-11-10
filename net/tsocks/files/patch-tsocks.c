--- tsocks.c.orig	2002-07-15 22:50:52 UTC
+++ tsocks.c
@@ -531,12 +531,12 @@ int poll(POLL_SIGNATURE) {
    /* If we're not currently managing any requests we can just 
     * leave here */
    if (!requests)
-      return(realpoll(ufds, nfds, timeout));
+      return(realpoll(fds, nfds, timeout));
 
    get_environment();
 
    show_msg(MSGDEBUG, "Intercepted call to poll with %d fds, "
-            "0x%08x timeout %d\n", nfds, ufds, timeout);
+            "0x%08x timeout %d\n", nfds, fds, timeout);
 
    for (conn = requests; conn != NULL; conn = conn->next)
       conn->selectevents = 0;
@@ -544,16 +544,16 @@ int poll(POLL_SIGNATURE) {
    /* Record what events on our sockets the caller was interested
     * in */
    for (i = 0; i < nfds; i++) {
-      if (!(conn = find_socks_request(ufds[i].fd, 0)))
+      if (!(conn = find_socks_request(fds[i].fd, 0)))
          continue;
       show_msg(MSGDEBUG, "Have event checks for socks enabled socket %d\n",
                conn->sockid);
-      conn->selectevents = ufds[i].events;
+      conn->selectevents = fds[i].events;
       monitoring = 1;
    }
 
    if (!monitoring)
-      return(realpoll(ufds, nfds, timeout));
+      return(realpoll(fds, nfds, timeout));
 
    /* This is our poll loop. In it we repeatedly call poll(). We 
     * pass select the same event list as provided by the caller except we
@@ -566,25 +566,25 @@ int poll(POLL_SIGNATURE) {
    do {
       /* Enable our sockets for the events WE want to hear about */
       for (i = 0; i < nfds; i++) {
-         if (!(conn = find_socks_request(ufds[i].fd, 0)))
+         if (!(conn = find_socks_request(fds[i].fd, 0)))
             continue;
 
          /* We always want to know about socket exceptions but they're 
           * always returned (i.e they don't need to be in the list of 
           * wanted events to be returned by the kernel */
-         ufds[i].events = 0;
+         fds[i].events = 0;
 
          /* If we're waiting for a connect or to be able to send
           * on a socket we want to get write events */
          if ((conn->state == SENDING) || (conn->state == CONNECTING))
-            ufds[i].events |= POLLOUT;
+            fds[i].events |= POLLOUT;
          /* If we're waiting to receive data we want to get 
           * read events */
          if (conn->state == RECEIVING)
-            ufds[i].events |= POLLIN;
+            fds[i].events |= POLLIN;
       }
 
-      nevents = realpoll(ufds, nfds, timeout);
+      nevents = realpoll(fds, nfds, timeout);
       /* If there were no events we must have timed out or had an error */
       if (nevents <= 0)
          break;
@@ -597,29 +597,29 @@ int poll(POLL_SIGNATURE) {
             continue;
 
          /* Find the socket in the poll list */
-         for (i = 0; ((i < nfds) && (ufds[i].fd != conn->sockid)); i++)
+         for (i = 0; ((i < nfds) && (fds[i].fd != conn->sockid)); i++)
             /* Empty Loop */;
          if (i == nfds) 
             continue;
 
          show_msg(MSGDEBUG, "Checking socket %d for events\n", conn->sockid);
 
-         if (!ufds[i].revents) {
+         if (!fds[i].revents) {
             show_msg(MSGDEBUG, "No events on socket\n");
             continue;
          }
 
          /* Clear any read or write events on the socket, we'll reset
           * any that are necessary later. */
-         setevents = ufds[i].revents;
+         setevents = fds[i].revents;
          if (setevents & POLLIN) {
             show_msg(MSGDEBUG, "Socket had read event\n");
-            ufds[i].revents &= ~POLLIN;
+            fds[i].revents &= ~POLLIN;
             nevents--;
          }
          if (setevents & POLLOUT) {
             show_msg(MSGDEBUG, "Socket had write event\n");
-            ufds[i].revents &= ~POLLOUT;
+            fds[i].revents &= ~POLLOUT;
             nevents--;
          }
          if (setevents & (POLLERR | POLLNVAL | POLLHUP)) 
@@ -669,10 +669,10 @@ int poll(POLL_SIGNATURE) {
 
    /* Now restore the events polled in each of the blocks */
    for (i = 0; i < nfds; i++) {
-      if (!(conn = find_socks_request(ufds[i].fd, 1)))
+      if (!(conn = find_socks_request(fds[i].fd, 1)))
          continue;
 
-      ufds[i].events = conn->selectevents;
+      fds[i].events = conn->selectevents;
    }
 
    return(nevents);
@@ -852,7 +852,7 @@ static int connect_server(struct connreq *conn) {
                     sizeof(conn->serveraddr));
 
    show_msg(MSGDEBUG, "Connect returned %d, errno is %d\n", rc, errno); 
-	if (rc) {
+	if (rc && errno != EISCONN) {
       if (errno != EINPROGRESS) {
          show_msg(MSGERR, "Error %d attempting to connect to SOCKS "
                   "server (%s)\n", errno, strerror(errno));
@@ -862,6 +862,7 @@ static int connect_server(struct connreq *conn) {
          conn->state = CONNECTING;
       }
    } else {
+      rc = 0;
       show_msg(MSGDEBUG, "Socket %d connected to SOCKS server\n", conn->sockid);
       conn->state = CONNECTED;
    }
