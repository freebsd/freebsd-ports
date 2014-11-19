--- vapi/libpq.vapi.orig	2014-02-03 19:35:53.000000000 +0000
+++ vapi/libpq.vapi	2014-03-10 10:22:09.771304414 +0000
@@ -20,11 +20,7 @@
  * 	Jukka-Pekka Iivonen <jp0409@jippii.fi>
  */
 
-#if LIBPQ_9_3
 [CCode (cprefix = "PQ", cheader_filename = "libpq-fe.h")]
-#else
-[CCode (cprefix = "PQ", cheader_filename = "postgresql/libpq-fe.h")]
-#endif
 namespace Postgres {
 
 	[CCode (cname = "ConnStatusType", cprefix = "CONNECTION_", has_type_id = false)]
