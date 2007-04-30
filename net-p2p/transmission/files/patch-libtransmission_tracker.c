Index: /trunk/libtransmission/tracker.c
===================================================================
--- libtransmission/tracker.c (revision 1685)
+++ libtransmission/tracker.c (revision 1810)
@@ -516,16 +516,15 @@
     char         * event, * trackerid, * idparam;
     uint64_t       left;
-    uint64_t       down;
-    uint64_t       up;
     char           start;
     int            numwant = 50;
 
-    down = tor->downloadedCur;
-    up   = tor->uploadedCur;
     if( tc->started )
     {
         event = "&event=started";
-        down  = 0;
-        up    = 0;
+        
+        tor->downloadedPrev += tor->downloadedCur;
+        tor->downloadedCur   = 0;
+        tor->uploadedPrev   += tor->uploadedCur;
+        tor->uploadedCur     = 0;
 
         if( shouldChangePort( tc ) )
@@ -576,6 +575,6 @@
                           "%s",
                           tcInf->announce, start, tor->escapedHashString,
-                          tc->id, tc->publicPort, up, down, left, numwant,
-                          tor->key, idparam, trackerid, event );
+                          tc->id, tc->publicPort, tor->uploadedCur, tor->downloadedCur,
+                          left, numwant, tor->key, idparam, trackerid, event );
 }
 
