--- src/call_script.cpp	Wed Jul 12 13:20:34 2006
+++ src/call_script.cpp	Wed Jul 12 13:23:34 2006
@@ -46,6 +46,8 @@
 #define SCR_TRIGGER_LOCAL_RELEASE	"local_release"
 #define SCR_TRIGGER_REMOTE_RELEASE	"remote_release"
 
+extern char **environ;
+
 /////////////////////////
 // class t_script_result
 /////////////////////////
@@ -324,14 +326,16 @@
 		}
 		
 		char *line_buf = NULL;
-		size_t line_buf_len = 0;
-		ssize_t num_read;
+		char *num_read;
+		int line_buf_len;
+		int count=0;
 		
 		// Read and parse script results.
-		while ((num_read = getline(&line_buf, &line_buf_len, fp_result)) != -1) {
+		while ((num_read = fgets(line_buf, sizeof(line_buf), fp_result)) != NULL) {
+			count++;
 			// Strip newline if present
-			if (line_buf[num_read - 1] == '\n') {
-				line_buf[num_read - 1] = 0;
+			if (line_buf[count - 1] == '\n') {
+				line_buf[count - 1] = 0;
 			}
 
 			// Convert the read line to a C++ string
