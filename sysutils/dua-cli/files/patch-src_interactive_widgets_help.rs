--- src/interactive/widgets/help.rs.orig	2021-06-29 23:43:34 UTC
+++ src/interactive/widgets/help.rs
@@ -168,6 +168,7 @@ impl HelpPane {
                     "Permanently delete all marked entries without prompt!",
                     Some("This operation cannot be undone!"),
                 );
+                #[cfg(feature = "trash-move")]
                 hotkey(
                     "Ctrl + t",
                     "Move all marked entries to the trash bin",
