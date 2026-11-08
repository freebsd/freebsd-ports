--- examples/island/Island.cpp.orig	2026-08-25 01:38:23 UTC
+++ examples/island/Island.cpp
@@ -430,7 +430,7 @@ int main()
     sf::RenderWindow window(sf::VideoMode(windowSize), "SFML Island", sf::Style::Titlebar | sf::Style::Close);
     window.setVerticalSyncEnabled(true);
 
-    const sf::Font font("resources/tuffy.ttf");
+    const sf::Font font("%%DATADIR%%/tuffy.ttf");
 
     // Create all of our graphics resources
     sf::Text         hudText(font);
@@ -459,7 +459,7 @@ int main()
     {
         statusText.setString("Shaders and/or Vertex Buffers Unsupported");
     }
-    else if (!terrainShader.loadFromFile("resources/terrain.vert", "resources/terrain.frag"))
+    else if (!terrainShader.loadFromFile("%%DATADIR%%/terrain.vert", "%%DATADIR%%/terrain.frag"))
     {
         statusText.setString("Failed to load shader program");
     }
