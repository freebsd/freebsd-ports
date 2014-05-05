From 730b33d806aea9653eb656e3be4adcd73c10dfd6 Mon Sep 17 00:00:00 2001
From: Charles Lindsay <chaz@yorba.org>
Date: Fri, 4 Apr 2014 13:01:01 -0700
Subject: Don't save draft when UIDPLUS is not present: Closes bgo#713983

Without UIDPLUS Geary currently cannot determine the UID of the drafts
it saves to the server, and so it cannot delete them when the draft is
saved again or the message is sent.  This patch simply checks if
UIDPLUS is supported, and if not, does not save the draft to the
server.

Although a string is included in this patch, it's a duplicate of an
existing string and so technically does not break string freeze.

diff --git src/client/composer/composer-window.vala src/client/composer/composer-window.vala
index d0a83e4..7351e2f 100644
--- src/client/composer/composer-window.vala.orig
+++ src/client/composer/composer-window.vala
@@ -667,28 +667,39 @@ public class ComposerWindow : Gtk.Window {
         update_from_field();
     }
     
+    private bool can_save() {
+        return (drafts_folder != null && drafts_folder.get_open_state() == Geary.Folder.OpenState.BOTH
+            && !drafts_folder.properties.create_never_returns_id && editor.can_undo());
+    }
+
     public bool should_close() {
-        if (!editor.can_undo())
-            return true;
+        bool try_to_save = can_save();
         
         present();
         AlertDialog dialog;
         
-        if (drafts_folder == null) {
+        if (drafts_folder == null && try_to_save) {
             dialog = new ConfirmationDialog(this,
                 _("Do you want to discard the unsaved message?"), null, Stock._DISCARD);
-        } else {
+        } else if (try_to_save) {
             dialog = new TernaryConfirmationDialog(this,
                 _("Do you want to discard this message?"), null, Stock._KEEP, Stock._DISCARD,
                 Gtk.ResponseType.CLOSE);
+        } else {
+            dialog = new ConfirmationDialog(this,
+                _("Do you want to discard this message?"), null, Stock._DISCARD);
         }
         
         Gtk.ResponseType response = dialog.run();
         if (response == Gtk.ResponseType.CANCEL || response == Gtk.ResponseType.DELETE_EVENT) {
             return false; // Cancel
         } else if (response == Gtk.ResponseType.OK) {
-            save_and_exit.begin(); // Save
-            return false;
+            if (try_to_save) {
+                save_and_exit.begin(); // Save
+                return false;
+            } else {
+                return true;
+            }
         } else {
             delete_and_exit.begin(); // Discard
             return false;
@@ -798,6 +809,11 @@ public class ComposerWindow : Gtk.Window {
         destroy(); // Only close window after draft is deleted; this closes the drafts folder.
     }
     
+    private void on_drafts_opened(Geary.Folder.OpenState open_state, int count) {
+        if (open_state == Geary.Folder.OpenState.BOTH)
+            reset_draft_timer();
+    }
+    
     // Returns the drafts folder for the current From account.
     private async void open_drafts_folder_async(Cancellable cancellable) throws Error {
         yield close_drafts_folder_async(cancellable);
@@ -808,9 +824,11 @@ public class ComposerWindow : Gtk.Window {
         if (folder == null)
             return; // No drafts folder.
         
-        yield folder.open_async(Geary.Folder.OpenFlags.FAST_OPEN, cancellable);
+        yield folder.open_async(Geary.Folder.OpenFlags.FAST_OPEN | Geary.Folder.OpenFlags.NO_DELAY,
+            cancellable);
         
         drafts_folder = folder;
+        drafts_folder.opened.connect(on_drafts_opened);
     }
     
     private async void close_drafts_folder_async(Cancellable? cancellable = null) throws Error {
@@ -818,6 +836,7 @@ public class ComposerWindow : Gtk.Window {
             return;
         
         // Close existing folder.
+        drafts_folder.opened.disconnect(on_drafts_opened);
         yield drafts_folder.close_async(cancellable);
         drafts_folder = null;
     }
@@ -835,7 +854,7 @@ public class ComposerWindow : Gtk.Window {
     }
     
     private async void save_async(Cancellable? cancellable) {
-        if (drafts_folder == null)
+        if (drafts_folder == null || !can_save())
             return;
         
         draft_save_label.label = DRAFT_SAVING_TEXT;
@@ -1555,7 +1574,7 @@ public class ComposerWindow : Gtk.Window {
     
     // Resets the draft save timeout.
     private void reset_draft_timer() {
-        if (!editor.can_undo())
+        if (!can_save())
             return;
         
         draft_save_label.label = "";
