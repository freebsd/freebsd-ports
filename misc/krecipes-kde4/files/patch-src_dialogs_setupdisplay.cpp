Fix build with clang 6

src/dialogs/setupdisplay.cpp:567:41: error: reference to type 'const KFontChooser::DisplayFlags' (aka 'const QFlags<KFontChooser::DisplayFlag>') could not bind to an rvalue of type 'bool'
        if ( KFontDialog::getFont( item->font, false, view() ) == QDialog::Accepted ) {
                                               ^~~~~
/usr/local/include/kde4/kfontdialog.h:134:57: note: passing argument to parameter 'flags' here
                      const KFontChooser::DisplayFlags& flags =
                                                        ^

--- src/dialogs/setupdisplay.cpp.orig	2018-01-21 21:28:58 UTC
+++ src/dialogs/setupdisplay.cpp
@@ -564,7 +564,7 @@ void SetupDisplay::setShown( int id )
 void SetupDisplay::setFont()
 {
 	KreDisplayItem *item = *node_item_map->find( m_currNodeId );
-	if ( KFontDialog::getFont( item->font, false, view() ) == QDialog::Accepted ) {
+	if ( KFontDialog::getFont( item->font, KFontChooser::NoDisplayFlags, view() ) == QDialog::Accepted ) {
 		m_currentItem = item;
 		loadFont(m_currNodeId,item->font);
 		m_currentItem = 0;
