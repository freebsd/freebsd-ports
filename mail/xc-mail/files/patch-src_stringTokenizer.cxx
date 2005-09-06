--- src/stringTokenizer.cxx.orig	Wed Aug 17 11:05:22 2005
+++ src/stringTokenizer.cxx	Wed Aug 17 13:35:24 2005
@@ -455,7 +455,7 @@
 	{
 		chs+=strlen(get(i)->tokenize(delim2?delim2:delim,ign_bslash))+l;
 	}
-	if (!(return_buf=(char*)malloc(chs)))
+	if (chs == 0 || !(return_buf=(char*)malloc(chs)))
 	{
 		return (char*)"";
 	}
@@ -478,7 +478,7 @@
 			}
 		}
 	}
-	*d=0;
+	//*d=0;
 	return return_buf;
 }
 
