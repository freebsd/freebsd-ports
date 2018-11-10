--- libhttp/url.c.orig	2016-11-09 19:40:33 UTC
+++ libhttp/url.c
@@ -312,6 +312,9 @@ static void urlParsePostBody(struct URL *url,
               }
             }
           }
+        } else {
+           warn("[http] broken multipart/form-data!");
+           break;
         }
       }
       if (lastPart) {
