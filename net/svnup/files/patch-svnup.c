--- svnup.c.orig
+++ svnup.c
@@ -51,7 +51,7 @@
 #include <unistd.h>
 
 
-#define SVNUP_VERSION "1.07"
+#define SVNUP_VERSION "1.07a"
 #define BUFFER_UNIT 4096
 #define COMMAND_BUFFER 32768
 #define COMMAND_BUFFER_THRESHOLD 32000
@@ -1539,7 +1539,6 @@
 process_report_http(connector *connection, file_node ***file, int *file_count, int *file_max)
 {
 	file_node   *this_file;
-	struct stat  local;
 	int          revision_length, x;
 	char         command[COMMAND_BUFFER + 1], *d, *end, *href, *md5, *path;
 	char        *start, *temp, temp_buffer[BUFFER_UNIT], *value;
@@ -1562,17 +1561,17 @@
 		"DAV: http://subversion.tigris.org/xmlns/dav/svn/log-revprops\r\n"
 		"Transfer-Encoding: chunked\r\n\r\n"
 		"%lx\r\n"
-		"<S:update-report xmlns:S=\"svn:\">\n"
-		"<S:src-path>/%s</S:src-path>\n"
-		"<S:target-revision>%d</S:target-revision>\n"
-		"<S:depth>unknown</S:depth>\n"
-		"<S:entry rev=\"%d\" depth=\"infinity\" start-empty=\"true\"></S:entry>\n"
-		"</S:update-report>\n"
+		"<S:update-report xmlns:S=\"svn:\">"
+		"<S:src-path>/%s</S:src-path>"
+		"<S:target-revision>%d</S:target-revision>"
+		"<S:depth>unknown</S:depth>"
+		"<S:entry rev=\"%d\" depth=\"infinity\" start-empty=\"true\"></S:entry>"
+		"</S:update-report>\r\n"
 		"\r\n0\r\n\r\n",
 		connection->root,
 		connection->address,
 		SVNUP_VERSION,
-		strlen(connection->branch) + revision_length + revision_length + strlen(SVNUP_VERSION) + 206,
+		strlen(connection->branch) + revision_length + revision_length + 205,
 		connection->branch,
 		connection->revision,
 		connection->revision);
@@ -2389,9 +2388,9 @@
 
 				snprintf(temp_buffer,
 					BUFFER_UNIT,
-					"PROPFIND %s HTTP/1.1\n"
-					"Depth: 1\n"
-					"Host: %s\n\n",
+					"PROPFIND %s HTTP/1.1\r\n"
+					"Depth: 1\r\n"
+					"Host: %s\r\n\r\n",
 					file[f]->href,
 					connection.address);
 			} else temp_buffer[0] = '\0';
@@ -2471,9 +2470,9 @@
 				if (connection.protocol >= HTTP)
 					snprintf(temp_buffer,
 						BUFFER_UNIT,
-						"GET %s HTTP/1.1\n"
-						"Host: %s\n"
-						"Connection: Keep-Alive\n\n",
+						"GET %s HTTP/1.1\r\n"
+						"Host: %s\r\n"
+						"Connection: Keep-Alive\r\n\r\n",
 						file[f]->href,
 						connection.address);
 
