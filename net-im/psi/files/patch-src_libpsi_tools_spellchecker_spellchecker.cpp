--- src/libpsi/tools/spellchecker/spellchecker.cpp.orig	2018-11-02 00:37:04 UTC
+++ src/libpsi/tools/spellchecker/spellchecker.cpp
@@ -48,7 +48,7 @@ SpellChecker* SpellChecker::instance()
 #elif defined(HAVE_ASPELL)
 		instance_ = new ASpellChecker();
 #elif defined(HAVE_HUNSPELL)
-		instance_ = new HunspellChecker();
+		instance_ = new HunSpellChecker();
 #else
 		instance_ = new SpellChecker();
 #endif
@@ -80,14 +80,23 @@ bool SpellChecker::isCorrect(const QString&)
 	return true;
 }
 
-QList<QString> SpellChecker::suggestions(const QString&)
+QList<QString> SpellChecker::suggestions(const QString&, const QString&, unsigned)
 {
 	return QList<QString>();
 }
 
-bool SpellChecker::add(const QString&)
+bool SpellChecker::add(const QString&, const QString&)
 {
 	return false;
+}
+
+QList<QString> SpellChecker::getAllLanguages() const
+{
+	return QList<QString>();
+}
+
+void SpellChecker::setActiveLanguages(const QList<QString>&)
+{
 }
 
 SpellChecker* SpellChecker::instance_ = NULL;
