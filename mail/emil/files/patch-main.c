--- main.c.orig	1996-06-04 13:36:58 UTC
+++ main.c
@@ -69,7 +69,7 @@ int	spawn_mailer	= 0;
 int     pseudo_route    = 0;
 
 int	in_fd		= 0;
-FILE	* out_fd	= stdout;
+FILE	* out_fd	= NULL;
 FILE	* char_fd	= NULL;
 FILE	* conf_fd	= NULL;
 off_t   pz;
@@ -84,6 +84,8 @@ int	main(int argc, char *argv[])
   char *cmailer = NULL;
   char *member = NULL;
 
+  out_fd	= stdout;
+
 #ifdef	HAVE_GETPAGESIZE
 	pz = (off_t) getpagesize();
 #elif	defined(hpux) || defined(_AUX_SOURCE)
@@ -177,7 +179,7 @@ int	main(int argc, char *argv[])
 			sprintf(ebuf,"Invalid parameter to -f: %s",optarg);
 #ifdef DEBUG
 		  if (edebug)
-		    fprintf(stderr, ebuf);
+		    fprintf(stderr, "%s", ebuf);
 #endif
 			logger(LOG_WARNING,ebuf);
 		}
@@ -303,7 +305,7 @@ int	main(int argc, char *argv[])
 		sprintf(ebuf,"Invalid flag: -%c",c);
 #ifdef DEBUG
 			if (edebug)
-			  fprintf(stderr, ebuf);
+			  fprintf(stderr, "%s", ebuf);
 #endif
 		logger(LOG_WARNING,ebuf);
 	}
@@ -359,7 +361,7 @@ int	main(int argc, char *argv[])
 	sprintf(ebuf, "Invalid mailer specification %s", optarg);
 #ifdef DEBUG
 	if (edebug)
-	  fprintf(stderr, ebuf);
+	  fprintf(stderr, "%s", ebuf);
 #endif
 	logger(LOG_ERR, ebuf);
 	fprintf(stderr, "Emil: %s\n", ebuf);
@@ -448,7 +450,7 @@ int	main(int argc, char *argv[])
 		);
 #ifdef DEBUG
       if (edebug)
-	fprintf(stderr, ebuf);
+	fprintf(stderr, "%s", ebuf);
 #endif
   logger(LOG_DEBUG,ebuf);
   if (source == NULL)
