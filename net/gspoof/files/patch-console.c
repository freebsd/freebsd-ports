--- console.c.orig	Wed Sep 25 04:20:25 2002
+++ console.c	Wed May  7 03:42:30 2003
@@ -333,7 +333,11 @@
 		  fgets(value, 20, stdin);
 		  seq = atol(value);
 	       }
+#ifdef __FreeBSD__
+	     while (atoi(value) < 0 || atoi(value) > 4294970000);
+#else
 	     while (atoi(value) < 0 || atoll(value) > 4294970000);
+#endif
 	  }
 	else if (!strcmp ("3.5", cmd))
 	  {
@@ -343,7 +347,11 @@
 		  fgets(value, 20, stdin);
 		  ack = atol(value);
 	       }
+#ifdef __FreeBSD__
+	     while (atoi(value) < 0 || atoi(value) > 4294970000);
+#else
 	     while (atoi(value) < 0 || atoll(value) > 4294970000);
+#endif
 	  }
 	else if (!strcmp ("3.6", cmd))
 	  {
