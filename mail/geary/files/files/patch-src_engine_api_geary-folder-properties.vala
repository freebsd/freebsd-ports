diff --git src/engine/api/geary-folder-properties.vala src/engine/api/geary-folder-properties.vala
index f40cf7c..2f571da 100644
--- src/engine/api/geary-folder-properties.vala.orig
+++ src/engine/api/geary-folder-properties.vala
@@ -59,8 +59,16 @@ public abstract class Geary.FolderProperties : BaseObject {
      */
     public bool is_virtual { get; private set; }
     
+    /**
+     * True if APPEND on the folder will never return the created UID.  This is
+     * for servers that don't support UIDPLUS.  Most servers support UIDPLUS,
+     * so this will usually be false.
+     */
+    public bool create_never_returns_id { get; protected set; }
+    
     protected FolderProperties(int email_total, int email_unread, Trillian has_children,
-        Trillian supports_children, Trillian is_openable, bool is_local_only, bool is_virtual) {
+        Trillian supports_children, Trillian is_openable, bool is_local_only, bool is_virtual,
+        bool create_never_returns_id) {
         this.email_total = email_total;
         this.email_unread = email_unread;
         this.has_children = has_children;
@@ -68,6 +76,7 @@ public abstract class Geary.FolderProperties : BaseObject {
         this.is_openable = is_openable;
         this.is_local_only = is_local_only;
         this.is_virtual = is_virtual;
+        this.create_never_returns_id = create_never_returns_id;
     }
 }
 
