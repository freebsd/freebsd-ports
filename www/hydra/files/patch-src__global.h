--- src/globals.h.orig
+++ src/globals.h
@@ -103,7 +103,7 @@
     int pollfd_id;
 #endif
 #ifdef ENABLE_SSL
-    gnutls_session ssl_state;
+    gnutls_session_t ssl_state;
     char * certificate_verified; /* a string that describes the output of the
                                   * certificate verification function. Needed
                                   * in CGIs.
