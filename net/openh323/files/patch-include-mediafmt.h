--- ../openh323.orig/work/openh323_v1_18_0/include/mediafmt.h	2005-11-30 08:05:01.000000000 -0500
+++ include/mediafmt.h	2008-01-05 23:12:39.000000000 -0500
@@ -163,9 +163,13 @@
     RTP_DataFrame::PayloadTypes GetPayloadType() const { return rtpPayloadType; }
 
     enum {
-      DefaultAudioSessionID = 1,
-      DefaultVideoSessionID = 2,
-      DefaultDataSessionID  = 3
+      FirstSessionID            = 1,
+      DefaultAudioSessionID     = 1,
+      DefaultVideoSessionID     = 2,
+      DefaultDataSessionID      = 3,
+      DefaultH224SessionID      = 4,
+      DefaultExtVideoSessionID  = 5,
+      LastSessionID             = 5
     };
 
     /**Get the default session ID for media format.
