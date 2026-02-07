--- src/msgmle.h.orig	2018-11-02 00:15:39 UTC
+++ src/msgmle.h
@@ -54,6 +54,8 @@ class ChatEdit : public QTextEdit (public)
 	void setFont(const QFont &);
 
 	static bool checkSpellingGloballyEnabled();
+	static QStringList checkSpellingActiveLanguages();
+	static unsigned checkSpellingMaxSuggestions();
 	void setCheckSpelling(bool);
 	XMPP::HTMLElement toHTMLElement();
 	bool isCorrection() { return correction; }
@@ -71,6 +73,7 @@ public slots:
 protected slots:
  	void applySuggestion();
  	void addToDictionary();
+	void changedUseLang();
 	void optionsChanged();
 	void showHistoryMessageNext();
 	void showHistoryMessagePrev();
@@ -91,6 +94,8 @@ protected slots: (protected)
 private:
 	QWidget	*dialog_;
 	bool check_spelling_;
+	QList<QString> langs_, all_langs_;
+	unsigned max_sugs_;
 	SpellHighlighter* spellhighlighter_;
 	QPoint last_click_;
 	int previous_position_;
