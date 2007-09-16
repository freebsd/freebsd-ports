--- src/wbc-gtk-edit.c.orig	2007-09-16 17:17:41.000000000 -0400
+++ src/wbc-gtk-edit.c	2007-09-16 17:18:37.000000000 -0400
@@ -887,8 +887,10 @@ wbcg_edit_start (WBCGtk *wbcg,
 				GOFormat *new_fmt;
 				int mbd;
 
+#ifndef WITH_GOFFICE_0_4
 				mbd = go_format_month_before_day (fmt);
 				if (mbd < 0)
+#endif
 					mbd = go_locale_month_before_day ();
 
 				fstr = g_string_new (mbd ? "m/d/yyyy" : "d/m/yyyy");
