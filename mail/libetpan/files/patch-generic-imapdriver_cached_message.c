--- generic/imapdriver_cached_message.c.orig	Fri Aug  6 18:17:41 2004
+++ generic/imapdriver_cached_message.c	Fri Aug  6 18:18:39 2004
@@ -213,6 +213,7 @@
  free_section:
   mailmime_section_free(part);
  err:
+  return;
 }
 
 static void generate_key_from_section(char * key, size_t size,
