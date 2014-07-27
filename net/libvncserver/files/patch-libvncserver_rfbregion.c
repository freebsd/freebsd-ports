--- ./libvncserver/rfbregion.c.orig	2014-07-01 23:00:03.428441834 +1000
+++ ./libvncserver/rfbregion.c	2014-07-01 23:00:14.275274256 +1000
@@ -751,7 +751,7 @@
       i->ptrSize += DEFSTEP;
       i->sPtrs = (sraSpan**)realloc(i->sPtrs, sizeof(sraSpan*)*i->ptrSize);
     }
-    i->ptrPos =+ 2;
+    i->ptrPos += 2;
     if(sraReverse(i)) {
       i->sPtrs[i->ptrPos]   =   i->sPtrs[i->ptrPos-2]->subspan->back._prev;
       i->sPtrs[i->ptrPos+1] = &(i->sPtrs[i->ptrPos-2]->subspan->front);
