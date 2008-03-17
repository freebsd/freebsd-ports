--- ./dkim-filter/dkim-filter.c.orig	2008-03-06 04:29:36.000000000 +0900
+++ ./dkim-filter/dkim-filter.c	2008-03-12 23:57:52.000000000 +0900
@@ -2481,6 +2481,16 @@
 		if (status != DKIM_STAT_OK)
 			return FALSE;
 	}
+	else
+	{
+		status = dkim_options(conf->conf_libdkim, DKIM_OP_SETOPT,
+		                      DKIM_OPTS_SKIPHDRS,
+		                      (void *) should_not_signhdrs,
+		                      sizeof (u_char **));
+
+		if (status != DKIM_STAT_OK)
+			return FALSE;
+	}
 
 	if (conf->conf_signhdrs != NULL)
 	{
@@ -2494,8 +2504,8 @@
 	else
 	{
 		status = dkim_options(conf->conf_libdkim, DKIM_OP_SETOPT,
-		                      DKIM_OPTS_SKIPHDRS,
-		                      (void *) should_not_signhdrs,
+		                      DKIM_OPTS_SIGNHDRS,
+		                      (void *) should_signhdrs,
 		                      sizeof (u_char **));
 
 		if (status != DKIM_STAT_OK)
@@ -7447,6 +7457,9 @@
 	}
 #endif /* _FFR_BODYLENGTH_DB */
 
+	pthread_mutex_init(&popen_lock, NULL);
+	pthread_mutex_init(&conf_lock, NULL);
+
 	/* perform test mode */
 	if (testfile != NULL)
 	{
@@ -7456,9 +7469,6 @@
 		return status;
 	}
 
-	pthread_mutex_init(&popen_lock, NULL);
-	pthread_mutex_init(&conf_lock, NULL);
-
 	memset(argstr, '\0', sizeof argstr);
 	end = &argstr[sizeof argstr - 1];
 	n = sizeof argstr;
