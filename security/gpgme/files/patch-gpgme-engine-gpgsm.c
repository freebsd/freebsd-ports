--- gpgme/engine-gpgsm.c.orig	Sat Dec 11 13:36:05 2004
+++ gpgme/engine-gpgsm.c	Sat Dec 11 13:36:09 2004
@@ -1,6 +1,6 @@
 /* engine-gpgsm.c - GpgSM engine.
    Copyright (C) 2000 Werner Koch (dd9jn)
-   Copyright (C) 2001, 2002, 2003, 2004 g10 Code GmbH
+   Copyright (C) 2001, 2002, 2003 g10 Code GmbH
  
    This file is part of GPGME.
 
@@ -40,7 +40,6 @@
 
 #include "assuan.h"
 #include "status-table.h"
-#include "debug.h"
 
 #include "engine-backend.h"
 
@@ -153,12 +152,6 @@
 static gpgme_error_t
 map_assuan_error (AssuanError err)
 {
-  if (!err)
-    return 0;
-
-  if (err == -1)
-    return gpg_error (GPG_ERR_INV_ENGINE);
-
   /* New code will use gpg_error_t values.  */
   if (gpg_err_source (err))
     return (gpgme_error_t) err;
@@ -276,13 +269,13 @@
 }
 
 
-static gpgme_error_t
-gpgsm_cancel (void *engine)
+static void
+gpgsm_release (void *engine)
 {
   engine_gpgsm_t gpgsm = engine;
 
   if (!gpgsm)
-    return gpg_error (GPG_ERR_INV_VALUE);
+    return;
 
   if (gpgsm->status_cb.fd != -1)
     _gpgme_io_close (gpgsm->status_cb.fd);
@@ -293,25 +286,7 @@
   if (gpgsm->message_cb.fd != -1)
     _gpgme_io_close (gpgsm->message_cb.fd);
 
-  if (gpgsm->assuan_ctx)
-    {
-      assuan_disconnect (gpgsm->assuan_ctx);
-      gpgsm->assuan_ctx = NULL;
-    }
-
-  return 0;
-}
-
-
-static void
-gpgsm_release (void *engine)
-{
-  engine_gpgsm_t gpgsm = engine;
-
-  if (!gpgsm)
-    return;
-
-  gpgsm_cancel (engine);
+  assuan_disconnect (gpgsm->assuan_ctx);
 
   free (gpgsm->colon.attic.line);
   free (gpgsm);
@@ -319,7 +294,7 @@
 
 
 static gpgme_error_t
-gpgsm_new (void **engine, const char *lc_ctype, const char *lc_messages)
+gpgsm_new (void **engine)
 {
   gpgme_error_t err = 0;
   engine_gpgsm_t gpgsm;
@@ -327,8 +302,10 @@
   int fds[2];
   int child_fds[4];
   char *dft_display = NULL;
-  char dft_ttyname[64];
+  char *dft_ttyname = NULL;
   char *dft_ttytype = NULL;
+  char *old_lc = NULL;
+  char *dft_lc = NULL;
   char *optstr;
   int fdlist[5];
   int nfds;
@@ -401,7 +378,6 @@
 
   err = assuan_pipe_connect (&gpgsm->assuan_ctx,
 			     _gpgme_get_gpgsm_path (), argv, child_fds);
-  /* FIXME: Check error.  */
 
   /* We need to know the fd used by assuan for reads.  We do this by
      using the assumption that the first returned fd from
@@ -427,19 +403,14 @@
   gpgsm->status_cb.dir = 1;
   gpgsm->status_cb.data = gpgsm;
 
-  err = _gpgme_getenv ("DISPLAY", &dft_display);
-  if (err)
-    goto leave;
+  dft_display = getenv ("DISPLAY");
   if (dft_display)
     {
       if (asprintf (&optstr, "OPTION display=%s", dft_display) < 0)
         {
-	  free (dft_display);
 	  err = gpg_error_from_errno (errno);
 	  goto leave;
 	}
-      free (dft_display);
-
       err = assuan_transact (gpgsm->assuan_ctx, optstr, NULL, NULL, NULL,
 			     NULL, NULL, NULL);
       free (optstr);
@@ -449,17 +420,27 @@
 	  goto leave;
 	}
     }
-
-  if (isatty (1))
+  dft_ttyname = ttyname (1);
+  if (dft_ttyname)
     {
-      if (ttyname_r (1, dft_ttyname, sizeof (dft_ttyname)))
-	{
+      if (asprintf (&optstr, "OPTION ttyname=%s", dft_ttyname) < 0)
+        {
 	  err = gpg_error_from_errno (errno);
 	  goto leave;
 	}
-      else
+      err = assuan_transact (gpgsm->assuan_ctx, optstr, NULL, NULL, NULL,
+			     NULL, NULL, NULL);
+      free (optstr);
+      if (err)
 	{
-	  if (asprintf (&optstr, "OPTION ttyname=%s", dft_ttyname) < 0)
+	  err = map_assuan_error (err);
+	  goto leave;
+	}
+
+      dft_ttytype = getenv ("TERM");
+      if (dft_ttytype)
+	{
+	  if (asprintf (&optstr, "OPTION ttytype=%s", dft_ttytype) < 0)
 	    {
 	      err = gpg_error_from_errno (errno);
 	      goto leave;
@@ -472,73 +453,82 @@
 	      err = map_assuan_error (err);
 	      goto leave;
 	    }
+	}
 
-	  err = _gpgme_getenv ("TERM", &dft_ttytype);
-	  if (err)
-	    goto leave;
-	  if (dft_ttytype)
+      old_lc = setlocale (LC_CTYPE, NULL);
+      if (old_lc)
+        {
+          old_lc = strdup (old_lc);
+          if (!old_lc)
+            {
+              err = gpg_error_from_errno (errno);
+              goto leave;
+            }
+        }
+      dft_lc = setlocale (LC_CTYPE, "");
+      if (dft_lc)
+	{
+	  if (asprintf (&optstr, "OPTION lc-ctype=%s", dft_lc) < 0)
+	    err = gpg_error_from_errno (errno);
+	  else
 	    {
-	      if (asprintf (&optstr, "OPTION ttytype=%s", dft_ttytype) < 0)
-		{
-		  free (dft_ttytype);
-		  err = gpg_error_from_errno (errno);
-		  goto leave;
-		}
-	      free (dft_ttytype);
-
 	      err = assuan_transact (gpgsm->assuan_ctx, optstr, NULL, NULL,
-				     NULL, NULL, NULL, NULL);
+                                     NULL, NULL, NULL, NULL);
 	      free (optstr);
 	      if (err)
-		{
-		  err = map_assuan_error (err);
-		  goto leave;
-		}
+		err = map_assuan_error (err);
 	    }
 	}
-    }
+      if (old_lc)
+        {
+          setlocale (LC_CTYPE, old_lc);
+          free (old_lc);
+        }
+      if (err)
+	goto leave;
 
-  if (lc_ctype)
-    {
-      if (asprintf (&optstr, "OPTION lc-ctype=%s", lc_ctype) < 0)
-	err = gpg_error_from_errno (errno);
-      else
-	{
-	  err = assuan_transact (gpgsm->assuan_ctx, optstr, NULL, NULL,
-				 NULL, NULL, NULL, NULL);
-	  free (optstr);
-	  if (err)
-	    err = map_assuan_error (err);
-	}
-    }
-  if (err)
-    goto leave;
-  
-  if (lc_messages)
-    {
-      if (asprintf (&optstr, "OPTION lc-messages=%s", lc_messages) < 0)
-	err = gpg_error_from_errno (errno);
-      else
+      old_lc = setlocale (LC_MESSAGES, NULL);
+      if (old_lc)
+        {
+          old_lc = strdup (old_lc);
+          if (!old_lc)
+            {
+              err = gpg_error_from_errno (errno);
+              goto leave;
+            }
+        }
+      dft_lc = setlocale (LC_MESSAGES, "");
+      if (dft_lc)
 	{
-	  err = assuan_transact (gpgsm->assuan_ctx, optstr, NULL, NULL,
-				 NULL, NULL, NULL, NULL);
-	  free (optstr);
-	  if (err)
-	    err = map_assuan_error (err);
+	  if (asprintf (&optstr, "OPTION lc-messages=%s", dft_lc) < 0)
+	    err = gpg_error_from_errno (errno);
+	  else
+	    {
+	      err = assuan_transact (gpgsm->assuan_ctx, optstr, NULL, NULL,
+				     NULL, NULL, NULL, NULL);
+	      free (optstr);
+	      if (err)
+		err = map_assuan_error (err);
+	    }
 	}
+      if (old_lc)
+        {
+          setlocale (LC_MESSAGES, old_lc);
+          free (old_lc);
+        }
+      if (err)
+	goto leave;
     }
-  if (err)
-    goto leave;
 
-  if (!err
-      && (_gpgme_io_set_close_notify (gpgsm->status_cb.fd,
+  if (!err &&
+      (_gpgme_io_set_close_notify (gpgsm->status_cb.fd,
+				   close_notify_handler, gpgsm)
+       || _gpgme_io_set_close_notify (gpgsm->input_cb.fd,
+				   close_notify_handler, gpgsm)
+       || _gpgme_io_set_close_notify (gpgsm->output_cb.fd,
 				      close_notify_handler, gpgsm)
-	  || _gpgme_io_set_close_notify (gpgsm->input_cb.fd,
-					 close_notify_handler, gpgsm)
-	  || _gpgme_io_set_close_notify (gpgsm->output_cb.fd,
-					 close_notify_handler, gpgsm)
-	  || _gpgme_io_set_close_notify (gpgsm->message_cb.fd,
-					 close_notify_handler, gpgsm)))
+       || _gpgme_io_set_close_notify (gpgsm->message_cb.fd,
+				      close_notify_handler, gpgsm)))
     {
       err = gpg_error (GPG_ERR_GENERAL);
       goto leave;
@@ -697,8 +687,6 @@
 	  /* Try our best to terminate the connection friendly.  */
 	  /*	  assuan_write_line (gpgsm->assuan_ctx, "BYE"); */
 	  err = map_assuan_error (assuan_err);
-          DEBUG3 ("fd %d: error from assuan (%d) getting status line : %s \n",
-                  fd, assuan_err, gpg_strerror (err));
 	}
       else if (linelen >= 3
 	       && line[0] == 'E' && line[1] == 'R' && line[2] == 'R'
@@ -708,8 +696,6 @@
 	    err = map_assuan_error (atoi (&line[4]));
 	  else
 	    err = gpg_error (GPG_ERR_GENERAL);
-          DEBUG2 ("fd %d: ERR line - mapped to: %s\n",
-                  fd, err? gpg_strerror (err):"ok");
 	}
       else if (linelen >= 2
 	       && line[0] == 'O' && line[1] == 'K'
@@ -730,8 +716,6 @@
               err = gpgsm->colon.fnc (gpgsm->colon.fnc_value, NULL);
             }
 	  _gpgme_io_close (gpgsm->status_cb.fd);
-          DEBUG2 ("fd %d: OK line - final status: %s\n",
-                  fd, err? gpg_strerror (err):"ok");
 	  return err;
 	}
       else if (linelen > 2
@@ -805,8 +789,6 @@
 		    dst++;
 		}
 	    }
