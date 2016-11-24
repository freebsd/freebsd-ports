--- lig.awk.orig	2010-03-04 12:13:47 UTC
+++ lig.awk
@@ -24,14 +24,20 @@ c=b
 c!=b { print c }
 
 /f[1-9]?$/ {
-	print gensub("f[1-9]?$", "ﬀ", "g", b);
-	if (c!=b) print gensub("f[1-9]?$", "ﬀ", "g", c);
+	out=b; gsub("f[1-9]?$", "ﬀ", out); print out
+	if (c!=b) {
+		out=c; gsub("f[1-9]?$", "ﬀ", out); print out
+	}
 
-	print gensub("f[1-9]?$", "ﬁ", "g", b);
-	if (c!=b) print gensub("f[1-9]?$", "ﬁ", "g", c);
+	out=b; gsub("f[1-9]?$", "ﬁ", out); print out
+	if (c!=b) {
+		out=c; gsub("f[1-9]?$", "ﬁ", out); print out
+	}
 
-	print gensub("f[1-9]?$", "ﬂ", "g", b);
-	if (c!=b) print gensub("f[1-9]?$", "ﬂ", "g", c);
+	out=b; gsub("f[1-9]?$", "ﬂ", out); print out
+	if (c!=b) {
+		out=c; gsub("f[1-9]?$", "ﬂ", out); print out
+	}
 }
 
 
