--- io/hpiod/system.cpp.orig	Mon Jul 23 14:08:51 2007
+++ io/hpiod/system.cpp	Mon Jul 23 14:09:52 2007
@@ -633,7 +633,7 @@
    list_for_each(p, &head.list)
    {
       psa = list_entry(p, SessionAttributes, list);
-      lstLen += sprintf(lst+lstLen, "t[%d] d[%d] socket=%d\n", (int)psa->tid, psa->descriptor, psa->sockid);   
+      lstLen += sprintf(lst+lstLen, "t[%d] d[%d] socket=%d\n", (unsigned long)psa->tid, psa->descriptor, psa->sockid);   
    }
 
    len = sprintf(sendBuf, "msg=PStateResult\nresult-code=%d\nlength=%d\ndata:\n%s", R_AOK, lstLen, lst); 
