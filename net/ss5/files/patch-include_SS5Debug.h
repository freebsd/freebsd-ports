--- include/SS5Debug.h.orig	2009-08-02 01:58:07.000000000 -0500
+++ include/SS5Debug.h
@@ -19,37 +19,37 @@
 #ifndef SS5DEBUG_H
 #define SS5DEBUG_H 1
 
-inline void
+void
   S5DebugMethodInfo( 	pid_t pid,
                         struct _SS5ClientInfo ci
 );
 
-inline void
+void
   S5DebugAuthInfo(	pid_t pid,
                         struct _SS5ClientInfo ci
 );
 
-inline void
+void
   S5DebugRequestInfo( 	pid_t pid,
                         struct _SS5RequestInfo ri
 );
 
-inline void
+void
  S5DebugUdpRequestInfo( pid_t pid,
                         struct _SS5RequestInfo ri
 );
 
-inline void
+void
   S5DebugUpstreamInfo(	pid_t pid,
                         struct _SS5RequestInfo ri
 );
 
-inline void
+void
   S5DebugFacilities( 	pid_t pid,
                         struct _SS5Facilities fa
 );
 
-inline void
+void
   S5DebugStatistics( 	pid_t pid
 );
 
