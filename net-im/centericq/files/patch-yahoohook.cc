--- src/hooks/yahoohook.cc.orig	Fri Oct  3 03:55:06 2003
+++ src/hooks/yahoohook.cc	Wed Oct  8 17:29:21 2003
@@ -556,7 +556,7 @@
 
 string yahoohook::decode(const string &text, bool utf) {
     if(utf)
-	return siconv(text, "utf8",
+	return siconv(text, "utf-8",
 	    conf.getrussian(proto) ? "koi8-u" : conf.getdefcharset());
 
     return rushtmlconv("wk", text);
