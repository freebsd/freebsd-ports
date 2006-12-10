--- cgi.c      Mon Nov 13 20:05:50 2006
+++ cgi.c      Sat Dec  9 14:49:16 2006
@@ -571,10 +579,12 @@
          "Look up which actions apply to a URL and why",
          TRUE },
 #ifdef FEATURE_CGI_EDIT_ACTIONS
+#ifdef FEATURE_TOGGLE
    { "toggle",
          cgi_toggle, 
          "Toggle Privoxy on or off",
          FALSE },
+#endif /* def FEATURE_TOGGLE */
    { "edit-actions", /* Edit the actions list */
          cgi_edit_actions, 
          NULL, FALSE },
