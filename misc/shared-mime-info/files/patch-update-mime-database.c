--- update-mime-database.c.orig	Sat Mar 19 15:29:41 2005
+++ update-mime-database.c	Sat Mar 19 15:29:45 2005
@@ -94,6 +94,12 @@ static GHashTable *globs_hash = NULL;
 /* 'magic' nodes */
 static GPtrArray *magic_array = NULL;
 
+/* Maps MIME type names to superclass names */
+static GHashTable *subclass_hash = NULL;
+
+/* Maps aliases to Types */
+static GHashTable *alias_hash = NULL;
+
 /* Static prototypes */
 static Magic *magic_new(xmlNode *node, Type *type, GError **error);
 
@@ -295,12 +301,37 @@ static gboolean process_freedesktop_node
 	{
 		char *other_type;
 		gboolean valid;
+		GSList *list, *nlist;
+
 		other_type = xmlGetNsProp(field, "type", NULL);
 		valid = other_type && strchr(other_type, '/');
-		xmlFree(other_type);
 		if (valid)
-			return FALSE;	/* Copy through */
+		{
+			char *typename;
 
+			typename = g_strdup_printf("%s/%s", 
+						   type->media,
+						   type->subtype);
+			
+			if (strcmp(field->name, "alias") == 0)
+				g_hash_table_insert(alias_hash,
+						    g_strdup(other_type), type);
+				
+			else
+			{
+				list = g_hash_table_lookup(subclass_hash, typename);
+				nlist = g_slist_append (list, g_strdup(other_type));
+				if (list == NULL)
+					g_hash_table_insert(subclass_hash, 
+							    g_strdup(typename), nlist);    
+			}
+			g_free(typename);
+			xmlFree(other_type);
+			
+			return FALSE;	/* Copy through */
+		}
+		
+		xmlFree(other_type);
 		g_set_error(error, MIME_ERROR, 0,
 			_("Incorrect or missing 'type' attribute "
 			  "in <%s>"), field->name);
@@ -377,7 +408,8 @@ static void remove_old(Type *type, xmlNo
 		}
 	}
 
