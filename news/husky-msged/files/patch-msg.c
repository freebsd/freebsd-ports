--- msg.c.orig	Sun Nov 12 18:23:41 2006
+++ msg.c	Sun Nov 12 18:23:46 2006
@@ -58,7 +58,7 @@
 
 static struct _minf minf;
 
-static MSGA *Ahandle = NULL;     /* area handle */
+static MSG *Ahandle = NULL;     /* area handle */
 static MSGH *mh = NULL;         /* message handle */
 static XMSG xmsg;               /* squish message header */
 
