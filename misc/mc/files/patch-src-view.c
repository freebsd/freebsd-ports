--- src/view.c.orig	Fri Dec 27 12:48:33 2002
+++ src/view.c	Tue Jun 15 03:15:09 2004
@@ -74,6 +74,10 @@
 #   define IFAIX(x)
 #endif
 
+#if GLIB_MAJOR_VERSION < 2
+# define g_try_malloc g_malloc
+#endif
+
 #define vwidth (view->widget.cols - (view->have_frame ? 2 : 0))
 #define vheight (view->widget.lines - (view->have_frame ? 2 : 0))
 
@@ -308,7 +312,7 @@
 	    view->block_ptr = g_realloc (view->block_ptr,
 					 sizeof (block_ptr_t) * page);
 	    for (i = view->blocks; i < page; i++) {
-		char *p = g_malloc (VIEW_PAGE_SIZE);
+		char *p = g_try_malloc (VIEW_PAGE_SIZE);
 		view->block_ptr[i].data = p;
 		if (!p)
 		    return '\n';
@@ -336,7 +340,7 @@
 	    }
 	    view->blocks = page;
 	}
-	if (byte_index > view->bytes_read) {
+	if (byte_index >= view->bytes_read) {
 	    return -1;
 	} else
 	    return view->block_ptr[page - 1].data[offset];
@@ -573,9 +577,11 @@
 	return init_growing_view (view, 0, view->filename);
     }
 #ifdef HAVE_MMAP
-    view->data =
-	mc_mmap (0, view->s.st_size, PROT_READ, MAP_FILE | MAP_SHARED,
-		 view->file, 0);
+    if ((size_t) view->s.st_size == view->s.st_size)
+	view->data = mc_mmap (0, view->s.st_size, PROT_READ,
+			      MAP_FILE | MAP_SHARED, view->file, 0);
+    else
+	view->data = (caddr_t) -1;
     if ((caddr_t) view->data != (caddr_t) - 1) {
 	/* mmap worked */
 	view->first = 0;
@@ -589,7 +595,11 @@
      * file into memory (alex@bcs.zaporizhzhe.ua). Also, mmap can fail
      * for any reason, so we use this as fallback (pavel@ucw.cz) */
 
-    view->data = (unsigned char *) g_malloc (view->s.st_size);
+    if ((gulong) view->s.st_size == view->s.st_size)
+      view->data = (unsigned char *) g_try_malloc (view->s.st_size);
+    else
+      view->data = NULL;
+
     if (view->data == NULL
 	|| mc_lseek (view->file, 0, SEEK_SET) != 0
 	|| mc_read (view->file, view->data,
@@ -821,7 +831,7 @@
 	if (w > 46) {
 	    widget_move (view, view->have_frame, 24 + view->have_frame);
 	    if (view->hex_mode)
-		printw (_("Offset 0x%08x"), view->edit_cursor);
+		printw (_("Offset 0x%08lx"), view->edit_cursor);
 	    else
 		printw (_("Col %d"), -view->start_col);
 	}
@@ -1513,33 +1523,41 @@
     long i = 0;
     int prev = 0;
 
+    if (!pos && direction == -1)
+	return 0;
+
     /* skip over all the possible zeros in the file */
     while ((ch = get_byte (view, pos)) == 0) {
+	if (!pos && direction == -1)
+	    return 0;
 	pos += direction;
 	i++;
     }
     *skipped = i;
 
-    if (pos) {
-	prev = get_byte (view, pos - 1);
+    if (!i && (pos || direction == -1)) {
+	prev = get_byte (view, pos - direction);
 	if ((prev == -1) || (prev == '\n'))
 	    prev = 0;
     }
 
-    for (i = 0; ch != -1; ch = get_byte (view, pos)) {
+    for (i = 1; ch != -1; ch = get_byte (view, pos)) {
 
-	if (i == usable_size) {
+	if (i >= usable_size) {
 	    buffer = grow_string_buffer (buffer, &buffer_size);
 	    usable_size = buffer_size - 2;
 	}
 
+	buffer[i++] = ch;
+	if (!pos && direction == -1)
+	    break;
+
 	pos += direction;
-	i++;
 
 	if (ch == '\n' || !ch) {
+	    i--;
 	    break;
 	}
-	buffer[i] = ch;
     }
     if (buffer) {
 	buffer[0] = prev;
