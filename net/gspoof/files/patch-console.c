--- console.c.orig	Sat Aug 30 00:16:50 2003
+++ console.c	Sat Aug 30 15:56:23 2003
@@ -335,7 +335,11 @@
 		  fgets(value, 20, stdin);
 		  seq = atol(value);
 	       }
+#ifdef __FreeBSD__
+	     while (atoi(value) < 0 || strtoll(value, NULL, 10) > 4294970000);
+#else
 	     while (atoi(value) < 0 || atoll(value) > 4294970000);
+#endif
 	  }
 	else if (!strcmp ("3.5", cmd))
 	  {
@@ -345,7 +349,11 @@
 		  fgets(value, 20, stdin);
 		  ack = atol(value);
 	       }
+#ifdef __FreeBSD__
+	     while (atoi(value) < 0 || strtoll(value, NULL, 10) > 4294970000);
+#else
 	     while (atoi(value) < 0 || atoll(value) > 4294970000);
+#endif
 	  }
 	else if (!strcmp ("3.6", cmd))
 	  {
