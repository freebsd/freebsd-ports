--- a/eepg.c
+++ b/eepg.c
@@ -427,7 +427,14 @@ static void load_file (int tableid, char
 
     while (fgets (buf, sizeof (buf), fp) != NULL) {
       from = binary = to = NULL;
+#ifdef __FreeBSD__
+      from = MALLOC(char, 256);
+      binary = MALLOC(char, 1024);
+      to = MALLOC(char, 256);
+      int elems = sscanf (buf, "%255[^:]:%1023[^:]:%255[^:]:", from, binary, to);
+#else
       int elems = sscanf (buf, "%a[^:]:%a[^:]:%a[^:]:", &from, &binary, &to);
+#endif
       if (elems == 3) {
 	int bin_len = strlen (binary);
 	int from_char = resolve_char (from);
