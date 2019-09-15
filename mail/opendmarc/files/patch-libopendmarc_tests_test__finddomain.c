--- libopendmarc/tests/test_finddomain.c.orig	2012-10-25 15:38:55 UTC
+++ libopendmarc/tests/test_finddomain.c
@@ -23,6 +23,7 @@ main(int argc, char **argv)
 		/* 11 */ {"(,) joe@joe.com", "joe.com"},
 		/* 12 */ {"\"( bob@bob.com)\" joe@joe.com", "joe.com"},
 		/* 12 */ {"From: Davide D'Marco <user@blah.com>", "blah.com"},
+		/* 13 */ {"blah.com>", "blah.com"},
 			 {NULL, NULL},
 	};
 	u_char dbuf[256];
