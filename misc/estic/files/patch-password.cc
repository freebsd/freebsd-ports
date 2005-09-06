--- spunk/password.cc.orig	Sat Feb 26 17:59:02 2000
+++ spunk/password.cc	Sat Feb 26 18:01:24 2000
@@ -525,14 +525,14 @@
 
 
 
-static void EntryEditor (PasswordEntry* E, int& Abort, int& Changed)
+inline void EntryEditor (PasswordEntry* E, int& Abort, int& Changed)
 // Allow editing of one password entry
 {
     // ID's of the menue items
-    const miUserID      = 1;
-    const miUserName    = 2;
-    const miPassword    = 3;
-    const miLevel       = 4;
+    const int miUserID      = 1;
+    const int miUserName    = 2;
+    const int miPassword    = 3;
+    const int miLevel       = 4;
 
      // Remember the crc of the entry
     u32 OldCRC = GetCRC (E);
