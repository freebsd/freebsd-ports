--- src/options/opt_advanced.cpp.orig	2018-11-02 00:15:39 UTC
+++ src/options/opt_advanced.cpp
@@ -45,6 +45,8 @@ QWidget *OptionsTabAdvanced::widget()
 #endif
 
 	d->ck_spell->setEnabled(SpellChecker::instance()->available());
+	d->le_spellLangs->setEnabled(SpellChecker::instance()->available());
+	d->le_spellMaxSugs->setEnabled(SpellChecker::instance()->available());
 
 	d->ck_messageevents->setWhatsThis(
 		tr("Enables the sending and requesting of message events such as "
@@ -60,6 +62,12 @@ QWidget *OptionsTabAdvanced::widget()
 		tr("Enables remote controlling your client from other locations"));
 	d->ck_spell->setWhatsThis(
 		tr("Check this option if you want your spelling to be checked"));
+	d->le_spellLangs->setWhatsThis(
+		tr("List here all languages you want your spell checker to use"
+		" when checking your spelling."));
+	d->le_spellMaxSugs->setWhatsThis(
+		tr("Maximal number of suggestion words per language you want to see"
+		" in context menu when the word is misspelled."));
 	d->ck_contactsMessageFormatting->setWhatsThis(
 		tr("If enabled, Psi will display incoming messages formatted in the style specified by the contact"));
 	d->ck_autocopy->setWhatsThis(
@@ -99,6 +107,10 @@ QWidget *OptionsTabAdvanced::widget()
 	connect(d->ck_messageevents,SIGNAL(toggled(bool)),d->ck_sendComposingEvents,SLOT(setEnabled(bool)));
 	d->ck_inactiveevents->setEnabled(d->ck_messageevents->isChecked());
 	d->ck_sendComposingEvents->setEnabled(d->ck_messageevents->isChecked());
+	connect(d->ck_spell,SIGNAL(toggled(bool)),d->le_spellLangs,SLOT(setEnabled(bool)));
+	connect(d->ck_spell,SIGNAL(toggled(bool)),d->le_spellMaxSugs,SLOT(setEnabled(bool)));
+	d->le_spellLangs->setEnabled(d->ck_spell->isChecked());
+	d->le_spellMaxSugs->setEnabled(d->ck_spell->isChecked());
 
 	return w;
 }
@@ -116,8 +128,11 @@ void OptionsTabAdvanced::applyOptions()
 	PsiOptions::instance()->setOption("options.ui.notifications.send-receipts", d->ck_sendReceipts->isChecked());
 	PsiOptions::instance()->setOption("options.messages.dont-send-composing-events", d->ck_sendComposingEvents->isChecked());
 	PsiOptions::instance()->setOption("options.external-control.adhoc-remote-control.enable", d->ck_rc->isChecked());
-	if ( SpellChecker::instance()->available() )
+	if ( SpellChecker::instance()->available() ) {
 		PsiOptions::instance()->setOption("options.ui.spell-check.enabled",d->ck_spell->isChecked());
+		PsiOptions::instance()->setOption("options.ui.spell-check.langs", d->le_spellLangs->text());
+		PsiOptions::instance()->setOption("options.ui.spell-check.maxsugs", d->le_spellMaxSugs->text());
+	}
 	PsiOptions::instance()->setOption("options.html.chat.render", d->ck_contactsMessageFormatting->isChecked());
 	PsiOptions::instance()->setOption("options.ui.automatically-copy-selected-text", d->ck_autocopy->isChecked());
 	PsiOptions::instance()->setOption("options.ui.contactlist.use-single-click", d->ck_singleclick->isChecked());
@@ -145,10 +160,15 @@ void OptionsTabAdvanced::restoreOptions()
 	d->ck_sendReceipts->setChecked( PsiOptions::instance()->getOption("options.ui.notifications.send-receipts").toBool() );
 	d->ck_sendComposingEvents->setChecked( PsiOptions::instance()->getOption("options.messages.dont-send-composing-events").toBool() );
 	d->ck_rc->setChecked( PsiOptions::instance()->getOption("options.external-control.adhoc-remote-control.enable").toBool() );
-	if ( !SpellChecker::instance()->available() )
+	if ( !SpellChecker::instance()->available() ) {
 		d->ck_spell->setChecked(false);
-	else
+		d->le_spellLangs->setText("");
+		d->le_spellMaxSugs->setText("");
+	} else {
 		d->ck_spell->setChecked(PsiOptions::instance()->getOption("options.ui.spell-check.enabled").toBool());
+		d->le_spellLangs->setText(PsiOptions::instance()->getOption("options.ui.spell-check.langs").toString());
+		d->le_spellMaxSugs->setText(PsiOptions::instance()->getOption("options.ui.spell-check.maxsugs").toString());
+	}
 	d->ck_contactsMessageFormatting->setChecked(PsiOptions::instance()->getOption("options.html.chat.render").toBool());
 	d->ck_autocopy->setChecked( PsiOptions::instance()->getOption("options.ui.automatically-copy-selected-text").toBool() );
 	d->ck_singleclick->setChecked( PsiOptions::instance()->getOption("options.ui.contactlist.use-single-click").toBool() );
