--- lib/vpwtable/gdbm_getbyname.cc.orig	2002-11-20 15:54:44 UTC
+++ lib/vpwtable/gdbm_getbyname.cc
@@ -24,7 +24,7 @@ vpwentry* vpwtable::getbyname(const mystring& name) co
   if(!db)
     return 0;
   mystring lower = name.lower();
-  datum key = { (char*)lower.c_str(), lower.length() };
+  datum key = { (char*)lower.c_str(), static_cast<int>(lower.length()) };
   datum result = gdbm_fetch(db, key);
   gdbm_close(db);
   return vpwentry::new_from_record(name, mystring(result.dptr, result.dsize));
