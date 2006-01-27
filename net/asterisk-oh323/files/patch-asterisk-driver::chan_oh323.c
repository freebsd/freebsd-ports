
$FreeBSD$

--- asterisk-driver/chan_oh323.c.orig	Tue Sep 20 13:50:34 2005
+++ asterisk-driver/chan_oh323.c	Wed Jan 25 17:59:14 2006
@@ -43,10 +43,12 @@
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <math.h>
+#include <netinet/in_systm.h>
 #include <netinet/ip.h>
 #include <sys/signal.h>
+#include <stdio.h>
 
-#include "asterisk.h"
+/* #include "asterisk.h" */
 
 #include "asterisk/lock.h"
 #include "asterisk/channel.h"
@@ -943,7 +945,7 @@ static int get_num(num_str_t tab[], char
 
 /******************************************************************************/
 
-static struct ast_channel *oh323_request(const char *type, int format, void *data, int *cause);
+static struct ast_channel *oh323_request(const char *type, const struct ast_codec_pref *formats, void *data, int *cause);
 static int oh323_text(struct ast_channel *c, const char *text);
 static int oh323_call(struct ast_channel *c, char *dest, int timeout);
 static int oh323_hangup(struct ast_channel *c);
@@ -2402,11 +2404,11 @@ static int oh323_write(struct ast_channe
 	}
 
 	/* Check for format changes */
-	if (f->subclass != i->owner->nativeformats) {
+	if (!f->subclass & i->owner->nativeformats.bits) {
 		ast_log(LOG_NOTICE, "%s: Format changed to %s (native %s).\n", 
 						c->name, 
 						ast_getformatname(f->subclass),
-						ast_getformatname(c->nativeformats));
+						ast_getformatname(c->nativeformats.bits));
 		if (ast_set_write_format(c, f->subclass) < 0) {
 			ast_mutex_unlock(&oh323_tab_lock);
 			return(-1);
@@ -2802,8 +2804,8 @@ static struct ast_channel *ast_oh323_new
 
 	/* Set our native format */
 	/* XXX: Only one should be selected */
-	tmp->nativeformats = oh323_capability;
-	fmt = oh323_codec_choose(tmp->nativeformats);
+	ast_codec_pref_append_missing2(&tmp->nativeformats, oh323_capability);
+	fmt = oh323_codec_choose(tmp->nativeformats.bits);
 	/*fmt = ast_best_codec(tmp->nativeformats);*/
 
 	tmp->writeformat = fmt;
@@ -2927,23 +2929,15 @@ static struct ast_channel *ast_oh323_new
  * This function limits the number of outbound H.323 calls.
  * Return NULL on error, the pointer to the channel on success.
  */
-static struct ast_channel *oh323_request(const char *type, int format, void *data, int *cause)
+static struct ast_channel *oh323_request(const char *type, const struct ast_codec_pref *formats, void *data, int *cause)
 {
-	int i=0, count, simcount, oldformat;
+	int i=0, count, simcount;
 	struct ast_channel *c;
 	char *dest = data;
 
 	if (option_debug)
 		ast_log(LOG_DEBUG, "In oh323_request: type=%s, format=%d, data=%s.\n", 
-						type, format, (char *)data);
-
-	/* Check the format requested */
-	oldformat = format;
-	format &= oh323_full_capability;
-	if (!format) {
-		ast_log(LOG_ERROR, "Asked to get a channel of unsupported format '%d'\n", format);
-		return NULL;
-	}
+						type, formats->bits, (char *)data);
 
 	ast_mutex_lock(&oh323_tab_lock);
 
@@ -3003,12 +2997,12 @@ static struct ast_channel *oh323_request
 	oh323_tab[i]->owner = c;
 
 	/* Specify our native formats */
-	c->nativeformats = format;
-	c->rawwriteformat = format;
-	c->rawreadformat = format;
+	memcpy(&c->nativeformats, formats, sizeof(struct ast_codec_pref));
+	c->rawwriteformat = formats->bits;
+	c->rawreadformat = formats->bits;
 	if (option_debug)
 		ast_log(LOG_DEBUG, "%s: Native format changed to %s.\n", 
-									c->name, ast_getformatname(format));
+									c->name, ast_getformatname(formats->bits));
 
 	ast_mutex_unlock(&oh323_tab_lock);
 	return c;
@@ -3439,7 +3433,8 @@ char *setup_h323_connection(call_details
 				ast_log(LOG_DEBUG, "Setting channel '%s' native format to %s!\n", 
 								oh323_tab[i]->owner->name,
 								ast_getformatname(oh323_tab[i]->capability));
-			oh323_tab[i]->owner->nativeformats = oh323_tab[i]->capability;
+			ast_codec_pref_init(&oh323_tab[i]->owner->nativeformats);
+			ast_codec_pref_append_missing2(&oh323_tab[i]->owner->nativeformats, oh323_tab[i]->capability);
 		}
 
 		/* Set environment variables */
@@ -3512,7 +3507,8 @@ char *setup_h323_connection(call_details
 				ast_log(LOG_DEBUG, "Setting channel '%s' native format to %s!\n", 
 								oh323_tab[i]->owner->name,
 								ast_getformatname(oh323_tab[i]->capability));
-			oh323_tab[i]->owner->nativeformats = oh323_tab[i]->capability;
+			ast_codec_pref_init(&oh323_tab[i]->owner->nativeformats);
+			ast_codec_pref_append_missing2(&oh323_tab[i]->owner->nativeformats, oh323_tab[i]->capability);
 			if (oh323_tab[i]->tx_smooth) {
 				ast_smoother_free(oh323_tab[i]->tx_smooth);
 				oh323_tab[i]->tx_smooth = NULL;
@@ -4429,7 +4425,7 @@ static int kill_monitor(void)
 				return(-1);
 			}
 		}
-		monitor_thread = -2;
+		monitor_thread = AST_PTHREADT_STOP;
 	} else {
 		ast_log(LOG_WARNING, "Unable to lock the monitor.\n");
 		return(-1);
