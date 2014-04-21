--- include/SS5Server.h.orig	2009-08-02 01:58:07.000000000 -0500
+++ include/SS5Server.h
@@ -31,7 +31,7 @@ UINT
   S5ServerClose(	int exitcode
 );
 
-inline UINT
+UINT
   S5ChildClose(		int exitcode,
                         UINT childSocket,
 			struct _SS5ClientInfo *ci
