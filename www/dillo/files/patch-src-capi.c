--- src/capi.c.orig	Fri Jan  7 19:35:29 2005
+++ src/capi.c	Fri Jan  7 19:37:29 2005
@@ -492,9 +492,9 @@
                a_Chain_bcb(OpStop, Info, conn->url, NULL);
 
             } else if (strcmp(Data2, "send_status_message") == 0) {
-               a_Interface_msg(conn->bw, Data1);
+               a_Interface_msg(conn->bw, "%s", Data1);
             } else if (strcmp(Data2, "chat") == 0) {
-               a_Interface_msg(conn->bw, Data1);
+               a_Interface_msg(conn->bw, "%s", Data1);
                a_Bookmarks_chat_add(NULL, NULL, Data1);
             } else if (strcmp(Data2, "dialog") == 0) {
                a_Dpiapi_dialog(conn->bw, conn->server, Data1);
