--- choqok/config/plugins/choqokpluginconfig.cpp.orig	2020-02-05 11:49:13 UTC
+++ choqok/config/plugins/choqokpluginconfig.cpp
@@ -46,8 +46,7 @@ ChoqokPluginConfig::ChoqokPluginConfig(QWidget *parent
     mainLayout->setMargin(0);
     mainLayout->addWidget(m_pluginSelector);
 
-    connect(m_pluginSelector, &KPluginSelector::changed, this,
-            (void (KCModule::*)())&KCModule::changed);
+    connect(m_pluginSelector, &KPluginSelector::changed, this, &ChoqokPluginConfig::markAsChanged);
     connect(m_pluginSelector, &KPluginSelector::configCommitted,
             this, &ChoqokPluginConfig::reparseConfiguration);
 
