--- update-mime-database.c.orig	Mon Oct 13 05:43:38 2003
+++ update-mime-database.c	Sat Dec  4 15:52:53 2004
@@ -377,7 +377,8 @@
 		}
 	}
 
-	xmlFree(lang);
+	if (lang)
+	  xmlFree(lang);
 }
 
 /* 'node' is a <mime-type> node from a source file, whose type is 'type'.
@@ -809,7 +810,13 @@
 	unsigned long value;
 	int b;
 
-	value = strtol(in, &end, 0);
+	value = strtoul(in, &end, 0);
+	if (errno == ERANGE) {
+		g_set_error(error, MIME_ERROR, 0,
+			"Number out-of-range (%s should fit in %d bytes)",
+			in, bytes);
+		return;
+	}
 	if (*end != '\0')
 	{
 		g_set_error(error, MIME_ERROR, 0, "Value is not a number");
@@ -834,9 +841,16 @@
 	if (in_mask)
 	{
 		int b;
-		long mask;
-		
-		mask = strtol(in_mask, &end, 0);
+		unsigned long mask;
+
+		mask = strtoul(in_mask, &end, 0);
+		if (errno == ERANGE) {
+			g_set_error(error, MIME_ERROR, 0,
+				"Mask out-of-range (%s should fit in %d bytes)",
+				in_mask, bytes);
+			return;
+		}
+
 		if (*end != '\0')
 		{
 			g_set_error(error, MIME_ERROR, 0,
@@ -847,7 +861,7 @@
 		out_mask = g_new(char, bytes);
 		for (b = 0; b < bytes; b++)
 		{
-			int shift = (bytes - b - 1) * 8;
+			int shift = (big_endian ? (bytes - b - 1) : b) * 8;
 			out_mask[b] = (mask >> shift) & 0xff;
 		}
 	}
@@ -991,11 +1005,32 @@
 	}
 
 	match->range_start = strtol(offset, &end, 10);
+	if (errno == ERANGE) {
+		char *number;
+		number = g_strndup(offset, end-offset);
+		g_set_error(error, MIME_ERROR, 0,
+			"Number out-of-range (%s should fit in 4 bytes)",
+			number);
+		g_free(number);
+		return;
+	}
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
+				"Number out-of-range (%s should fit in 8 bytes)",
+				number);
+			g_free(number);
+			return;
+		}
 
-		last = strtol(end + 1, &end, 10);
 		if (*end == '\0' && last >= match->range_start)
 			match->range_length = last - match->range_start + 1;
 		else
@@ -1330,7 +1365,7 @@
 
 	env = getenv("XDG_DATA_DIRS");
 	if (!env)
-		env = "/usr/local/share/:/usr/share/";
+		env = "%%X11BASE%%/share/gnome/:/usr/local/share/gnome/:%%X11BASE%%/share/:/usr/local/share/:/usr/share/";
 	dirs = g_strsplit(env, ":", 0);
 	g_return_if_fail(dirs != NULL);
 	for (n = 0; dirs[n]; n++)
