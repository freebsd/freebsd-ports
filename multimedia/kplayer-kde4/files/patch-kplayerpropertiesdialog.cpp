--- kplayer/kplayerpropertiesdialog.cpp.orig	Sat Oct 16 02:14:58 2004
+++ kplayer/kplayerpropertiesdialog.cpp	Sat Oct 16 02:13:17 2004
@@ -153,7 +153,7 @@
     config -> deleteEntry ("Properties Dialog Page");
   else
     config -> writeEntry ("Properties Dialog Page", name);
-  setHelp (name.isEmpty() ? "properties" : "properties-" + name);
+  setHelp (name.isEmpty() ? QString::fromLatin1("properties") : "properties-" + name);
 }
 
 void KPlayerPropertiesDialog::slotOk (void)
@@ -191,8 +191,8 @@
   c_name -> setText (m_properties -> name());
   c_playlist -> setCurrentItem (m_properties -> playlistOption());
   c_length -> setText (timeString (m_properties -> length()));
-  c_original_width -> setText (m_properties -> originalSize().isEmpty() ? "" : QString::number (m_properties -> originalSize().width()));
-  c_original_height -> setText (m_properties -> originalSize().isEmpty() ? "" : QString::number (m_properties -> originalSize().height()));
+  c_original_width -> setText (m_properties -> originalSize().isEmpty() ? QString::fromLatin1("") : QString::number (m_properties -> originalSize().width()));
+  c_original_height -> setText (m_properties -> originalSize().isEmpty() ? QString::fromLatin1("") : QString::number (m_properties -> originalSize().height()));
   c_display_size -> setCurrentItem (m_properties -> displaySizeOption());
   displaySizeChanged (c_display_size -> currentItem());
   c_maintain_aspect -> setCurrentItem (m_properties -> maintainAspectOption() + 1);
@@ -266,7 +266,7 @@
 
 void KPlayerPropertiesSubtitles::autoloadChanged (int option)
 {
-  c_url -> setText (option < 2 || m_properties -> subtitleUrl().isEmpty() ? ""
+  c_url -> setText (option < 2 || m_properties -> subtitleUrl().isEmpty() ? QString::fromLatin1("")
     : m_properties -> subtitleUrl().isLocalFile() ? m_properties -> subtitleUrl().path()
     : m_properties -> subtitleUrl().url());
   c_url -> setEnabled (option == 2);
@@ -274,7 +274,7 @@
 
 void KPlayerPropertiesSubtitles::positionChanged (int option)
 {
-  c_position -> setText (option > 0 ? QString::number (m_properties -> subtitlePositionValue()) : "");
+  c_position -> setText (option > 0 ? QString::number (m_properties -> subtitlePositionValue()) : QString::fromLatin1(""));
   c_position -> setEnabled (option > 0);
   if ( option > 0 && sender() )
   {
@@ -285,7 +285,7 @@
 
 void KPlayerPropertiesSubtitles::delayChanged (int option)
 {
-  c_delay -> setText (option > 0 ? QString::number (m_properties -> subtitleDelayValue()) : "");
+  c_delay -> setText (option > 0 ? QString::number (m_properties -> subtitleDelayValue()) : QString::fromLatin1(""));
   c_delay -> setEnabled (option > 0);
   if ( option > 0 && sender() )
   {
@@ -348,7 +348,7 @@
 
 void KPlayerPropertiesAudio::volumeChanged (int option)
 {
-  c_volume -> setText (option > 0 ? QString::number (m_properties -> volumeValue()) : "");
+  c_volume -> setText (option > 0 ? QString::number (m_properties -> volumeValue()) : QString::fromLatin1(""));
   c_volume -> setEnabled (option > 0);
   if ( option > 0 && sender() )
   {
@@ -359,7 +359,7 @@
 
 void KPlayerPropertiesAudio::delayChanged (int option)
 {
-  c_delay -> setText (option > 0 ? QString::number (m_properties -> audioDelayValue()) : "");
+  c_delay -> setText (option > 0 ? QString::number (m_properties -> audioDelayValue()) : QString::fromLatin1(""));
   c_delay -> setEnabled (option > 0);
   if ( option > 0 && sender() )
   {
@@ -441,7 +441,7 @@
 
 void KPlayerPropertiesVideo::contrastChanged (int option)
 {
-  c_contrast -> setText (option > 0 ? QString::number (m_properties -> contrastValue()) : "");
+  c_contrast -> setText (option > 0 ? QString::number (m_properties -> contrastValue()) : QString::fromLatin1(""));
   c_contrast -> setEnabled (option > 0);
   if ( option > 0 && sender() )
   {
@@ -452,7 +452,7 @@
 
 void KPlayerPropertiesVideo::brightnessChanged (int option)
 {
-  c_brightness -> setText (option > 0 ? QString::number (m_properties -> brightnessValue()) : "");
+  c_brightness -> setText (option > 0 ? QString::number (m_properties -> brightnessValue()) : QString::fromLatin1(""));
   c_brightness -> setEnabled (option > 0);
   if ( option > 0 && sender() )
   {
@@ -463,7 +463,7 @@
 
 void KPlayerPropertiesVideo::hueChanged (int option)
 {
-  c_hue -> setText (option > 0 ? QString::number (m_properties -> hueValue()) : "");
+  c_hue -> setText (option > 0 ? QString::number (m_properties -> hueValue()) : QString::fromLatin1(""));
   c_hue -> setEnabled (option > 0);
   if ( option > 0 && sender() )
   {
@@ -474,7 +474,7 @@
 
 void KPlayerPropertiesVideo::saturationChanged (int option)
 {
-  c_saturation -> setText (option > 0 ? QString::number (m_properties -> saturationValue()) : "");
+  c_saturation -> setText (option > 0 ? QString::number (m_properties -> saturationValue()) : QString::fromLatin1(""));
   c_saturation -> setEnabled (option > 0);
   if ( option > 0 && sender() )
   {
@@ -524,7 +524,7 @@
 
 void KPlayerPropertiesAdvanced::commandLineChanged (int option)
 {
-  c_command_line -> setText (option > 0 ? m_properties -> commandLineValue() : "");
+  c_command_line -> setText (option > 0 ? m_properties -> commandLineValue() : QString::fromLatin1(""));
   c_command_line -> setEnabled (option > 0);
   if ( option > 0 && sender() )
   {
