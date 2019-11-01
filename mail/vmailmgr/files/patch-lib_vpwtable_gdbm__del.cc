--- lib/vpwtable/gdbm_del.cc.orig	2002-11-20 15:54:44 UTC
+++ lib/vpwtable/gdbm_del.cc
@@ -23,7 +23,7 @@ bool vpwtable::del(const mystring& name) const
   GDBM_FILE db = gdbm_open((char*)filename.c_str(), 0, GDBM_WRITER, 0, 0);
   if(!db)
     return false;
-  datum key = { (char*)name.c_str(), name.length() };
+  datum key = { (char*)name.c_str(), static_cast<int>(name.length()) };
   bool result = gdbm_delete(db, key) == 0;
   gdbm_close(db);
   return result;
