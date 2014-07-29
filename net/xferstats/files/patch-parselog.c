--- parselog.c.orig	Sun Oct 13 17:39:55 2002
+++ parselog.c	Sun Oct 13 17:42:12 2002
@@ -202,15 +202,11 @@
     
     while (1) {
       if (pointers->config->use_stdin) {
-	if (feof(stdin))
+	if (fgets(foo, sizeof(foo), stdin) == NULL)
 	  break;
-	/* there's probably a better way to do this :) */
-	fgets(foo, sizeof(foo), stdin);
       } else {
-	if (feof(log_stream))
+	if (fgets(foo, sizeof(foo), log_stream) == NULL)
 	  break;
-	
-	fgets(foo, sizeof(foo), log_stream);
       }
       
       if ((len = strlen(foo)) < 42)
@@ -455,10 +451,8 @@
 #ifdef HAVE_MMAP
 	  if (pointers->config->use_stdin)
 	    {
-	      if (feof(stdin))
+	      if (fgets(foo, sizeof(foo), stdin) == NULL)
 		break;
-	      /* there's probably a better way to do this :) */
-	      fgets(foo, sizeof(foo), stdin);
 	    }
 	  else
 	    {
@@ -497,17 +491,13 @@
 #else /* HAVE_MMAP */
 	  if (pointers->config->use_stdin)
 	    {
-	      if (feof(stdin))
+	      if (fgets(foo, sizeof(foo), stdin) == NULL)
 		break;
-	      /* there's probably a better way to do this :) */
-	      fgets(foo, sizeof(foo), stdin);
 	    }
 	  else
 	    {
-	      if (feof(log_stream))
+	      if (fgets(foo, sizeof(foo), log_stream) == NULL)
 		break;
-
-	      fgets(foo, sizeof(foo), log_stream);
 	    }
 #endif /* HAVE_MMAP */
 
@@ -770,10 +760,8 @@
 #ifdef HAVE_MMAP
 	  if (pointers->config->use_stdin)
 	    {
-	      if (feof(stdin))
+	      if (fgets(foo, sizeof(foo), stdin) == NULL)
 		break;
-	      /* there's probably a better way to do this :) */
-	      fgets(foo, 2047, stdin);
 	    }
 	  else
 	    {
@@ -812,17 +800,13 @@
 #else /* HAVE_MMAP */
 	  if (pointers->config->use_stdin)
 	    {
-	      if (feof(stdin))
+	      if (fgets(foo, sizeof(foo), stdin) == NULL)
 		break;
-	      /* there's probably a better way to do this :) */
-	      fgets(foo, 2047, stdin);
 	    }
 	  else
 	    {
-	      if (feof(log_stream))
+	      if (fgets(foo, sizeof(foo), log_stream) == NULL)
 		break;
-
-	      fgets(foo, sizeof(foo), log_stream);
 	    }
 #endif /* HAVE_MMAP */
 
