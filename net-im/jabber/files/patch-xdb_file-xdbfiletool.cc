--- xdb_file/xdbfiletool.cc.orig	Fri Feb  9 11:46:12 2007
+++ xdb_file/xdbfiletool.cc	Fri Feb  9 11:55:35 2007
@@ -66,7 +66,11 @@
 
 int main(int argc, const char **argv) {
     char *host = NULL;
+#ifdef __FreeBSD__
+    const char *error = NULL;
+#else
     char *error = NULL;
+#endif
     char *cfgfile = CONFIG_DIR "/jabber.xml";
     char *basedir = NULL;
     char *do_get = NULL;
