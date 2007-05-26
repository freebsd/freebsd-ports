
$FreeBSD$

--- kkstrtext-0.1/kkstrtext.cc.orig
+++ kkstrtext-0.1/kkstrtext.cc
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
@@ -431,7 +431,7 @@
 }
 
 int intcompare(void *s1, void *s2) {
-    return (int) s1 != (int) s2;
+    return (intptr_t) s1 != (intptr_t) s2;
 }
 
 string i2str(int i) {
@@ -885,7 +885,7 @@
 #ifdef HAVE_ICONV
     iconv_t cd = iconv_open(tocs.c_str(), fromcs.c_str());
 
-    if(((int) cd) != -1) {
+    if(((intptr_t) cd) != -1) {
 	string r, text(atext);
 	size_t inleft, outleft, soutleft;
 	char *inbuf, *outbuf, *sinbuf, *soutbuf;
@@ -907,8 +907,8 @@
 	    r += soutbuf;
 	    text.erase(0, text.size()-inleft);
 
-	    delete soutbuf;
-	    delete sinbuf;
+	    delete[] soutbuf;
+	    free(sinbuf);
 
 	    if(res == -1 && errno != EILSEQ)
 		break;
