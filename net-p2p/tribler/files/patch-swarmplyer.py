--- ../usr/share/tribler/Tribler/Player/swarmplayer.py.orig	2012-02-08 00:33:48.000000000 +0900
+++ ../usr/share/tribler/Tribler/Player/swarmplayer.py	2012-02-24 18:44:52.000000000 +0900
@@ -438,9 +438,9 @@
 
     s_play = status.get_or_create_status_element("playable", False)
     if playable:
+        global START_TIME
         if preprogress < 1.0:
             if s_play.get_value() == True:
-                global START_TIME
                 status.create_and_add_event("failed_after", [time.time() - START_TIME])
                 START_TIME = time.time()
                 
@@ -448,7 +448,6 @@
 
         elif s_play.get_value() == False:
             s_play.set_value(True)
-            global START_TIME
             status.create_and_add_event("playable_in", [time.time() - START_TIME])
             START_TIME = time.time()
 
