--- nx-X11/programs/Xserver/hw/nxagent/Atoms.c.orig	2006-04-18 11:40:18.000000000 -0355
+++ nx-X11/programs/Xserver/hw/nxagent/Atoms.c
@@ -785,6 +785,8 @@
 
     nxagentWriteAtom(local, remote, string, True);
 
+    XFree(string);
+
     return local;
   }
 
