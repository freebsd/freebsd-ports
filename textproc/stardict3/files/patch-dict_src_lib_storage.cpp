--- dict/src/lib/storage.cpp.orig	2017-04-02 22:21:15 UTC
+++ dict/src/lib/storage.cpp
@@ -793,7 +793,7 @@ FileHolder Database_ResourceStorage::get_file_path(con
 	std::string name_pattern; // in file name encoding
 	if(!utf8_to_file_name(key, name_pattern))
 		return FileHolder();
-	std::string::size_type pos = name_pattern.find_last_of("."DB_DIR_SEPARATOR_S);
+	std::string::size_type pos = name_pattern.find_last_of("." DB_DIR_SEPARATOR_S);
 	if(pos != std::string::npos) {
 		if(name_pattern[pos] == '.')
 			name_pattern = name_pattern.substr(pos);
