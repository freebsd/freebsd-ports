--- options-table.c.orig	2016-03-29 03:30:07 UTC
+++ options-table.c
@@ -925,15 +925,34 @@ const struct options_table_entry options_table[] = {
 	{ .name = "tmate-server-rsa-fingerprint",
 	  .type = OPTIONS_TABLE_STRING,
 	  .scope = OPTIONS_TABLE_SERVER,
-	  .default_str = "af:2d:81:c1:fe:49:70:2d:7f:09:a9:d7:4b:32:e3:be"
+	  .default_str = "00:00:00:00:00:00:00:00:00:00:00:00:00:00:00:00"
 	},
 
 	{ .name = "tmate-server-ecdsa-fingerprint",
 	  .type = OPTIONS_TABLE_STRING,
 	  .scope = OPTIONS_TABLE_SERVER,
-	  .default_str = "c7:a1:51:36:d2:bb:35:4b:0a:1a:c0:43:97:74:ea:42"
+	  .default_str = "00:00:00:00:00:00:00:00:00:00:00:00:00:00:00:00"
 	},
-
+	{ .name = "tmate-server-dss-fingerprint",
+	  .type = OPTIONS_TABLE_STRING,
+	  .scope = OPTIONS_TABLE_SERVER,
+	  .default_str = "00:00:00:00:00:00:00:00:00:00:00:00:00:00:00:00"
+	},
+	{ .name = "tmate-server-ed25519-fingerprint",
+	  .type = OPTIONS_TABLE_STRING,
+	  .scope = OPTIONS_TABLE_SERVER,
+	  .default_str = "00:00:00:00:00:00:00:00:00:00:00:00:00:00:00:00"
+	},
+	{ .name = "tmate-server-dss-cert01-fingerprint",
+	  .type = OPTIONS_TABLE_STRING,
+	  .scope = OPTIONS_TABLE_SERVER,
+	  .default_str = "00:00:00:00:00:00:00:00:00:00:00:00:00:00:00:00"
+	},
+	{ .name = "tmate-server-rsa-cert01-fingerprint",
+	  .type = OPTIONS_TABLE_STRING,
+	  .scope = OPTIONS_TABLE_SERVER,
+	  .default_str = "00:00:00:00:00:00:00:00:00:00:00:00:00:00:00:00"
+	},
 	{ .name = "tmate-display-time",
 	  .type = OPTIONS_TABLE_NUMBER,
 	  .scope = OPTIONS_TABLE_SESSION,
