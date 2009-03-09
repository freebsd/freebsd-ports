--- ../ark/plugins/libarchive/libarchivehandler.cpp.orig	2009-02-01 00:16:54.000000000 +0100
+++ ../ark/plugins/libarchive/libarchivehandler.cpp	2009-02-01 00:19:50.000000000 +0100
@@ -567,7 +567,7 @@
 		}
 	}
 
-	ret = archive_write_finish(arch_writer);
+	archive_write_finish(arch_writer);
 
 	if (!creatingNewFile) {
 		archive_read_finish( arch_reader );
@@ -700,7 +700,7 @@
 		archive_entry_clear( entry );
 	}
 
-	ret = archive_write_finish(arch_writer);
+	archive_write_finish(arch_writer);
 
 	archive_read_finish( arch_reader );
 
