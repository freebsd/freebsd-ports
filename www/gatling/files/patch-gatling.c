--- gatling.c.orig	Wed Jul 28 15:23:51 2004
+++ gatling.c	Mon Jan 31 18:42:03 2005
@@ -1261,6 +1261,7 @@ e404:
 		++c;
 		if ((i=scan_ulonglong(c,&range_last))) {
 		  if (!i) goto rangeerror;
+		  ++range_last;
 		}
 	      }
 	    } else {
@@ -1311,7 +1312,7 @@ rangeerror:
 	  c+=fmt_str(c,"\r\nContent-Range: bytes ");
 	  c+=fmt_ulonglong(c,range_first);
 	  c+=fmt_str(c,"-");
-	  c+=fmt_ulonglong(c,range_last);
+	  c+=fmt_ulonglong(c,range_last-1);
 	  c+=fmt_str(c,"/");
 	  c+=fmt_ulonglong(c,ss.st_size);
 	}
