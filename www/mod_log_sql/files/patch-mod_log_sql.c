--- mod_log_sql.c.orig	Wed Aug  6 18:46:10 2003
+++ mod_log_sql.c	Wed Aug  6 18:49:22 2003
@@ -225,6 +225,11 @@
 	return r->args;
 }
 
+static const char *extract_content_type(request_rec *r, char *a)
+{
+	return r->content_type;
+}
+
 static const char *extract_status(request_rec *r, char *a)
 {
 	return pfmt(r->pool, r->status);
@@ -538,6 +543,7 @@
 	{   'a', extract_request_args,      "request_args",     1, 1    },
 	{   'b', extract_bytes_sent,        "bytes_sent",       0, 0    },
     {   'c', extract_cookie,            "cookie",           0, 1    },
+	{   'C', extract_content_type,      "content_type",  0, 1        },
     {   'e', extract_env_var,           "env_var",          0, 1    },
     {   'f', extract_request_file,      "request_file",     0, 1    },
 	{   'H', extract_request_protocol,  "request_protocol", 0, 1    },
@@ -833,8 +839,9 @@
        request_method varchar(10),\
        request_protocol varchar(10),\
        request_time char(28),\
-       request_uri varchar(50),\
+       request_uri varchar(255),\
 	   request_args varchar(255),\
+       content_type varchar(64),\
        server_port smallint unsigned,\
        ssl_cipher varchar(25),\
        ssl_keysize smallint unsigned,\
