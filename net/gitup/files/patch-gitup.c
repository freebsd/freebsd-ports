--- gitup.c.orig	2021-09-05 19:58:01.000000000 +0300
+++ gitup.c	2022-01-18 16:53:41.999972000 +0300
@@ -676,7 +676,8 @@ save_file(char *path, int mode, char *buffer, int buff
 		memcpy(temp_buffer, buffer, buffer_size);
 		temp_buffer[buffer_size] = '\0';
 
-		if (symlink(temp_buffer, path) == -1)
+		if (symlink(temp_buffer, path) == -1 &&
+		    (unlink(path), symlink(temp_buffer, path)) == -1)
 			err(EXIT_FAILURE,
 				"save_file: symlink failure %s -> %s",
 				path,
@@ -2800,7 +2801,9 @@ save_repairs(connector *session)
 					"save_repairs: cannot create %s",
 					found_file->path);
 		} else {
-			missing = !path_exists(found_file->path);
+			struct stat st;
+
+			missing = stat(found_file->path, &st) != 0;
 			update  = true;
 
 			/*
@@ -2813,7 +2816,7 @@ save_repairs(connector *session)
 
 				check_hash = calculate_file_hash(
 					found_file->path,
-					found_file->mode);
+					st.st_mode);
 
 				buffer_hash = calculate_object_hash(
 					found_object->buffer,
