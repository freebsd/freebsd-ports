--- scan.h.orig	2000-05-25 05:11:42 UTC
+++ scan.h
@@ -64,36 +64,36 @@ struct scontext {
 
 /* the current values */
 
-long* s_ent_sort;		/* sorted list of entries in the context */
-long s_ent_sort_max;		/* maximum index of sorted array */
-long s_ent_sorted_max;		/* maximum index *that is sorted* */
-long* s_ent_index;		/* indexes into ent_sorted */
-long s_ent_index_max;		/* maximum entry number added */
+EXT long* s_ent_sort;		/* sorted list of entries in the context */
+EXT long s_ent_sort_max;	/* maximum index of sorted array */
+EXT long s_ent_sorted_max;	/* maximum index *that is sorted* */
+EXT long* s_ent_index;		/* indexes into ent_sorted */
+EXT long s_ent_index_max;	/* maximum entry number added */
 
-int s_page_size;		/* number of entries allocated for page */
+EXT int s_page_size;		/* number of entries allocated for page */
 				/* (usually fixed, > max screen lines) */
-PAGE_ENT* page_ents;		/* array of entries on page */
+EXT PAGE_ENT* page_ents;	/* array of entries on page */
 /* -1 means not initialized for top and bottom entry */
-long s_top_ent;		/* top entry on page */
-long s_bot_ent;		/* bottom entry (note change) */
-bool s_refill;			/* does the page need refilling? */
+EXT long s_top_ent;		/* top entry on page */
+EXT long s_bot_ent;		/* bottom entry (note change) */
+EXT bool s_refill;		/* does the page need refilling? */
 /* refresh entries */
-bool s_ref_all;		/* refresh all on page */
-bool s_ref_top;		/* top status bar */
-bool s_ref_bot;		/* bottom status bar */
+EXT bool s_ref_all;		/* refresh all on page */
+EXT bool s_ref_top;		/* top status bar */
+EXT bool s_ref_bot;		/* bottom status bar */
 /* -1 for the next two entries means don't refresh */
-short s_ref_status;		/* line to start refreshing status from */
-short s_ref_desc;		/* line to start refreshing descript. from */
+EXT short s_ref_status;		/* line to start refreshing status from */
+EXT short s_ref_desc;		/* line to start refreshing descript. from */
 /* screen sizes */
-short s_top_lines;		/* lines for top status bar */
-short s_bot_lines;		/* lines for bottom status bar */
-short s_status_cols;		/* characters for status column */
-short s_cursor_cols;		/* characters for cursor column */
-short s_itemnum_cols;		/* characters for item number column */
-short s_desc_cols;		/* characters for description column */
+EXT short s_top_lines;		/* lines for top status bar */
+EXT short s_bot_lines;		/* lines for bottom status bar */
+EXT short s_status_cols;	/* characters for status column */
+EXT short s_cursor_cols;	/* characters for cursor column */
+EXT short s_itemnum_cols;	/* characters for item number column */
+EXT short s_desc_cols;		/* characters for description column */
 /* pointer info */
-short s_ptr_page_line;		/* page_ent index */
-long  s_flags;			/* misc. flags */
+EXT short s_ptr_page_line;	/* page_ent index */
+EXT long  s_flags;		/* misc. flags */
 
 EXT int s_num_contexts INIT(0);
 /* array of context structures */
@@ -102,7 +102,7 @@ EXT SCONTEXT* s_contexts INIT((SCONTEXT*)NULL);
 /* current context number */
 EXT int s_cur_context INIT(0);
 /* current context type (for fast switching) */
-int s_cur_type;
+EXT int s_cur_type;
 
 /* options */
 /* show item numbers by default */
