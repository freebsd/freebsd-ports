--- libgnomeui/gnome-ice.c.orig	Sun Mar 20 20:33:56 2005
+++ libgnomeui/gnome-ice.c	Sun Mar 20 20:34:21 2005
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
