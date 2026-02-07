--- object/url.c.orig	2003-08-18 16:58:57 UTC
+++ object/url.c
@@ -362,7 +362,8 @@ URLparse(Url *url)
           case ftp:
           case unset:
           case unknown:
-	  }
+	  break; 
+	}
 	  URLsetHost(url, cp);
      }
 
