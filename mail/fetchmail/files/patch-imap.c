--- ./imap.c.orig	2003-10-15 21:17:41.000000000 +0200
+++ ./imap.c	2005-10-29 15:19:58.000000000 +0200
@@ -105,6 +105,15 @@
 	{
 	    recentcount = atoi(buf+2);
 	}
+	/* servers are not required to update the EXISTS counts,
+	 * so count down by ourselves */
+	else if (strstr(buf, " EXPUNGE"))
+	{
+	    if (atoi(buf+2) > 0) {
+	       if (count > 0)
+		   count --;
+	    }
+	}
 	else if (strstr(buf, "PREAUTH"))
 	    preauth = TRUE;
 	/*
