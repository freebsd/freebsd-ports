--- a/live.cpp
+++ b/live.cpp
@@ -42,7 +42,13 @@ bool Plugin::ProcessArgs(int argc, char 
 
 bool Plugin::Start(void)
 {
+#ifdef __FreeBSD__
+	char buf[PATH_MAX];
+
+	m_configDirectory = realpath(cPlugin::ConfigDirectory( PLUGIN_NAME_I18N ), buf);
+#else
 	m_configDirectory = canonicalize_file_name(cPlugin::ConfigDirectory( PLUGIN_NAME_I18N ));
+#endif
 
 #if VDRVERSNUM < 10507
 	RegisterI18n( vdrlive::Phrases );
