--- httpd.orig	Fri Oct 14 14:44:45 2005
+++ httpd.c	Fri Oct 14 14:47:03 2005
@@ -963,13 +963,12 @@
 }
 static void handledirlist(const char*origurl) {
   DIR*dir;
-  unsigned int nl=str_len(origurl);
+  unsigned int nl;
   const char*nurl=origurl;
   url=(char*)origurl;
   while (nurl[0]=='/') ++nurl;
-  if (nurl<=origurl) return;
+  if (nurl==origurl) return;
   nl=str_len(nurl);
-  if (nurl[nl-1]!='/') return;
   if (!stat(nl?nurl:".",&st) && (S_ISDIR(st.st_mode)) && ((st.st_mode&S_IRWXO)==5)) {
     if (nl) chdir(nurl);
     if (dir=opendir(".")) {
