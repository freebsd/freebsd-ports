--- scd/scdaemon.h.orig	2019-07-09 09:08:45 UTC
+++ scd/scdaemon.h
@@ -62,6 +62,8 @@ struct
   strlist_t disabled_applications;  /* Card applications we do not
                                        want to use. */
   unsigned long card_timeout; /* Disconnect after N seconds of inactivity.  */
+
+  int shared_access;
 } opt;
 
 
