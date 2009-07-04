$FreeBSD$

--- src/comp/comp.c.orig	2009-07-03 21:10:25.000000000 -0700
+++ src/comp/comp.c	2009-07-03 21:12:26.000000000 -0700
@@ -699,6 +699,14 @@
     return (string *) NULL;
 }
 
+#ifdef NETWORK_PACKAGE
+bool comm_is_connection(obj)
+object *obj;
+{
+    return FALSE;
+}
+#endif
+
 /*
  * NAME:	comm->close()
  * DESCRIPTION:	pretend to remove a user
