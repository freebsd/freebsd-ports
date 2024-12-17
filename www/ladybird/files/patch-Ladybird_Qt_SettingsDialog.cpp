While not offically deprecated until Qt 6.9, use of the
QCheckBox::stateChanged() signal fails with -Werror due to the
deprecation warnings added in Qt 6.8. This signal has been replaced
by QCheckBox::checkStateChanged().

--- Ladybird/Qt/SettingsDialog.cpp.orig	2024-05-05 05:45:42 UTC
+++ Ladybird/Qt/SettingsDialog.cpp
@@ -99,12 +99,20 @@ void SettingsDialog::setup_search_engines()
     m_autocomplete_engine_dropdown->setMenu(autocomplete_engine_menu);
     m_autocomplete_engine_dropdown->setEnabled(Settings::the()->enable_autocomplete());
 
+#if (QT_VERSION > QT_VERSION_CHECK(6, 7, 0))
+    connect(m_enable_search, &QCheckBox::checkStateChanged, this, [&](int state) {
+#else
     connect(m_enable_search, &QCheckBox::stateChanged, this, [&](int state) {
+#endif
         Settings::the()->set_enable_search(state == Qt::Checked);
         m_search_engine_dropdown->setEnabled(state == Qt::Checked);
     });
 
+#if (QT_VERSION > QT_VERSION_CHECK(6, 7, 0))
+    connect(m_enable_autocomplete, &QCheckBox::checkStateChanged, this, [&](int state) {
+#else
     connect(m_enable_autocomplete, &QCheckBox::stateChanged, this, [&](int state) {
+#endif
         Settings::the()->set_enable_autocomplete(state == Qt::Checked);
         m_autocomplete_engine_dropdown->setEnabled(state == Qt::Checked);
     });
