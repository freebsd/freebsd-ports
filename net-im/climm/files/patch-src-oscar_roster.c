--- src/oscar_roster.c  23 Sep 2006 21:03:22 -0000      1.28
+++ src/oscar_roster.c  2 Nov 2006 22:28:05 -0000
@@ -117,6 +117,7 @@
     SnacCliReady (serv);
     SnacCliAddcontact (serv, NULL, serv->contacts);
     SnacCliReqofflinemsgs (serv);
+    SnacCliReqinfo (serv);
     if (serv->flags & CONN_WIZARD)
     {
         IMRoster (serv, IMROSTER_IMPORT);
