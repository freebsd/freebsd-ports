--- sysdep/bsd/krt-sock.c.orig	2011-05-11 10:41:35.432219356 +0400
+++ sysdep/bsd/krt-sock.c	2011-05-11 10:42:02.483875083 +0400
@@ -320,7 +320,7 @@
   if ((flags & RTF_GATEWAY) && ipa_zero(igate))
     { log(L_ERR "%s (%I/%d) - missing gateway", errmsg, idst, pxlen); return; }
 
-  u32 self_mask = RTF_PROTO1;
+  u32 self_mask = 0;
   u32 alien_mask = RTF_STATIC | RTF_PROTO1 | RTF_GATEWAY;
 
 #ifdef RTF_PROTO2
