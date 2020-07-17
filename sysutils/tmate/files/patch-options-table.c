--- options-table.c.orig	2020-07-17 03:22:27 UTC
+++ options-table.c
@@ -925,19 +925,19 @@ const struct options_table_entry options_table[] = {
 	{ .name = "tmate-server-rsa-fingerprint",
 	  .type = OPTIONS_TABLE_STRING,
 	  .scope = OPTIONS_TABLE_SERVER,
-	  .default_str = "SHA256:Hthk2T/M/Ivqfk1YYUn5ijC2Att3+UPzD7Rn72P5VWs"
+	  .default_str = "SHA256:0000000000000000000000000000000000000000000"
 	},
 
 	{ .name = "tmate-server-ecdsa-fingerprint",
 	  .type = OPTIONS_TABLE_STRING,
 	  .scope = OPTIONS_TABLE_SERVER,
-	  .default_str = "SHA256:8GmKHYHEJ6n0TEdciHeEGkKOigQfCFuBULdt6vZIhDc"
+	  .default_str = "SHA256:0000000000000000000000000000000000000000000"
 	},
 
 	{ .name = "tmate-server-ed25519-fingerprint",
 	  .type = OPTIONS_TABLE_STRING,
 	  .scope = OPTIONS_TABLE_SERVER,
-	  .default_str = "SHA256:jfttvoypkHiQYUqUCwKeqd9d1fJj/ZiQlFOHVl6E9sI"
+	  .default_str = "SHA256:0000000000000000000000000000000000000000000"
 	},
 
 	{ .name = "tmate-display-time",
