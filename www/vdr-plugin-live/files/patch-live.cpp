--- a/live.cpp
+++ b/live.cpp
@@ -46,10 +46,19 @@ bool Plugin::ProcessArgs(int argc, char 
 
 bool Plugin::Start(void)
 {
-	m_configDirectory = canonicalize_file_name(cPlugin::ConfigDirectory( PLUGIN_NAME_I18N ));
+#ifdef __FreeBSD__
+	char buf[PATH_MAX], buf2[PATH_MAX];
+
+	m_configDirectory = realpath(cPlugin::ConfigDirectory( PLUGIN_NAME_I18N ), buf);
+#if APIVERSNUM > 10729
+	m_resourceDirectory = realpath(cPlugin::ResourceDirectory( PLUGIN_NAME_I18N ), buf2);
+#endif
+#else
+ 	m_configDirectory = canonicalize_file_name(cPlugin::ConfigDirectory( PLUGIN_NAME_I18N ));
 #if APIVERSNUM > 10729
 	m_resourceDirectory = canonicalize_file_name(cPlugin::ResourceDirectory( PLUGIN_NAME_I18N ));
 #endif
+#endif
 
 #if VDRVERSNUM < 10507
 	RegisterI18n( vdrlive::Phrases );
