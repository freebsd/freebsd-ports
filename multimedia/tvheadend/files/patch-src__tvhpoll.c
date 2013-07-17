--- src/tvhpoll.c.orig	2013-07-14 13:20:52.000000000 +0200
+++ src/tvhpoll.c	2013-07-14 16:54:00.375898773 +0200
@@ -121,10 +121,10 @@
   tvhpoll_alloc(tp, num);
   for (i = 0; i < num; i++) {
     if (evs[i].events & TVHPOLL_OUT){
-      EV_SET(tp->ev+i, evs[i].fd, EVFILT_WRITE, EV_ADD | EV_ENABLE, 0, 0, (void*)evs[i].data.u64);
+      EV_SET(tp->ev+i, evs[i].fd, EVFILT_WRITE, EV_ADD | EV_ENABLE, 0, 0, (intptr_t*)evs[i].data.u64);
     }
     if (evs[i].events & TVHPOLL_IN){
-      EV_SET(tp->ev+i, evs[i].fd, EVFILT_READ, EV_ADD | EV_ENABLE, 0, 0, (void*)evs[i].data.u64);
+      EV_SET(tp->ev+i, evs[i].fd, EVFILT_READ, EV_ADD | EV_ENABLE, 0, 0, (intptr_t*)evs[i].data.u64);
     }
   }
   return kevent(tp->fd, tp->ev, num, NULL, 0, NULL);
@@ -177,7 +177,7 @@
   for (i = 0; i < nfds; i++) {
     evs[i].fd       = tp->ev[i].ident;
     evs[i].events   = 0;
-    evs[i].data.u64 = (uint64_t)tp->ev[i].udata;
+    evs[i].data.u64 = (intptr_t)tp->ev[i].udata;
     if (tp->ev[i].filter & EVFILT_WRITE) evs[i].events |= TVHPOLL_OUT;
     if (tp->ev[i].filter & EVFILT_READ)  evs[i].events |= TVHPOLL_IN;
     if (tp->ev[i].flags  & EV_ERROR)     evs[i].events |= TVHPOLL_ERR;
