--- src/msgmle.cpp.orig	2018-11-02 00:15:39 UTC
+++ src/msgmle.cpp
@@ -257,12 +257,36 @@ bool ChatEdit::checkSpellingGloballyEnabled()
 	return (SpellChecker::instance()->available() && PsiOptions::instance()->getOption("options.ui.spell-check.enabled").toBool());
 }
 
+QStringList ChatEdit::checkSpellingActiveLanguages()
+{
+	return PsiOptions::instance()->getOption("options.ui.spell-check.langs").toString().split(QRegExp("\\s+|,|\\:"), QString::SkipEmptyParts);
+}
+
+unsigned ChatEdit::checkSpellingMaxSuggestions()
+{
+	return PsiOptions::instance()->getOption("options.ui.spell-check.maxsugs").toString().toInt();
+}
+
 void ChatEdit::setCheckSpelling(bool b)
 {
 	check_spelling_ = b;
 	if (check_spelling_) {
 		if (!spellhighlighter_)
 			spellhighlighter_ = new SpellHighlighter(document());
+		all_langs_ = SpellChecker::instance()->getAllLanguages();
+		langs_ = checkSpellingActiveLanguages();
+		// No langs specified in options?
+		if (langs_.isEmpty()) {
+			QString env_lang(getenv("LANG"));
+			// Let's try to use the language specified in environment ...
+			if (!env_lang.isEmpty() && all_langs_.contains(env_lang))
+				langs_.append(env_lang);
+			else // ... still no luck? Will use all available languages then.
+				langs_ = all_langs_;
+		}
+		SpellChecker::instance()->setActiveLanguages(langs_);
+		// If zero, means no limit (empty option also translates to zero).
+		max_sugs_ = checkSpellingMaxSuggestions();
 	}
 	else {
 		delete spellhighlighter_;
@@ -335,19 +359,34 @@ void ChatEdit::contextMenuEvent(QContextMenuEvent *e)
 		tc.movePosition(QTextCursor::EndOfWord, QTextCursor::KeepAnchor);
 		QString selected_word = tc.selectedText();
 		if (!selected_word.isEmpty() && !QRegExp("\\d+").exactMatch(selected_word) && !SpellChecker::instance()->isCorrect(selected_word)) {
-			QList<QString> suggestions = SpellChecker::instance()->suggestions(selected_word);
-			if (!suggestions.isEmpty() || SpellChecker::instance()->writable()) {
-				QMenu spell_menu;
+			QMenu spell_menu;
+			foreach (QString lang, langs_) {
+				QList<QString> suggestions = SpellChecker::instance()->suggestions(selected_word, lang, max_sugs_);
 				if (!suggestions.isEmpty()) {
+					QAction* lang_name = spell_menu.addAction(tr("Language") + ": " + lang);
+					lang_name->setDisabled(true);
 					foreach(QString suggestion, suggestions) {
 						QAction* act_suggestion = spell_menu.addAction(suggestion);
 						connect(act_suggestion,SIGNAL(triggered()),SLOT(applySuggestion()));
 					}
 					spell_menu.addSeparator();
 				}
+			}
+			if (!spell_menu.isEmpty() || SpellChecker::instance()->writable() || !all_langs_.isEmpty()) {
 				if (SpellChecker::instance()->writable()) {
-					QAction* act_add = spell_menu.addAction(tr("Add to dictionary"));
-					connect(act_add,SIGNAL(triggered()),SLOT(addToDictionary()));
+					foreach (QString lang, langs_) {
+						QAction* act_add = spell_menu.addAction(tr("Add to dictionary") + ": " + lang);
+						act_add->setData(lang);
+						connect(act_add,SIGNAL(triggered()),SLOT(addToDictionary()));
+					}
+					spell_menu.addSeparator();
+					foreach (QString lang, all_langs_) {
+						QAction* act_lang_sel = spell_menu.addAction(tr("Use language") + ": " + lang);
+						act_lang_sel->setCheckable(true);
+						act_lang_sel->setChecked(langs_.contains(lang));
+						act_lang_sel->setData(lang);
+						connect(act_lang_sel,SIGNAL(triggered()),SLOT(changedUseLang()));
+					}
 				}
 				spell_menu.exec(QCursor::pos());
 				e->accept();
@@ -397,18 +436,35 @@ void ChatEdit::applySuggestion()
  */
 void ChatEdit::addToDictionary()
 {
+	QAction* action = static_cast<QAction*>(sender());
 	QTextCursor	tc = cursorForPosition(last_click_);
 	int current_position = textCursor().position();
 
 	// Get the selected word
 	tc.movePosition(QTextCursor::StartOfWord, QTextCursor::MoveAnchor);
 	tc.movePosition(QTextCursor::EndOfWord, QTextCursor::KeepAnchor);
-	SpellChecker::instance()->add(tc.selectedText());
+	SpellChecker::instance()->add(tc.selectedText(), action->data().toString());
 
 	// Put the cursor where it belongs
 	tc.clearSelection();
 	tc.setPosition(current_position);
 	setTextCursor(tc);
+
+	spellhighlighter_->rehighlight();
+}
+
+void ChatEdit::changedUseLang()
+{
+	QAction* action = static_cast<QAction*>(sender());
+	QString lang = action->data().toString();
+
+	if (langs_.contains(lang))
+		langs_.removeAt(langs_.indexOf(lang));
+	else
+		langs_.append(lang);
+
+	SpellChecker::instance()->setActiveLanguages(langs_);
+	spellhighlighter_->rehighlight();
 }
 
 void ChatEdit::optionsChanged()
