--- src/translate-session.c.orig	Mon Apr 11 22:44:53 2005
+++ src/translate-session.c	Mon Apr 11 22:51:48 2005
@@ -703,7 +703,14 @@
 	  GError *tmp_err = NULL;
 
 	  g_mutex_lock(info->mutex);
-	  ret = info->err != NULL;
+	  if (info->err)
+	    {
+	      ret = TRUE;
+	      if (info->progress_cond)
+		g_cond_signal(info->progress_cond);
+	    }
+	  else
+	    ret = FALSE;
 	  g_mutex_unlock(info->mutex);
 
 	  if (ret)
@@ -728,6 +735,9 @@
 		  else
 		    g_propagate_error(&info->err, tmp_err);
 
+		  if (info->progress_cond)
+		    g_cond_signal(info->progress_cond);
+
 		  g_mutex_unlock(info->mutex);
 
 		  return;
@@ -759,6 +769,9 @@
 	info->err = g_error_new(TRANSLATE_SESSION_ERROR,
 				TRANSLATE_SESSION_ERROR_NO_SERVICE,
 				_("no service could translate chunk"));
+
+      if (info->progress_cond)
+	g_cond_signal(info->progress_cond);
     }
   
   g_mutex_unlock(info->mutex);
