--- src/interactive/widgets/mark.rs.orig	2021-06-29 23:43:34 UTC
+++ src/interactive/widgets/mark.rs
@@ -28,6 +28,7 @@ use unicode_segmentation::UnicodeSegmentation;
 
 pub enum MarkMode {
     Delete,
+    #[cfg(feature = "trash-move")]
     Trash,
 }
 
@@ -110,6 +111,7 @@ impl MarkPane {
         let action = None;
         match key {
             Ctrl('r') => return Some(self.prepare_deletion(MarkMode::Delete)),
+            #[cfg(feature = "trash-move")]
             Ctrl('t') => return Some(self.prepare_deletion(MarkMode::Trash)),
             Char('x') | Char('d') | Char(' ') => {
                 return self.remove_selected().map(|s| (s, action))
@@ -360,6 +362,7 @@ impl MarkPane {
                 sub_modifier: Modifier::empty(),
             };
             Paragraph::new(Text::from(Spans::from(vec![
+                #[cfg(feature = "trash-move")]
                 Span::styled(
                     " Ctrl + t",
                     Style {
@@ -368,6 +371,7 @@ impl MarkPane {
                         ..default_style
                     },
                 ),
+                #[cfg(feature = "trash-move")]
                 Span::styled(" to trash or ", default_style),
                 Span::styled(
                     " Ctrl + r",
