--- blip-0.1/msn_bittybits.C.orig	Mon Dec  9 20:31:41 2002
+++ blip-0.1/msn_bittybits.C	Thu Oct 23 20:02:19 2003
@@ -18,6 +18,8 @@
   char c;
   int pos=0, numspaces=0;
 
+  *numargs = 0;
+
   while(1)
   {
     if(read(sock, &c, 1)<1)
@@ -259,13 +261,16 @@
   {
     if(*rptr=='\0')
     { *wptr='\0'; break; }
+
     if(!(isalpha(*rptr) || isdigit(*rptr)))
     {
+      if ( *rptr != '\xc2' && *rptr != '\xb0' ) {
       sprintf(wptr, "%%%2x", (int)(*rptr));
 
       rptr++;
       wptr+=3;
       continue;
+    }
     }
 
     *wptr=*rptr;
