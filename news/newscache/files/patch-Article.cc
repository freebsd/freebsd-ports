--- NServer-0.9.1/Article.cc.orig	Sun Apr  6 18:09:33 2003
+++ NServer-0.9.1/Article.cc	Sun Apr  6 18:10:44 2003
@@ -93,7 +93,7 @@
 	}
 }
 
-string Article::getfield(const char *ifld, int Full = 0) const
+string Article::getfield(const char *ifld, int Full) const
 {
 	string rfld;
 	const char *p, *fld;
@@ -214,7 +214,7 @@
 	_ctext = _text.c_str();
 }
 
-ostream & Article::write(ostream & os, int flags = Head | Body)
+ostream & Article::write(ostream & os, int flags)
 {
 	const char *p, *q;
 