-          DEBUG2 ("fd %d: D line; final status: %s\n",
-                  fd, err? gpg_strerror (err):"ok");
         }
       else if (linelen > 2
 	       && line[0] == 'S' && line[1] == ' ')
@@ -829,8 +811,6 @@
 	    }
 	  else
 	    fprintf (stderr, "[UNKNOWN STATUS]%s %s", line + 2, rest);
-          DEBUG3 ("fd %d: S line (%s) - final status: %s\n",
-                  fd, line+2, err? gpg_strerror (err):"ok");
 	}
     }
   while (!err && assuan_pending_line (gpgsm->assuan_ctx));
@@ -870,7 +850,7 @@
     err = add_io_cb (gpgsm, &gpgsm->message_cb, _gpgme_data_outbound_handler);
 
   if (!err)
-    err = map_assuan_error (assuan_write_line (gpgsm->assuan_ctx, command));
+    err = assuan_write_line (gpgsm->assuan_ctx, command);
 
   if (!err)
     (*gpgsm->io_cbs.event) (gpgsm->io_cbs.event_priv, GPGME_EVENT_START, NULL);
@@ -1128,6 +1108,7 @@
 	      patlet++;
 	    }
 	  pat++;
+	  /* This will allocate one byte more than necessary.  */
 	  length++;
 	}
     }
