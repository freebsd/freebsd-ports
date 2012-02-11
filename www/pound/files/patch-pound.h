--- ./pound.h.orig	2012-02-11 22:51:17.579834493 +0000
+++ ./pound.h	2012-02-11 22:51:28.220833901 +0000
@@ -323,6 +323,10 @@
 /* maximal session key size */
 #define KEY_SIZE    127
 
+#if OPENSSL_VERSION_NUMBER >= 0x10000000L
+DECLARE_LHASH_OF(TABNODE);
+#endif
+
 /* service definition */
 typedef struct _service {
     char                name[KEY_SIZE + 1]; /* symbolic name */
@@ -338,7 +342,11 @@
     int                 sess_ttl;   /* session time-to-live */
     regex_t             sess_start; /* pattern to identify the session data */
     regex_t             sess_pat;   /* pattern to match the session data */
+#if OPENSSL_VERSION_NUMBER >= 0x10000000L
+    LHASH_OF(TABNODE)   *sessions;  /* currently active sessions */
+#else
     LHASH               *sessions;  /* currently active sessions */
+#endif
     int                 dynscale;   /* true if the back-ends should be dynamically rescaled */
     int                 disabled;   /* true if the service is disabled */
     struct _service     *next;
