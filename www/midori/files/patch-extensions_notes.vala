--- extensions/notes.vala.orig	2015-08-30 11:56:26 UTC
+++ extensions/notes.vala
@@ -116,7 +116,11 @@ namespace ClipNotes {
                     if (current_note == note) {
                         current_note = null;
                     }
+#if VALA_0_36
+                    notes_list_store.remove (ref iter);
+#else
                     notes_list_store.remove (iter);
+#endif
                     break;
                 }
             } while (notes_list_store.iter_next (ref iter));
