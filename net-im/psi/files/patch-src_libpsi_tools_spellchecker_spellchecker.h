--- src/libpsi/tools/spellchecker/spellchecker.h.orig	2018-11-02 00:37:04 UTC
+++ src/libpsi/tools/spellchecker/spellchecker.h
@@ -37,12 +37,11 @@ class SpellChecker : public QObject (public)
 	static SpellChecker* instance();
 	virtual bool available() const;
 	virtual bool writable() const;
-	virtual QList<QString> suggestions(const QString&);
+	virtual QList<QString> suggestions(const QString& word, const QString& lang, unsigned max_sugs);
 	virtual bool isCorrect(const QString&);
-	virtual bool add(const QString&);
-
-	virtual void setActiveLanguages(const QList<QString>& ) {}
-	virtual QList<QString> getAllLanguages() const { return QList<QString>(); }
+	virtual bool add(const QString& word, const QString& lang);
+	virtual QList<QString> getAllLanguages() const;
+	virtual void setActiveLanguages(const QList<QString>&);
 
 protected:
 	SpellChecker();
