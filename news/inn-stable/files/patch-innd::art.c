--- innd/art.c.orig	Sat Jul 12 19:40:34 2003
+++ innd/art.c	Thu Jan  8 10:09:34 2004
@@ -1773,7 +1773,7 @@
 bool
 ARTpost(CHANNEL *cp)
 {
-  char		*p, **groups, ControlWord[SMBUF], tmpbuff[32], **hops;
+  char		*p, **groups, ControlWord[SMBUF], **hops, *controlgroup;
   int		i, j, *isp, hopcount, oerrno, canpost;
   NEWSGROUP	*ngp, **ngptr;
   SITE		*sp;
@@ -2184,9 +2184,10 @@
    * or control. */
   if (IsControl && Accepted && !ToGroup) {
     ControlStore = true;
-    FileGlue(tmpbuff, "control", '.', ControlWord);
-    if ((ngp = NGfind(tmpbuff)) == NULL)
+    controlgroup = concat("control.", ControlWord, (char *) 0);
+    if ((ngp = NGfind(controlgroup)) == NULL)
       ngp = NGfind(ARTctl);
+    free(controlgroup);
     ngp->PostCount = 0;
     ngptr = GroupPointers;
     *ngptr++ = ngp;
