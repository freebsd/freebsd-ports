--- libgnomeui/gnome-ice.c.orig	Fri Oct 22 23:22:11 2004
+++ libgnomeui/gnome-ice.c	Fri Oct 22 23:22:38 2004
@@ -54,6 +54,8 @@
   IceConn connection = (IceConn) data;
   IceProcessMessagesStatus status;
 
+  GDK_THREADS_ENTER();
+
   status = IceProcessMessages (connection, NULL, NULL);
 
   if (status == IceProcessMessagesIOError)
@@ -73,6 +75,8 @@
 	  IceCloseConnection (connection);
 	}
     }
+
+  GDK_THREADS_LEAVE();
 
   return TRUE;
 }
