
$FreeBSD$

--- kkconsui-0.1/src/texteditor.cc.orig
+++ kkconsui-0.1/src/texteditor.cc
@@ -106,7 +106,7 @@
 	fread(p, st.st_size, 1, f);
 	p[st.st_size] = 0;
 	i = load(p, strdup(id.c_str()));
-	delete p;
+	delete[] p;
     }
 
     return i;
@@ -124,7 +124,7 @@
     f.read(buf, size);
     buf[size] = 0;
     ret = load(buf, strdup(id.c_str()));
-    delete buf;
+    delete[] buf;
 
     return ret;
 }
@@ -172,7 +172,7 @@
 int texteditor::save(FILE *f, const char *linebreak) {
     char *buf = save(linebreak);
     fwrite(buf, strlen(buf), 1, f);
-    delete buf;
+    free(buf);
     modified = false;
     return 0;
 }
@@ -180,7 +180,7 @@
 int texteditor::save(ofstream &f, const string linebreak) {
     char *buf = save(linebreak.c_str());
     f.write(buf, strlen(buf));
-    delete buf;
+    free(buf);
     f.close();
     modified = false;
     return 0;
@@ -526,7 +526,7 @@
 	fread(buf, fsize, 1, f);
 	buf[fsize] = 0;
 	insert(buf);
-	delete buf;
+	delete[] buf;
     }
 }
 
@@ -576,8 +576,8 @@
 	    firstpass = false;
 	}
     
-	delete el;
-	delete sl;
+	free(el);
+	free(sl);
 
 	modification(uinsblock, sbuf);
     }
@@ -1081,7 +1081,7 @@
 			curfile->lines->replace(CURLINE, newline);
 		    }
 
-		    delete anext;
+		    free(anext);
 		} else {
 		    if(next) nextlen = strlen(next); else nextlen = 0;
 		    char *newline = new char[nextlen+strlen(p)+1];
@@ -1940,7 +1940,7 @@
 }
 
 int texteditor::findint(void *p1, void *p2) {
-    return *(int *) p1 != (int) p2;
+    return *(int *) p1 != (intptr_t) p2;
 }
 
 int texteditor::findhighline(void *p1, void *p2) {
