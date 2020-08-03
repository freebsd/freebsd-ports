--- lib/events/doc.go.orig	2020-07-08 18:08:40 UTC
+++ lib/events/doc.go
@@ -85,7 +85,7 @@ Main Audit Log Format
 
 The main log files are saved as:
 
-	/var/lib/teleport/log/<auth-server-id>/<date>.log
+	/var/db/teleport/log/<auth-server-id>/<date>.log
 
 The log file is rotated every 24 hours. The old files must be cleaned
 up or archived by an external tool.
@@ -111,7 +111,7 @@ Each session has its own session log stored as several
 
 Index file contains a list of event files and chunks files associated with a session:
 
-	/var/lib/teleport/log/sessions/<auth-server-id>/<session-id>.index
+	/var/db/teleport/log/sessions/<auth-server-id>/<session-id>.index
 
 The format of the index file contains of two or more lines with pointers to other files:
 
@@ -120,8 +120,8 @@ The format of the index file contains of two or more l
 
 Files:
 
-	/var/lib/teleport/log/<auth-server-id>/<session-id>-<first-event-in-file-index>.events
-	/var/lib/teleport/log/<auth-server-id>/<session-id>-<first-chunk-in-file-offset>.chunks
+	/var/db/teleport/log/<auth-server-id>/<session-id>-<first-event-in-file-index>.events
+	/var/db/teleport/log/<auth-server-id>/<session-id>-<first-chunk-in-file-offset>.chunks
 
 Where:
 	- .events   (same events as in the main log, but related to the session)
@@ -135,7 +135,7 @@ Examples
 In the simplest case, single auth server a1 log for a single session id s1
 will consist of three files:
 
-/var/lib/teleport/a1/s1.index
+/var/db/teleport/a1/s1.index
 
 With contents:
 
@@ -146,14 +146,14 @@ This means that all session events are located in s1-0
 the first event with index 0 and all chunks are located in file s1-0.chunks file
 with the byte offset from the start - 0.
 
-File with session events /var/lib/teleport/a1/s1-0.events will contain:
+File with session events /var/db/teleport/a1/s1-0.events will contain:
 
 {"ei":0,"event":"session.start", ...}
 {"ei":1,"event":"resize",...}
 {"ei":2,"ci":0, "event":"print","bytes":40,"offset":0}
 {"ei":3,"event":"session.end", ...}
 
-File with recorded session /var/lib/teleport/a1/s1-0.chunks will contain 40 bytes
+File with recorded session /var/db/teleport/a1/s1-0.chunks will contain 40 bytes
 emitted by print event with chunk index 0
 
 **Multiple Auth Servers**
@@ -164,7 +164,7 @@ In high availability mode scenario, multiple auth serv
 Any auth server can go down during session and clients will retry the delivery
 to the other auth server.
 
-Both auth servers have mounted /var/lib/teleport/log as a shared NFS folder.
+Both auth servers have mounted /var/db/teleport/log as a shared NFS folder.
 
 To make sure that only one auth server writes to a file at a time,
 each auth server writes to it's own file in a sub folder named
@@ -176,37 +176,37 @@ and the second batch of event to the second server a2.
 
 Server a1 will produce the following file:
 
-/var/lib/teleport/a1/s1.index
+/var/db/teleport/a1/s1.index
 
 With contents:
 
 {"file_name":"s1-0.events","type":"events","index":0}
 {"file_name":"s1-0.chunks","type":"chunks","offset":0}
 
-Events file /var/lib/teleport/a1/s1-0.events will contain:
+Events file /var/db/teleport/a1/s1-0.events will contain:
 
 {"ei":0,"event":"session.start", ...}
 {"ei":1,"event":"resize",...}
 {"ei":2,"ci":0, "event":"print","bytes":40,"offset":0}
 
-Events file /var/lib/teleport/a1/s1-0.chunks will contain 40 bytes
+Events file /var/db/teleport/a1/s1-0.chunks will contain 40 bytes
 emitted by print event with chunk index.
 
 Server a2 will produce the following file:
 
-/var/lib/teleport/a2/s1.index
+/var/db/teleport/a2/s1.index
 
 With contents:
 
 {"file_name":"s1-3.events","type":"events","index":3}
 {"file_name":"s1-40.chunks","type":"chunks","offset":40}
 
-Events file /var/lib/teleport/a2/s1-4.events will contain:
+Events file /var/db/teleport/a2/s1-4.events will contain:
 
 {"ei":3,"ci":1, "event":"print","bytes":15,"ms":713,"offset":40}
 {"ei":4,"event":"session.end", ...}
 
-Events file /var/lib/teleport/a2/s1-40.chunks will contain 15 bytes emitted
+Events file /var/db/teleport/a2/s1-40.chunks will contain 15 bytes emitted
 by print event with chunk index 1 and comes after delay of 713 milliseconds.
 
 Offset 40 indicates that the first chunk stored in the file s1-40.chunks
