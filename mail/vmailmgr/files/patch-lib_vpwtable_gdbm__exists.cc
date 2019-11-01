--- lib/vpwtable/gdbm_exists.cc.orig	2002-11-20 15:54:44 UTC
+++ lib/vpwtable/gdbm_exists.cc
@@ -23,7 +23,7 @@ bool vpwtable::exists(const mystring& name) const
   GDBM_FILE db = gdbm_open((char*)filename.c_str(), 0, GDBM_READER, 0, 0);
   if(!db)
     return false;
-  datum key = { (char*)name.c_str(), name.length() };
+  datum key = { (char*)name.c_str(), static_cast<int>(name.length()) };
   bool result = gdbm_exists(db, key);
   gdbm_close(db);
   return result;
