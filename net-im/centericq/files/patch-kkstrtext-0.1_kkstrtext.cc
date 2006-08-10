--- kkstrtext-0.1/kkstrtext.cc.orig	Wed Aug  9 10:44:43 2006
+++ kkstrtext-0.1/kkstrtext.cc	Wed Aug  9 10:50:27 2006
@@ -154,7 +154,7 @@
     string r;
     char *buf = (char *) utf8_to_str(text.c_str());
     r = buf;
-    delete buf;
+    delete[] buf;
     return r;
 }
 
@@ -162,7 +162,7 @@
     string r;
     char *buf = str_to_utf8(text.c_str());
     r = buf;
-    delete buf;
+    delete[] buf;
     return r;
 }
 
@@ -416,7 +416,7 @@
 
 void charpointerfree(void *p) {
     char *cp = (char *) p;
-    if(cp) delete cp;
+    if(cp) free(cp);
 }
 
 void nothingfree(void *p) {
@@ -907,8 +907,8 @@
 	    r += soutbuf;
 	    text.erase(0, text.size()-inleft);
 
-	    delete soutbuf;
-	    delete sinbuf;
+	    delete[] soutbuf;
+	    free(sinbuf);
 
 	    if(res == -1 && errno != EILSEQ)
 		break;
