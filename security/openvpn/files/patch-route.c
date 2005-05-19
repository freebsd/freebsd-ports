--- route.c.orig	Mon Apr 11 05:43:56 2005
+++ route.c	Mon May 16 21:13:41 2005
@@ -1380,6 +1380,7 @@
     {
       warn("writing to routing socket");
       gc_free (&gc);
+      close(s);
       return false;
     }
 
@@ -1387,6 +1388,7 @@
     l = read(s, (char *)&m_rtmsg, sizeof(m_rtmsg));
   } while (l > 0 && (rtm.rtm_seq != seq || rtm.rtm_pid != pid));
                         
+  close(s);
 
   rtm_aux = &rtm;
 
@@ -1535,6 +1537,7 @@
     {
       msg (M_WARN, "ROUTE: problem writing to routing socket");
       gc_free (&gc);
+      close(s);
       return false;
     }
 
@@ -1542,6 +1545,7 @@
     l = read(s, (char *)&m_rtmsg, sizeof(m_rtmsg));
   } while (l > 0 && (rtm.rtm_seq != seq || rtm.rtm_pid != pid));
                         
+  close(s);
 
   rtm_aux = &rtm;
 
@@ -1690,6 +1694,7 @@
     {
       warn("writing to routing socket");
       gc_free (&gc);
+      close(s);
       return false;
     }
 
@@ -1697,6 +1702,7 @@
     l = read(s, (char *)&m_rtmsg, sizeof(m_rtmsg));
   } while (l > 0 && (rtm.rtm_seq != seq || rtm.rtm_pid != pid));
                         
+  close(s);
 
   rtm_aux = &rtm;
 
