--- gtk/main.c.orig	2015-05-13 14:47:31 UTC
+++ gtk/main.c
@@ -1919,9 +1919,7 @@ void linphone_gtk_log_handler(OrtpLogLev
 	if (verbose){
 		const char *lname="undef";
 		char *msg;
-#if defined(__linux) || defined(__APPLE__)
 		va_list cap;/*copy of our argument list: a va_list cannot be re-used (SIGSEGV on linux 64 bits)*/
-#endif
 		switch(lev){
 			case ORTP_DEBUG:
 				lname="debug";
@@ -1941,13 +1939,9 @@ void linphone_gtk_log_handler(OrtpLogLev
 			default:
 				g_error("Bad level !");
 		}
-#if defined(__linux) || defined(__APPLE__)
 		va_copy(cap,args);
 		msg=g_strdup_vprintf(fmt,cap);
 		va_end(cap);
-#else
-		msg=g_strdup_vprintf(fmt,args);
-#endif
 		fprintf(stdout,"linphone-%s : %s\n",lname,msg);
 		ortp_free(msg);
 	}
