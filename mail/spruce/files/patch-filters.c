
$FreeBSD$

--- filters.c.orig	Sun Aug 22 17:24:12 2004
+++ filters.c	Sun Aug 22 17:24:23 2004
@@ -514,7 +514,7 @@
          gtk_entry_set_text(GTK_ENTRY(GTK_COMBO(move_combo)->entry), "");
          gtk_entry_set_text(GTK_ENTRY(forward_entry), "");
          break;
-      default:
+      default: break;
    }
 }
  