-	xmlFree(lang);
+	if (lang)
+	  xmlFree(lang);
 }
 
 /* 'node' is a <mime-type> node from a source file, whose type is 'type'.
@@ -809,7 +841,14 @@ static void parse_int_value(int bytes, c
 	unsigned long value;
 	int b;
 
-	value = strtol(in, &end, 0);
+	value = strtoul(in, &end, 0);
+	if (errno == ERANGE) {
+		g_set_error(error, MIME_ERROR, 0,
+			    "Number out-of-range (%s should fit in %d bytes)",
+			    in, bytes);
+		return;
+	}
+
 	if (*end != '\0')
 	{
 		g_set_error(error, MIME_ERROR, 0, "Value is not a number");
@@ -834,9 +873,17 @@ static void parse_int_value(int bytes, c
 	if (in_mask)
 	{
 		int b;
-		long mask;
+		unsigned long mask;
 		
-		mask = strtol(in_mask, &end, 0);
+		mask = strtoul(in_mask, &end, 0);
+		if (errno == ERANGE) {
+			g_set_error(error, MIME_ERROR, 0,
+				    "Mask out-of-range (%s should fit in %d bytes)",
+				    in_mask, bytes);
+			return;
+		}
+
+
 		if (*end != '\0')
 		{
 			g_set_error(error, MIME_ERROR, 0,
@@ -847,7 +894,7 @@ static void parse_int_value(int bytes, c
 		out_mask = g_new(char, bytes);
 		for (b = 0; b < bytes; b++)
 		{
-			int shift = (bytes - b - 1) * 8;
+			int shift = (big_endian ? (bytes - b - 1) : b) * 8;
 			out_mask[b] = (mask >> shift) & 0xff;
 		}
 	}
@@ -991,11 +1038,33 @@ static void match_offset(Match *match, x
 	}
 
 	match->range_start = strtol(offset, &end, 10);
+	if (errno == ERANGE) {
+		char *number;
+		number = g_strndup(offset, end-offset);
+		g_set_error(error, MIME_ERROR, 0,
+			    "Number out-of-range (%s should fit in 4 bytes)",
+			    number);
+		g_free(number);
+		return;
+	}
+
 	if (*end == ':' && end[1] && match->range_start >= 0)
 	{
 		int last;
+		char *begin;
+
+		begin = end + 1;
+		last = strtol(begin, &end, 10);
+		if (errno == ERANGE) {
+			char *number;
+			number = g_strndup(begin, end-begin);
+			g_set_error(error, MIME_ERROR, 0,
+				    "Number out-of-range (%s should fit in 8 bytes)",
+				    number);
+			g_free(number);
+			return;
+		}
 
-		last = strtol(end + 1, &end, 10);
 		if (*end == '\0' && last >= match->range_start)
 			match->range_length = last - match->range_start + 1;
 		else
@@ -1310,6 +1379,66 @@ static void write_namespaces(FILE *strea
 	g_ptr_array_free(lines, TRUE);
 }
 
+static void write_subclass(gpointer key, gpointer value, gpointer data)
+{
+	GSList *list = value;
+	FILE *stream = data;
+	GSList *l;
+	char *line;
+
+	for (l = list; l; l = l->next)
+	{
+		line = g_strconcat (key, " ", l->data, "\n", NULL);
+		fwrite(line, 1, strlen(line), stream);
+		g_free (line);
+	}
+}
+
+/* Write all the collected subclass information to 'subclasses' */
+static void write_subclasses(FILE *stream)
+{
+	g_hash_table_foreach(subclass_hash, write_subclass, stream);
+}
+
+/* Extract one entry from alias_hash and put it in the GPtrArray so
+ * we can sort it.
+ */
+static void add_alias(gpointer key, gpointer value, gpointer data)
+{
+	GPtrArray *lines = (GPtrArray *) data;
+	const guchar *alias = (guchar *) key;
+	Type *type = (Type *) value;
+	
+	g_ptr_array_add(lines, g_strconcat(alias, " ", type->media,
+					   "/", type->subtype, "\n", 
+					   NULL));
+}
+
+/* Write all the collected aliases */
+static void write_aliases(FILE *stream)
+{
+	GPtrArray *lines;
+	int i;
+	
+	lines = g_ptr_array_new();
+
+	g_hash_table_foreach(alias_hash, add_alias, lines);
+
+	g_ptr_array_sort(lines, strcmp2);
+
+	for (i = 0; i < lines->len; i++)
+	{
+		char *line = (char *) lines->pdata[i];
+
+		fwrite(line, 1, strlen(line), stream);
+
+		g_free(line);
+	}
+
+	g_ptr_array_free(lines, TRUE);
+}
+
+
 /* Issue a warning if 'path' won't be found by applications */
 static void check_in_path_xdg_data(const char *mime_path)
 {
@@ -1330,7 +1459,7 @@ static void check_in_path_xdg_data(const
 
 	env = getenv("XDG_DATA_DIRS");
 	if (!env)
-		env = "/usr/local/share/:/usr/share/";
+		env = "%%X11BASE%%/share/gnome/:/usr/local/share/gnome/:%%X11BASE%%/share/:/usr/local/share/:/usr/share/";
 	dirs = g_strsplit(env, ":", 0);
 	g_return_if_fail(dirs != NULL);
 	for (n = 0; dirs[n]; n++)
@@ -1371,6 +1500,14 @@ out:
 	g_free(path);
 }
 
+static void free_string_list(gpointer data)
+{
+  GSList *list = data;
+
+  g_slist_foreach(list, (GFunc)g_free, NULL);
+  g_slist_free(list);
+}
+
 int main(int argc, char **argv)
 {
 	char *mime_dir = NULL;
@@ -1442,7 +1579,11 @@ int main(int argc, char **argv)
 	namespace_hash = g_hash_table_new_full(g_str_hash, g_str_equal,
 					g_free, NULL);
 	magic_array = g_ptr_array_new();
-
+	subclass_hash = g_hash_table_new_full(g_str_hash, g_str_equal,
+					      g_free, free_string_list);
+	alias_hash = g_hash_table_new_full(g_str_hash, g_str_equal,
+					   g_free, NULL);
+	
 	scan_source_dir(package_dir);
 	g_free(package_dir);
 
@@ -1494,7 +1635,7 @@ int main(int argc, char **argv)
 		atomic_update(magic_path);
 		g_free(magic_path);
 	}
-	
+
 	{
 		FILE *stream;
 		char *ns_path;
@@ -1510,12 +1651,47 @@ int main(int argc, char **argv)
 		atomic_update(ns_path);
 		g_free(ns_path);
 	}
+	
+	{
+		FILE *stream;
+		char *path;
+		
+		path = g_strconcat(mime_dir, "/subclasses.new", NULL);
+		stream = fopen(path, "wb");
+		if (!stream)
+			g_error("Failed to open '%s' for writing\n",
+				path);
+		
+		write_subclasses(stream);
+
+		atomic_update(path);
+		g_free(path);
+	}
+
+	{
+		FILE *stream;
+		char *path;
+		
+		path = g_strconcat(mime_dir, "/aliases.new", NULL);
+		stream = fopen(path, "wb");
+		if (!stream)
+			g_error("Failed to open '%s' for writing\n",
+				path);
+		
+		write_aliases(stream);
+
+		atomic_update(path);
+		g_free(path);
+	}
+
 
 	g_ptr_array_free(magic_array, TRUE);
 
 	g_hash_table_destroy(types);
 	g_hash_table_destroy(globs_hash);
 	g_hash_table_destroy(namespace_hash);
+	g_hash_table_destroy(subclass_hash);
+	g_hash_table_destroy(alias_hash);
 
 	g_print("***\n");
 
