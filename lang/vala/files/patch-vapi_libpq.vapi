--- vapi/libpq.vapi.orig	2009-07-17 21:34:39.000000000 +0600
+++ vapi/libpq.vapi	2009-11-23 01:18:21.000000000 +0500
@@ -22,7 +22,7 @@
 
 using GLib;
 
-[CCode (cprefix = "PQ", cheader_filename = "postgresql/libpq-fe.h")]
+[CCode (cprefix = "PQ", cheader_filename = "libpq-fe.h")]
 namespace Postgres {
 
 	[CCode (cname = "ConnStatusType", cprefix = "CONNECTION_")]