@@ -1170,8 +1151,6 @@
 	      patlet++;
 	    }
 	  pattern++;
-          if (*pattern)
-            *linep++ = ' ';
 	}
     }
   *linep = '\0';
@@ -1263,16 +1242,6 @@
   if (err)
     return err;
 
-
-  /* Use the validation mode if required.  We don't check for an error
-     yet because this is a pretty fresh gpgsm features. */
-  gpgsm_assuan_simple_command (gpgsm->assuan_ctx, 
-                               (mode & GPGME_KEYLIST_MODE_VALIDATE)?
-                               "OPTION with-validation=1":
-                               "OPTION with-validation=0" ,
-                               NULL, NULL);
-
-
   /* Length is "LISTSECRETKEYS " + p + '\0'.  */
   line = malloc (15 + strlen (pattern) + 1);
   if (!line)
@@ -1308,7 +1277,6 @@
   /* Length is "LISTSECRETKEYS " + p + '\0'.  */
   int length = 15 + 1;
   char *linep;
-  int any_pattern = 0;
   int list_mode = 0;
 
   if (reserved)
@@ -1326,15 +1294,6 @@
   if (err)
     return err;
 
-  /* Use the validation mode if required.  We don't check for an error
-     yet because this is a pretty fresh gpgsm features. */
-  gpgsm_assuan_simple_command (gpgsm->assuan_ctx, 
-                               (mode & GPGME_KEYLIST_MODE_VALIDATE)?
-                               "OPTION with-validation=1":
-                               "OPTION with-validation=0" ,
-                               NULL, NULL);
-
-
   if (pattern && *pattern)
     {
       const char **pat = pattern;
@@ -1351,6 +1310,7 @@
 	      patlet++;
 	    }
 	  pat++;
+	  /* This will allocate one byte more than necessary.  */
 	  length++;
 	}
     }
@@ -1399,13 +1359,9 @@
 		}
 	      patlet++;
 	    }
-          any_pattern = 1;
-          *linep++ = ' ';
 	  pattern++;
 	}
     }
-  if (any_pattern)
-    linep--;
   *linep = '\0';
 
   _gpgme_io_close (gpgsm->input_cb.fd);
@@ -1439,8 +1395,8 @@
   if (err)
     return err;
 
-  /* We must send a reset because we need to reset the list of
-     signers.  Note that RESET does not reset OPTION commands. */
+  /* We must do a reset becuase we need to reset the list of signers.  Note
+     that RESET does not reset OPTION commands. */
   err = gpgsm_assuan_simple_command (gpgsm->assuan_ctx, "RESET", NULL, NULL);
   if (err)
     return err;
@@ -1590,6 +1546,5 @@
     NULL,		/* trustlist */
     gpgsm_verify,
     gpgsm_set_io_cbs,
-    gpgsm_io_event,
-    gpgsm_cancel
+    gpgsm_io_event
   };
