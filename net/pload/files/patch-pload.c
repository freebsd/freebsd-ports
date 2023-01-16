--- pload.c.orig	2000-02-01 07:11:24 UTC
+++ pload.c
@@ -285,6 +285,13 @@ static XtResource pload_resources[] = {
 /************* Main () ******************/
 int main (int argc, char *argv[])
 {
+	char *orig_argv[64];
+	int i;
+
+	/* save original argv pointers */
+	for(i = 0; argv[i]; i++)
+		orig_argv[i] = argv[i];
+
 	Progname = argv[0];
 	
 	toplevel = XtAppInitialize (
@@ -301,6 +308,11 @@ int main (int argc, char *argv[])
 	   and exit */	
 	if (argc != 1) Usage();
 	
+	/* XtAppInitialize() eats the arguments, so restore original
+	   argv so that ps(1) shows the command line */
+	for(i = 0; orig_argv[i]; i++)
+		argv[i] = orig_argv[i];
+
 	XtGetApplicationResources(
 		toplevel,			/* widget */
 		(XtPointer) &resources, 	/* where to put */
@@ -596,27 +608,26 @@ void CheckForWMExit(	Widget w, 
 void do_total(char *b, double total)
 {
 	if (total < 1024.0)
-		sprintf(b, "%s%0.0f b", b, total);
+		sprintf(b, "%s%0.0f B", b, total);
 	else if (total < (1024.0*1024.0))
-		sprintf(b, "%s%0.2f k", b, total/1024.0);
+		sprintf(b, "%s%0.2f kiB", b, total/1024.0);
 	else if (total < (1024.0*1024.0*1024.0))
-		sprintf(b, "%s%0.2f M", b, total/1024.0/1024.0);
+		sprintf(b, "%s%0.2f MiB", b, total/1024.0/1024.0);
 	else
-		sprintf(b, "%s%0.2f G", b, total/1024.0/1024.0/1024.0);
-	
+		sprintf(b, "%s%0.2f GiB", b, total/1024.0/1024.0/1024.0);
 	return;
 }
 
 void do_rate(char *b, double rate)
 {
 	if (rate < 1024.0)
-		sprintf(b, "%s%0.0f b/s",b, rate);
+		sprintf(b, "%s%0.0f B/s",b, rate);
 	else if (rate < (1024.0*1024.0))
-		sprintf(b, "%s%0.2f k/s",b, rate/1024.0);
+		sprintf(b, "%s%0.2f kiB/s",b, rate/1024.0);
 	else if (rate < (1024.0*1024.0*1024.0))
-		sprintf(b, "%s%0.2f M/s",b, rate/1024.0/1024.0);
+		sprintf(b, "%s%0.2f MiB/s",b, rate/1024.0/1024.0);
 	else
-		sprintf(b, "%s%0.2f G/s", b, rate/1024.0/1024.0/1024.0);
+		sprintf(b, "%s%0.2f GiB/s", b, rate/1024.0/1024.0/1024.0);
 	return;
 }
 
@@ -643,6 +654,9 @@ void make_label(char *fmt, unsigned long total, double
 					break;
 				case 'M':
 					do_rate(buff, max);
+					break;
+				case 'd':
+					strcat(buff, resources.device);
 					break;
 				case '%':	/* literal % */
 					i = strlen(buff);
