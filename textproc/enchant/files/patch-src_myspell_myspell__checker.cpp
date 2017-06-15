--- src/myspell/myspell_checker.cpp.orig	2010-04-01 20:53:37 UTC
+++ src/myspell/myspell_checker.cpp
@@ -427,7 +427,7 @@ MySpellChecker::requestDictionary(const 
 	if(myspell == NULL){
 		return false;
 	}
-	char *enc = myspell->get_dic_encoding();
+	const char *enc = myspell->get_dic_encoding();
 
 	m_translate_in = g_iconv_open(enc, "UTF-8");
 	m_translate_out = g_iconv_open("UTF-8", enc);
