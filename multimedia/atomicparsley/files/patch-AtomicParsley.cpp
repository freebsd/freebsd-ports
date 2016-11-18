--- AtomicParsley.cpp.orig	2006-09-15 23:22:33 UTC
+++ AtomicParsley.cpp
@@ -1447,7 +1447,7 @@ void APar_Extract_uuid_binary_file(Atomi
 	uint32_t atom_offsets = 0;
 	char* uuid_outfile = (char*)calloc(1, sizeof(char)*MAXPATHLEN+1); //malloc a new string because it may be a cli arg for a specific output path	
 	if (output_path == NULL) {
-		char* orig_suffix = strrchr(originating_file, '.');
+		const char* orig_suffix = strrchr(originating_file, '.');
 		if (orig_suffix == NULL) {
 			fprintf(stdout, "AP warning: a file extension for the input file was not found.\n\tGlobbing onto original filename...\n");
 			path_len = strlen(originating_file);
@@ -4462,7 +4462,7 @@ void APar_TestTracksForKind() {
 #endif
 
 void APar_DeriveNewPath(const char *filePath, char* temp_path, int output_type, const char* file_kind, char* forced_suffix, bool random_filename = true) {
-	char* suffix = NULL;
+	const char* suffix = NULL;
 	if (forced_suffix == NULL) {
 		suffix = strrchr(filePath, '.');
 	} else {
@@ -4480,7 +4480,7 @@ void APar_DeriveNewPath(const char *file
 		memcpy(temp_path, filePath, base_len);
 		memcpy(temp_path + base_len, file_kind, strlen(file_kind));
 #else
-		char* file_name = strrchr(filePath, '/');
+		const char* file_name = strrchr(filePath, '/');
 		size_t file_name_len = strlen(file_name);
 		memcpy(temp_path, filePath, filepath_len-file_name_len+1);
 		memcpy(temp_path + strlen(temp_path), ".", 1);
@@ -5006,7 +5006,7 @@ void APar_WriteFile(const char* m4aFile,
 			free_modified_name = true;
 			if (forced_suffix_type == FORCE_M4B_TYPE) { //using --stik Audiobook with --overWrite will change the original file's extension
 				uint16_t filename_len = strlen(m4aFile);
-				char* suffix = strrchr(m4aFile, '.');
+				const char* suffix = strrchr(m4aFile, '.');
 				memcpy(originating_file, m4aFile, filename_len+1 );
 				memcpy(originating_file + (filename_len - strlen(suffix) ), ".m4b", 5 );
 			}
