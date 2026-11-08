--- examples/joystick/Joystick.cpp.orig	2026-08-25 01:38:49 UTC
+++ examples/joystick/Joystick.cpp
@@ -94,7 +94,7 @@ int main()
     window.setVerticalSyncEnabled(true);
 
     // Open the text font
-    const sf::Font font("resources/tuffy.ttf");
+    const sf::Font font("%%DATADIR%%/tuffy.ttf");
 
     // Set up our string conversion parameters
     sstr.precision(2);
