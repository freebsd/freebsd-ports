--- monitord.c.orig	2003-01-16 21:39:44.000000000 +0000
+++ monitord.c	2011-11-24 23:12:13.468148722 +0000
@@ -85,8 +85,8 @@
 			setsid ();
 			break;
 		}
-		default: 
-		exit(1);
+		default: // The parent exits
+		exit(0);
 	}
 
 	/* Read the configuration file, saving it in *file[] and return the number of lines
@@ -454,13 +454,13 @@
 
 	struct timeval *tp;
 	struct timezone *tzp;
-	const time_t *time;
+	time_t *time;
 	char *buf;
 
 	buf = (char *) malloc ( (size_t) _BUFSIZE ); // init the time buffer
 	tp = (struct timeval *) malloc ( (size_t) sizeof (struct timeval) ); // init the time buffer
 	tzp = (struct timezone *) malloc ( (size_t) sizeof (struct timezone) ); // init the timezone buffer
-	time = (const time_t *) malloc ( (size_t) sizeof (time_t) ); // init the timezone buffer
+	time = (time_t *) malloc ( (size_t) sizeof (time_t) ); // init the timezone buffer
 
 	/* Get time of day in seconds since Epoch */
 	gettimeofday (tp, tzp);
