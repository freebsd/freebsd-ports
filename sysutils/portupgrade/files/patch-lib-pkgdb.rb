--- lib/pkgdb.rb.orig	Mon Jun 19 13:50:29 2006
+++ lib/pkgdb.rb	Mon Jun 19 13:51:35 2006
@@ -606,17 +606,17 @@
   def get_db(mode, perm)
     case db_driver
     when :bdb_btree
-      db = BDB::Btree.open @db_file, nil, mode, perm, *@db_params
+      db = BDB::Btree.open @db_file, nil, mode.to_i, perm, *@db_params
     when :bdb_hash
-      db = BDB::Hash.open @db_file, nil, mode, perm, *@db_params
+      db = BDB::Hash.open @db_file, nil, mode.to_i, perm, *@db_params
     when :bdb1_btree
-      db = BDB1::Btree.open @db_file, mode, perm, *@db_params
+      db = BDB1::Btree.open @db_file, mode.to_i, perm, *@db_params
     when :bdb1_hash
-      db = BDB1::Hash.open @db_file, mode, perm, *@db_params
+      db = BDB1::Hash.open @db_file, mode.to_i, perm, *@db_params
     else
       if mode == 'w+'
 	File.unlink(@db_file) if File.exist?(@db_file)
-	db = DBM.open(@db_filebase, mode)
+	db = DBM.open(@db_filebase, mode.to_i)
       else
 	db = DBM.open(@db_filebase)
       end
