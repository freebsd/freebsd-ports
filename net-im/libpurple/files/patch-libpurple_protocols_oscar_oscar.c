#
#
# patch "libpurple/protocols/oscar/oscar.c"
#  from [ec79d8d9fcba376be091b363977e8f23c748eff2]
#    to [c8cc188e64cc6b466711a5b56454ce70615b0eea]
#
============================================================
--- libpurple/protocols/oscar/oscar.c	ec79d8d9fcba376be091b363977e8f23c748eff2
+++ libpurple/protocols/oscar/oscar.c	c8cc188e64cc6b466711a5b56454ce70615b0eea
@@ -4787,7 +4761,8 @@ oscar_send_im(PurpleConnection *gc, cons
 			tmp2 = purple_markup_strip_html(tmp1);
 			is_html = FALSE;
 		} else {
-			tmp2 = g_strdup(tmp1);
+			/* ICQ 6 wants its HTML wrapped in these tags. Oblige it. */
+			tmp2 = g_strdup_printf("<HTML><BODY>%s</BODY></HTML>", tmp1);
 			is_html = TRUE;
 		}
 		g_free(tmp1);
