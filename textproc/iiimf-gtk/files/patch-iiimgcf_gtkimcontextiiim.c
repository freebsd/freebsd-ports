--- iiimgcf/gtkimcontextiiim.c.orig	Fri Apr 22 07:46:48 2005
+++ iiimgcf/gtkimcontextiiim.c	Tue May 17 23:33:11 2005
@@ -39,6 +39,7 @@
 #include "imaux.h"
 #include "imswitcher.h"
 #include "IIIMGdkEventKey.h"
+#include "iconv.h"
 
 #ifdef DEBUG
 #define DEBUG_DO(x) (x)
@@ -147,6 +148,8 @@
 static GdkAtom im_settings_atom = GDK_NONE;
 static const char *_IM_SETTINGS = "_IM_SETTINGS";
 
+static iconv_t                 ic_u16_to_u8 = (iconv_t)-1;
+
 static gboolean on_status_toplevel_configure (GtkWidget         *toplevel,
 					      GdkEventConfigure *event,
 					      StatusWindow      *status_window);
@@ -305,6 +308,7 @@
       return;
     }
   utf8 = utf16_to_utf8 (text);
+  if (!utf8) utf8 = g_strdup("");
 
   if (current_setting_enabled &&
       (current_setting.im_enabled == IM_OFF ||
@@ -593,9 +597,12 @@
 	    IIIMCF_text text;
 	    gchar *utf8 = NULL;
 	    st = iiimcf_get_committed_text (c, &text);
+	    if (st != IIIMF_STATUS_SUCCESS) break;
 	    utf8 = utf16_to_utf8 (text);
-	    g_signal_emit_by_name (context_iiim, "commit", utf8);
-	    g_free (utf8);
+	    if (utf8) {
+	      g_signal_emit_by_name (context_iiim, "commit", utf8);
+	      g_free (utf8);
+	    }
 	  }
 	  break;
 	default:
@@ -936,7 +943,7 @@
       return;
     }
 
-  gtk_frame_set_label(GTK_FRAME (cw->frame), title_u8);
+  gtk_frame_set_label(GTK_FRAME (cw->frame), (title_u8 ? title_u8 : ""));
 
   if (title_u8)
     g_free (title_u8);
@@ -975,6 +982,7 @@
       if (label)
 	label_u8 = utf16_to_utf8 (label);
       candidate_u8 = utf16_to_utf8 (candidate);
+      if (!candidate_u8) candidate_u8 = g_strdup("");
       DEBUG_DO (g_message ("candidate %s", candidate_u8));
       if (label_u8)
 	{
@@ -997,12 +1005,9 @@
 	    gtk_tree_view_get_selection (GTK_TREE_VIEW (cw->tree));
 	  gtk_tree_selection_select_iter (selection, &iter);
 	}
-      if (result)
-	{
-	  g_free (result);
-	  g_free (label_u8);
-	}
-      g_free (candidate_u8);
+      if (result) g_free(result);
+      if (candidate_u8) g_free (candidate_u8);
+      if (label_u8) g_free(label_u8);
     }
   gtk_widget_realize (w);
   iiim_candidate_move (context_iiim, w);
@@ -1187,7 +1192,7 @@
   w->toplevel = gtk_window_new (GTK_WINDOW_POPUP);
   gtk_container_set_border_width (GTK_CONTAINER (w->toplevel), 2);
 
-  w->frame = gtk_frame_new (title_u8);
+  w->frame = gtk_frame_new (title_u8 ? title_u8 : "");
   gtk_frame_set_shadow_type (GTK_FRAME (w->frame), GTK_SHADOW_ETCHED_OUT);
 
   w->tree = gtk_tree_view_new ();
@@ -1539,14 +1544,52 @@
 }
 
 static gchar *
+iconv_utf16_to_utf8(const gunichar2 *utf16, int length)
+{
+  if (!utf16 || 0 >= length) return g_strdup("");
+
+  if ((iconv_t)-1 == ic_u16_to_u8) {
+    ic_u16_to_u8 = iconv_open("UTF-8", "UTF-16");
+
+    if ((iconv_t)-1 == ic_u16_to_u8) {
+      fprintf(stderr, "iiimgcf: Unable to open UTF-16 -> UTF-8 converter.");
+      return NULL;
+    }
+  }
+
+  int inlen = length * sizeof(gunichar2);
+  int outlen = (length +1) * 4;
+  const char *inbuf = (char*)utf16;
+  char *outbuf = g_malloc0(outlen + 4);
+  gchar *utf8 = (gchar*)outbuf;
+
+  if (!outbuf) {
+    fprintf(stderr, "iiimgcf: Out of memory error.");
+    return NULL;
+  }
+
+  if ((size_t)-1 == iconv(ic_u16_to_u8, &inbuf, &inlen, &outbuf, &outlen)) {
+    fprintf(stderr, "iiimgcf: Unable to convert the string.");
+    g_free(utf8);
+    return NULL;
+  }
+
+  return utf8;
+}
+
+static gchar *
 utf16_to_utf8 (IIIMCF_text text)
 {
   IIIMF_status st;
+
+  int len = 0;
   IIIMP_card16 *u16str = NULL;
   st = iiimcf_get_text_utf16string (text, (const IIIMP_card16 **) &u16str);
-  return (u16str != NULL ?
-	  g_utf16_to_utf8 ((const gunichar2 *) u16str, -1, NULL, NULL, NULL) :
-	  NULL);
+  st = iiimcf_get_text_length(text, &len);
+
+  if (st != IIIMF_STATUS_SUCCESS) return NULL;
+
+  return iconv_utf16_to_utf8((const gunichar2 *)u16str, len);
 }
 
 static void
@@ -2094,7 +2137,7 @@
     goto Error;
   utf8 = utf16_to_utf8 (text);
 
-  if (attrs)
+  if (attrs && utf8)
     {
       gint i;
       gint j;
