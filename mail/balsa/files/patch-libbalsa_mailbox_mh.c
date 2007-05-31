--- libbalsa/mailbox_mh.c.orig	Wed May 16 13:49:05 2007
+++ libbalsa/mailbox_mh.c	Thu May 31 01:09:09 2007
@@ -27,6 +27,8 @@
 /* to compile this on BSD/Darwin */
 #undef _POSIX_SOURCE
 
+#include <sys/types.h>
+#include <sys/stat.h>
 #include <unistd.h>
 #include <fcntl.h>
 #include <errno.h>
@@ -45,7 +47,7 @@
 struct message_info {
     LibBalsaMailboxLocalMessageInfo local_info;
     LibBalsaMessageFlag orig_flags;     /* Has only real flags */
-    gint fileno;
+    gint mi_fileno;
 };
 
 #define REAL_FLAGS(flags) (flags & LIBBALSA_MESSAGE_FLAGS_REAL)
@@ -260,7 +262,7 @@ libbalsa_mailbox_mh_load_config(LibBalsa
 
 #define MH_BASENAME(msg_info) \
     g_strdup_printf((msg_info->orig_flags & LIBBALSA_MESSAGE_FLAG_DELETED) ? \
-		    ",%d" : "%d", msg_info->fileno)
+		    ",%d" : "%d", msg_info->mi_fileno)
 
 static GMimeStream *
 libbalsa_mailbox_mh_get_message_stream(LibBalsaMailbox * mailbox,
@@ -335,7 +337,7 @@ static gint
 lbm_mh_compare_fileno(const struct message_info ** a,
 		      const struct message_info ** b)
 {
-    return (*a)->fileno - (*b)->fileno;
+    return (*a)->mi_fileno - (*b)->mi_fileno;
 }
 
 static void
@@ -352,7 +354,7 @@ lbm_mh_parse_mailbox(LibBalsaMailboxMh *
 
     while ((filename = g_dir_read_name(dir)) != NULL) {
 	LibBalsaMessageFlag delete_flag = 0;
-	guint fileno;
+	guint mh_fileno;
 
 	if (filename[0] == ',') {
 	    filename++;
@@ -361,22 +363,22 @@ lbm_mh_parse_mailbox(LibBalsaMailboxMh *
 	if (lbm_mh_check_filename(filename) == FALSE)
 	    continue;
 
-	if (sscanf(filename, "%d", &fileno) != 1)
+	if (sscanf(filename, "%d", &mh_fileno) != 1)
             break;     /* FIXME report error? */
-	if (fileno > mh->last_fileno)
-	    mh->last_fileno = fileno;
+	if (mh_fileno > mh->last_fileno)
+	    mh->last_fileno = mh_fileno;
 
 	if (add_msg_info && mh->messages_info) {
 	    struct message_info *msg_info =
 		g_hash_table_lookup(mh->messages_info,
-				    GINT_TO_POINTER(fileno));
+				    GINT_TO_POINTER(mh_fileno));
 	    if (!msg_info) {
 		msg_info = g_new0(struct message_info, 1);
 		msg_info->local_info.flags = INVALID_FLAG;
 		g_hash_table_insert(mh->messages_info,
-				    GINT_TO_POINTER(fileno), msg_info);
+				    GINT_TO_POINTER(mh_fileno), msg_info);
 		g_ptr_array_add(mh->msgno_2_msg_info, msg_info);
-		msg_info->fileno = fileno;
+		msg_info->mi_fileno = mh_fileno;
 	    }
 	    msg_info->orig_flags = delete_flag;
 	}
@@ -394,17 +396,17 @@ static const gchar *LibBalsaMailboxMhRep
 static const gchar *LibBalsaMailboxMhRecent = "recent:";
 
 static void
-lbm_mh_set_flag(LibBalsaMailboxMh * mh, guint fileno, LibBalsaMessageFlag flag)
+lbm_mh_set_flag(LibBalsaMailboxMh * mh, guint mh_fileno, LibBalsaMessageFlag flag)
 {
     struct message_info *msg_info;
 
-    if (!fileno)
+    if (!mh_fileno)
 	return;
 
-    msg_info = g_hash_table_lookup(mh->messages_info, GINT_TO_POINTER(fileno));
+    msg_info = g_hash_table_lookup(mh->messages_info, GINT_TO_POINTER(mh_fileno));
 
     if (!msg_info) {
-	g_print("MH sequence info for nonexistent message %d\n", fileno);
+	g_print("MH sequence info for nonexistent message %d\n", mh_fileno);
 	return;
     }
 
@@ -433,7 +435,7 @@ lbm_mh_handle_seq_line(LibBalsaMailboxMh
 
     for (seq = sequences; *seq; seq++) {
 	guint end = 0;
-	guint fileno;
+	guint mh_fileno;
 
 	if (!**seq)
 	    continue;
@@ -444,11 +446,11 @@ lbm_mh_handle_seq_line(LibBalsaMailboxMh
 	    if (sscanf(line, "%d", &end) != 1)
                 break; /* FIXME report error? */
 	}
-	if (sscanf(*seq, "%d", &fileno) != 1)
+	if (sscanf(*seq, "%d", &mh_fileno) != 1)
             break;     /* FIXME report error? */
 	do
-	    lbm_mh_set_flag(mh, fileno, flag);
-	while (++fileno <= end);
+	    lbm_mh_set_flag(mh, mh_fileno, flag);
+	while (++mh_fileno <= end);
     }
 
     g_strfreev(sequences);
@@ -580,7 +582,7 @@ lbm_mh_check(LibBalsaMailboxMh * mh, con
 	    sequences = g_strsplit(p, " ", 0);
 	    for (seq = sequences; *seq; seq++) {
 		guint end = 0;
-		guint fileno;
+		guint mh_fileno;
 
 		if (!**seq)
 		    continue;
@@ -591,15 +593,15 @@ lbm_mh_check(LibBalsaMailboxMh * mh, con
 		    if (sscanf(p, "%d", &end) != 1)
                         break; /* FIXME report error? */
 		}
-		if (sscanf(*seq, "%d", &fileno) != 1)
+		if (sscanf(*seq, "%d", &mh_fileno) != 1)
                     break; /* FIXME report error? */
 		do {
-		    p = g_strdup_printf("%s/%d", path, fileno);
+		    p = g_strdup_printf("%s/%d", path, mh_fileno);
 		    if (access(p, F_OK) == 0)
 			retval = TRUE;
 		    g_free(p);
 		    /* One undeleted unread message is enough. */
-		} while (!retval && ++fileno <= end);
+		} while (!retval && ++mh_fileno <= end);
 	    }
 	    g_strfreev(sequences);
 	    break;
@@ -686,7 +688,7 @@ libbalsa_mailbox_mh_check(LibBalsaMailbo
 	else {
 	    g_ptr_array_remove(mh->msgno_2_msg_info, msg_info);
 	    g_hash_table_remove(mh->messages_info, 
-		    		GINT_TO_POINTER(msg_info->fileno));
+		    		GINT_TO_POINTER(msg_info->mi_fileno));
 	    libbalsa_mailbox_local_msgno_removed(mailbox, msgno);
 	    if (renumber > msgno)
 		/* First message that needs renumbering. */
@@ -763,11 +765,11 @@ lbm_mh_flag_line(struct message_info *ms
     if (!(msg_info->local_info.flags & flag))
 	return;
 
-    if (li->last < msg_info->fileno - 1) {
+    if (li->last < msg_info->mi_fileno - 1) {
 	lbm_mh_print_line(li);
-	li->first = msg_info->fileno;
+	li->first = msg_info->mi_fileno;
     }
-    li->last = msg_info->fileno;
+    li->last = msg_info->mi_fileno;
 }
 
 static gboolean
@@ -849,7 +851,7 @@ libbalsa_mailbox_mh_sync(LibBalsaMailbox
 	    /* free old information */
 	    g_ptr_array_remove(mh->msgno_2_msg_info, msg_info);
 	    g_hash_table_remove(mh->messages_info, 
-		    		GINT_TO_POINTER(msg_info->fileno));
+		    		GINT_TO_POINTER(msg_info->mi_fileno));
 	    libbalsa_mailbox_local_msgno_removed(mailbox, msgno);
 	} else {
 	    lbm_mh_flag_line(msg_info, LIBBALSA_MESSAGE_FLAG_NEW, &unseen);
@@ -1038,7 +1040,7 @@ libbalsa_mailbox_mh_fetch_message_struct
  * we'll just add new lines and let the next sync merge them with any
  * existing lines. */
 static void
-lbm_mh_update_sequences(LibBalsaMailboxMh * mh, gint fileno,
+lbm_mh_update_sequences(LibBalsaMailboxMh * mh, gint mh_fileno,
 			LibBalsaMessageFlag flags)
 {
     FILE *fp;
@@ -1049,13 +1051,13 @@ lbm_mh_update_sequences(LibBalsaMailboxM
 	return;
 
     if (flags & LIBBALSA_MESSAGE_FLAG_NEW)
-	fprintf(fp, "unseen: %d\n", fileno);
+	fprintf(fp, "unseen: %d\n", mh_fileno);
     if (flags & LIBBALSA_MESSAGE_FLAG_FLAGGED)
-	fprintf(fp, "flagged: %d\n", fileno);
+	fprintf(fp, "flagged: %d\n", mh_fileno);
     if (flags & LIBBALSA_MESSAGE_FLAG_REPLIED)
-	fprintf(fp, "replied: %d\n", fileno);
+	fprintf(fp, "replied: %d\n", mh_fileno);
     if (flags & LIBBALSA_MESSAGE_FLAG_RECENT)
-	fprintf(fp, "recent: %d\n", fileno);
+	fprintf(fp, "recent: %d\n", mh_fileno);
     fclose(fp);
 }
 
@@ -1072,7 +1074,7 @@ libbalsa_mailbox_mh_add_message(LibBalsa
     int fd;
     GMimeStream *out_stream;
     GMimeFilter *crlffilter;
-    int fileno;
+    int mh_fileno;
     int retries;
     GMimeStream *in_stream;
 
@@ -1115,14 +1117,14 @@ libbalsa_mailbox_mh_add_message(LibBalsa
     libbalsa_mime_stream_shared_unlock(stream);
     g_object_unref(in_stream);
 
-    fileno = mh->last_fileno; 
+    mh_fileno = mh->last_fileno; 
     retries = 10;
     do {
 	/* rename tempfile to message-number-name */
 	char *new_filename;
 	gint rename_status;
 
-	new_filename = g_strdup_printf("%s/%d", path, ++fileno);
+	new_filename = g_strdup_printf("%s/%d", path, ++mh_fileno);
 	rename_status = libbalsa_safe_rename(tmp, new_filename);
 	g_free(new_filename);
 	if (rename_status != -1)
@@ -1145,9 +1147,9 @@ libbalsa_mailbox_mh_add_message(LibBalsa
                     "Too high activity?");
 	return FALSE;
     }
-    mh->last_fileno = fileno;
+    mh->last_fileno = mh_fileno;
 
-    lbm_mh_update_sequences(mh, fileno,
+    lbm_mh_update_sequences(mh, mh_fileno,
                             flags | LIBBALSA_MESSAGE_FLAG_RECENT);
 
     return TRUE;
