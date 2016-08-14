diff --git sysdep/unix/io.c sysdep/unix/io.c
index 486319f..8198743 100644
--- sysdep/unix/io.c
+++ sysdep/unix/io.c
@@ -1211,7 +1211,7 @@ sk_setup(sock *s)
   if (s->iface)
   {
 #ifdef SO_BINDTODEVICE
-    struct ifreq ifr;
+    struct ifreq ifr = {};
     strcpy(ifr.ifr_name, s->iface->name);
     if (setsockopt(s->fd, SOL_SOCKET, SO_BINDTODEVICE, &ifr, sizeof(ifr)) < 0)
       ERR("SO_BINDTODEVICE");
@@ -1854,6 +1854,20 @@ sk_write(sock *s)
 }
 
 void
+sk_err(sock *s, int revents)
+{
+  int se = 0, sse = sizeof(se);
+  if (revents & POLLERR)
+    if (getsockopt(s->fd, SOL_SOCKET, SO_ERROR, &se, &sse) < 0)
+    {
+      log(L_ERR "IO: Socket error: SO_ERROR: %m");
+      se = 0;
+    }
+
+  s->err_hook(s, se);
+}
+
+void
 sk_dump_all(void)
 {
   node *n;
@@ -2163,7 +2177,7 @@ io_loop(void)
 	      int steps;
 
 	      steps = MAX_STEPS;
-	      if (s->fast_rx && (pfd[s->index].revents & (POLLIN | POLLHUP | POLLERR)) && s->rx_hook)
+	      if (s->fast_rx && (pfd[s->index].revents & POLLIN) && s->rx_hook)
 		do
 		  {
 		    steps--;
@@ -2185,6 +2199,7 @@ io_loop(void)
 		      goto next;
 		  }
 		while (e && steps);
+
 	      current_sock = sk_next(s);
 	    next: ;
 	    }
@@ -2208,18 +2223,26 @@ io_loop(void)
 		  goto next2;
 		}
 
-	      if (!s->fast_rx && (pfd[s->index].revents & (POLLIN | POLLHUP | POLLERR)) && s->rx_hook)
+	      if (!s->fast_rx && (pfd[s->index].revents & POLLIN) && s->rx_hook)
 		{
 		  count++;
 		  io_log_event(s->rx_hook, s->data);
 		  sk_read(s, pfd[s->index].revents);
 		  if (s != current_sock)
-		      goto next2;
+		    goto next2;
+		}
+
+	      if (pfd[s->index].revents & (POLLHUP | POLLERR))
+		{
+		  sk_err(s, pfd[s->index].revents);
+		    goto next2;
 		}
+
 	      current_sock = sk_next(s);
 	    next2: ;
 	    }
 
+
 	  stored_sock = current_sock;
 	}
     }
