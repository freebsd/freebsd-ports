--- scribus/plugins/tools/hunspellcheck/hunspelldict.cpp.orig	2012-11-20 22:49:14 UTC
+++ scribus/plugins/tools/hunspellcheck/hunspelldict.cpp
@@ -19,7 +19,7 @@ HunspellDict::HunspellDict(const QString
 	m_hunspell = new Hunspell(affPath.toLocal8Bit().constData(), dictPath.toLocal8Bit().constData());
 	if (m_hunspell)
 	{
-		char* dictEncoding = m_hunspell->get_dic_encoding();
+		const char* dictEncoding = m_hunspell->get_dic_encoding();
 		if (dictEncoding)
 			encoding = QString::fromLatin1(dictEncoding);
 	}
