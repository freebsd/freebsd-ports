diff -urN src/redir.h src/redir.h
--- src/redir.h.orig	2008-06-28 17:38:35.000000000 +0100
+++ src/redir.h	2008-06-29 16:17:48.000000000 +0100
@@ -124,17 +124,18 @@
 		      struct redir_conn_t *conn);
 };
 
+struct redir_msg_data {
+  uint16_t opt;
+  struct in_addr addr;
+  struct redir_state redir;
+  struct session_params params;
+} __attribute__((packed));
+
 struct redir_msg_t {
   long mtype;
-  struct redir_msg_data {
-    uint16_t opt;
-    struct in_addr addr;
-    struct redir_state redir;
-    struct session_params params;
-  } mdata;
+  struct redir_msg_data mdata;
 };
 
-
 int redir_new(struct redir_t **redir, struct in_addr *addr, int port, int uiport);
 

