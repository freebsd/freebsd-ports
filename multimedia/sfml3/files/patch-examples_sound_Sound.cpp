--- examples/sound/Sound.cpp.orig	2026-08-25 01:39:50 UTC
+++ examples/sound/Sound.cpp
@@ -15,7 +15,7 @@ void playSound()
 void playSound()
 {
     // Load a sound buffer from a wav file
-    const sf::SoundBuffer buffer("resources/killdeer.wav");
+    const sf::SoundBuffer buffer("%%DATADIR%%/killdeer.wav");
 
     // Display sound information
     std::cout << "killdeer.wav:" << '\n'
@@ -48,7 +48,7 @@ void playMusic(const std::filesystem::path& filename)
 void playMusic(const std::filesystem::path& filename)
 {
     // Load an ogg music file
-    sf::Music music("resources" / filename);
+    sf::Music music("%%DATADIR%%" / filename);
 
     // Display music information
     std::cout << filename << ":" << '\n'
