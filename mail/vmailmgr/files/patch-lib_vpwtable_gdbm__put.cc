--- lib/vpwtable/gdbm_put.cc.orig	2002-11-20 15:54:44 UTC
+++ lib/vpwtable/gdbm_put.cc
@@ -25,9 +25,9 @@ bool vpwtable::put(const vpwentry* vpw, bool onlyadd) 
   if(!db)
     return false;
   mystring name = vpw->name.lower();
-  datum key = { (char*)name.c_str(), name.length() };
+  datum key = { (char*)name.c_str(), static_cast<int>(name.length()) };
   mystring binary = vpw->to_record();
-  datum data = { (char*)binary.c_str(), binary.length() };
+  datum data = { (char*)binary.c_str(), static_cast<int>(binary.length()) };
   bool result = gdbm_store(db, key, data,
 			   onlyadd ? GDBM_INSERT : GDBM_REPLACE) == 0;
   gdbm_close(db);
