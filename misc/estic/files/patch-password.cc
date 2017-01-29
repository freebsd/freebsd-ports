--- spunk/password.cc.orig	1996-11-07 17:06:48 UTC
+++ spunk/password.cc
@@ -525,14 +525,14 @@ LINK (PasswordColl, ID_PasswordColl);
 
 
 
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
