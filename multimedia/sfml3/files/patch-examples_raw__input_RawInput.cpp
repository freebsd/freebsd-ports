--- examples/raw_input/RawInput.cpp.orig	2026-08-25 01:39:32 UTC
+++ examples/raw_input/RawInput.cpp
@@ -19,7 +19,7 @@ int main()
     window.setVerticalSyncEnabled(true);
 
     // Open the application font
-    const sf::Font font("resources/tuffy.ttf");
+    const sf::Font font("%%DATADIR%%/tuffy.ttf");
 
     // Create the mouse position text
     sf::Text mousePosition(font, "", 20);
