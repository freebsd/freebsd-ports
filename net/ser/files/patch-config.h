
$FreeBSD$

--- config.h	2004/06/29 19:14:46	1.1
+++ config.h	2004/06/29 19:33:41
@@ -72,12 +72,14 @@
 #define CONTENT_LENGTH "Content-Length: "
 #define CONTENT_LENGTH_LEN (sizeof(CONTENT_LENGTH)-1)
 
-#define USER_AGENT "User-Agent: Sip EXpress router"\
+#define UA_NAME "Sip EXpress router "\
 		"(" VERSION " (" ARCH "/" OS"))"
+#define UA_NAME_LEN (sizeof(UA_NAME)-1)
+
+#define USER_AGENT "User-Agent: "
 #define USER_AGENT_LEN (sizeof(USER_AGENT)-1)
 
-#define SERVER_HDR "Server: Sip EXpress router "\
-		"(" VERSION " (" ARCH "/" OS"))"
+#define SERVER_HDR "Server: "
 #define SERVER_HDR_LEN (sizeof(SERVER_HDR)-1)
 
 #define MAX_WARNING_LEN  256
