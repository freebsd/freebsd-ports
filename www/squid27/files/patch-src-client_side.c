--- ./src/client_side.c.orig	Thu Jul  6 11:44:18 2006
+++ ./src/client_side.c	Thu Jul  6 11:52:07 2006
@@ -4490,6 +4490,13 @@
 	    return -1;
     }
 }
+#elif IPFW_TRANSPARENT
+static int inline
+clientNatLookup(ConnStateData * conn)
+{
+    static time_t last_reported = 0;
+    return 0;
+}
 #else
 static int inline
 clientNatLookup(ConnStateData * conn)
