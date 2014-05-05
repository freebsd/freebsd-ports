From 201af223c2cd7265ec60b4a1f608405d264f9351 Mon Sep 17 00:00:00 2001
From: Jim Nelson <jim@yorba.org>
Date: Mon, 21 Apr 2014 11:17:03 -0700
Subject: Prevent AccountSynchronizier from deadlocking under certain
 conditions

The AccountSynchronizer could deadlock waiting for an EmailPrefetcher
to finish under certain conditions, particularly if the folder closed
before the prefetcher was finished.  This lead to a state where the
AccountSynchronizer would never synchronize against unopened folders.
If Geary was left open for a long time and the user clicked on All
Mail, rather than the current state of that folder appearing
immediately, it could take a moment for Geary to fetch the envelopes
and headers/bodies.

Fixing this closes bgo#713447, which was also due to other bugs that
have been fixed over time (in particular, the startup speedup work in
0.5) and better spinner management (bgo#713703).  It also corrects
a problem where detection of new mail while opening the folder let
to prefetching that mail, which was unnecessary because once the
folder is fully opened all unsynchronized mail is detected and pulled
down.

diff --git src/engine/imap-engine/imap-engine-email-prefetcher.vala src/engine/imap-engine/imap-engine-email-prefetcher.vala
index 4fd3a47..76c36dc 100644
--- src/engine/imap-engine/imap-engine-email-prefetcher.vala.orig
+++ src/engine/imap-engine/imap-engine-email-prefetcher.vala
@@ -70,10 +70,18 @@ private class Geary.ImapEngine.EmailPrefetcher : Object {
         if (schedule_id != 0) {
             Source.remove(schedule_id);
             schedule_id = 0;
+            
+            // since an acquire was done when scheduled, need to notify when cancelled
+            active_sem.blind_notify();
         }
     }
     
     private void on_local_expansion(Gee.Collection<Geary.EmailIdentifier> ids) {
+        // it's possible to be notified of an append prior to remote open; don't prefetch until
+        // that occurs
+        if (folder.get_open_state() != Geary.Folder.OpenState.BOTH)
+            return;
+        
         // acquire here since .begin() only schedules for later
         active_sem.acquire();
         do_prepare_new_async.begin(ids);
