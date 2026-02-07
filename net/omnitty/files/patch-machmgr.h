--- machmgr.h.orig	2005-10-25 22:04:01 UTC
+++ machmgr.h
@@ -106,6 +106,10 @@ void machmgr_delete_dead();
 /* Deletes all tagged machines */
 void machmgr_delete_tagged();
 
+/* Toggles tagged status of all machines. If ignore_dead, does not
+ * tag dead machines (i.e. machines whose alive flag is down). */
+void machmgr_toggle_tag_all(bool ignore_dead);
+
 /* Tags all machines. If ignore_dead, does not tag dead machines (i.e. machines
  * whose alive flag is down). */
 void machmgr_tag_all(bool ignore_dead);
