--- examples/event_handling/EventHandling.cpp.orig	2026-08-25 01:35:09 UTC
+++ examples/event_handling/EventHandling.cpp
@@ -316,7 +316,7 @@ class Application (private)
     // Member data
     ////////////////////////////////////////////////////////////
     sf::RenderWindow m_window{sf::VideoMode({800u, 600u}), "SFML Event Handling", sf::Style::Titlebar | sf::Style::Close};
-    const sf::Font           m_font{"resources/tuffy.ttf"};
+    const sf::Font           m_font{"%%DATADIR%%/tuffy.ttf"};
     sf::Text                 m_logText{m_font, "", 20};
     sf::Text                 m_handlerText{m_font, "Current Handler: Classic", 24};
     sf::Text                 m_instructions{m_font, "Press Enter to change handler type", 24};
