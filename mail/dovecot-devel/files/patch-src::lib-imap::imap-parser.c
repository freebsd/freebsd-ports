--- src/lib-imap/imap-parser.c.orig	Wed Mar 12 06:05:57 2003
+++ src/lib-imap/imap-parser.c	Sun Apr 20 02:32:45 2003
@@ -451,7 +451,6 @@
 			imap_parser_save_arg(parser, data,
 					     (size_t)parser->literal_size);
 			parser->cur_pos = (size_t)parser->literal_size;
-			parser->eol = TRUE;
 			return TRUE;
 		}
 	} else {
@@ -560,8 +559,8 @@
 {
 	parser->flags = flags;
 
-	while (count == 0 || parser->root_list->size < count ||
-	       IS_UNFINISHED(parser)) {
+	while (!parser->eol && (count == 0 || parser->root_list->size < count ||
+				IS_UNFINISHED(parser))) {
 		if (!imap_parser_read_arg(parser))
 			break;
 
@@ -580,7 +579,7 @@
 	} else if ((!IS_UNFINISHED(parser) && count > 0 &&
 		    parser->root_list->size >= count) || parser->eol) {
 		/* all arguments read / end of line. */
-		i_stream_skip(parser->input, parser->cur_pos);
+ 		i_stream_skip(parser->input, parser->cur_pos);
 		parser->cur_pos = 0;
 
 		if (parser->list_arg != NULL) {
