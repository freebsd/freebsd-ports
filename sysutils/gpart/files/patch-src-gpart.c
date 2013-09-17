--- src/gpart.c.orig	2001-02-07 21:08:08.000000000 +0300
+++ src/gpart.c	2013-09-17 03:12:11.505226148 +0400
@@ -69,7 +69,7 @@
 int		(*boundary_fun)(disk_desc *,s64_t);
 unsigned long	increment = 'h', gc = 0, gh = 0, gs = 0;
 s64_t		skipsec = 0, maxsec = 0;
-FILE		*log = 0;
+FILE		*logfile = 0;
 
 
 
@@ -125,26 +125,26 @@
 		case FATAL :
 			g_mod_deleteall();
 			if (! f_quiet) fprintf(stderr,EM_FATALERROR,msg);
-			if (log)
+			if (logfile)
 			{
-				fprintf(log,EM_FATALERROR,msg);
-				fclose(log);
+				fprintf(logfile,EM_FATALERROR,msg);
+				fclose(logfile);
 			}
 			exit(1);
 		case ERROR :
 			if (! f_quiet) fprintf(stderr,EM_SIMPLEERROR,msg);
-			if (log) fprintf(log,EM_SIMPLEERROR,msg);
+			if (logfile) fprintf(logfile,EM_SIMPLEERROR,msg);
 			break;
 		case WARN :
 			if (! f_quiet) fprintf(stderr,EM_WARNING,msg);
-			if (log) fprintf(log,EM_WARNING,msg);
+			if (logfile) fprintf(logfile,EM_WARNING,msg);
 			break;
 		case MSG :
 			if (! f_quiet) fputs(msg,stdout); fflush(stdout);
-			if (log) fputs(msg,log);
+			if (logfile) fputs(msg,logfile);
 			break;
 	}
-	if (log) fflush(log);
+	if (logfile) fflush(logfile);
 }
 
 
@@ -1750,8 +1750,8 @@
 				}
 				break;
 			case 'l' :
-				if (log) fclose(log);
-				if ((log = fopen(optarg,"w")) == 0)
+				if (logfile) fclose(logfile);
+				if ((logfile = fopen(optarg,"w")) == 0)
 					pr(FATAL,EM_OPENLOG,optarg);
 				break;
 			case 'L' :
@@ -1831,7 +1831,7 @@
 		}
 	}
 	free_disk_desc(d);
-	if (log) fclose(log);
+	if (logfile) fclose(logfile);
 
 	return (f_check ? no_of_incons : 0);
 }
