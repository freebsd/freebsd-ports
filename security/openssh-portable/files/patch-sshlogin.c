--- sshlogin.c.orig	Wed Sep  4 08:45:11 2002
+++ sshlogin.c	Fri Dec 13 22:58:07 2002
@@ -70,7 +70,7 @@
   struct logininfo *li;
 
   li = login_alloc_entry(pid, user, host, ttyname);
-  login_set_addr(li, addr, sizeof(struct sockaddr));
+  login_set_addr(li, addr, addrlen);
   login_login(li);
   login_free_entry(li);
 }
