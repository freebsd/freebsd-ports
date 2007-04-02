===================================================================
RCS file: /cvsroot/linuxdcpp/linuxdcpp/client/Text.cpp,v
retrieving revision 1.15
retrieving revision 1.16
diff -u -r1.15 -r1.16
--- client/Text.cpp	2007/03/24 18:33:17	1.15
+++ client/Text.cpp	2007/03/28 00:03:12	1.16
@@ -25,6 +25,7 @@
 #ifndef _WIN32
 #include <errno.h>
 #include <iconv.h>
+#include <langinfo.h>
 
 #ifndef ICONV_CONST
  #define ICONV_CONST
@@ -38,12 +39,16 @@
 void Text::initialize() {
 	setlocale(LC_ALL, "");
 
+#ifdef _WIN32
 	char *ctype = setlocale(LC_CTYPE, NULL);
 	if(ctype) {
 		systemCharset = string(ctype);
 	} else {
 		dcdebug("Unable to determine the program's locale");
 	}
+#else
+	systemCharset = string(nl_langinfo(CODESET));
+#endif
 }
 
 int Text::utf8ToWc(const char* str, wchar_t& c) {
