--- examples/shader/Shader.cpp.orig	2026-08-25 01:39:40 UTC
+++ examples/shader/Shader.cpp
@@ -279,11 +279,11 @@ std::optional<Pixelate> tryLoadPixelate()
 std::optional<Pixelate> tryLoadPixelate()
 {
     sf::Texture texture;
-    if (!texture.loadFromFile("resources/background.jpg"))
+    if (!texture.loadFromFile("%%DATADIR%%/background.jpg"))
         return std::nullopt;
 
     sf::Shader shader;
-    if (!shader.loadFromFile("resources/pixelate.frag", sf::Shader::Type::Fragment))
+    if (!shader.loadFromFile("%%DATADIR%%/pixelate.frag", sf::Shader::Type::Fragment))
         return std::nullopt;
 
     return std::make_optional<Pixelate>(std::move(texture), std::move(shader));
@@ -292,7 +292,7 @@ std::optional<WaveBlur> tryLoadWaveBlur(const sf::Font
 std::optional<WaveBlur> tryLoadWaveBlur(const sf::Font& font)
 {
     sf::Shader shader;
-    if (!shader.loadFromFile("resources/wave.vert", "resources/blur.frag"))
+    if (!shader.loadFromFile("%%DATADIR%%/wave.vert", "%%DATADIR%%/blur.frag"))
         return std::nullopt;
 
     return std::make_optional<WaveBlur>(font, std::move(shader));
@@ -301,7 +301,7 @@ std::optional<StormBlink> tryLoadStormBlink()
 std::optional<StormBlink> tryLoadStormBlink()
 {
     sf::Shader shader;
-    if (!shader.loadFromFile("resources/storm.vert", "resources/blink.frag"))
+    if (!shader.loadFromFile("%%DATADIR%%/storm.vert", "%%DATADIR%%/blink.frag"))
         return std::nullopt;
 
     return std::make_optional<StormBlink>(std::move(shader));
@@ -318,21 +318,21 @@ std::optional<Edge> tryLoadEdge()
 
     // Load the background texture
     sf::Texture backgroundTexture;
-    if (!backgroundTexture.loadFromFile("resources/sfml.png"))
+    if (!backgroundTexture.loadFromFile("%%DATADIR%%/sfml.png"))
         return std::nullopt;
 
     backgroundTexture.setSmooth(true);
 
     // Load the entity texture
     sf::Texture entityTexture;
-    if (!entityTexture.loadFromFile("resources/devices.png"))
+    if (!entityTexture.loadFromFile("%%DATADIR%%/devices.png"))
         return std::nullopt;
 
     entityTexture.setSmooth(true);
 
     // Load the shader
     sf::Shader shader;
-    if (!shader.loadFromFile("resources/edge.frag", sf::Shader::Type::Fragment))
+    if (!shader.loadFromFile("%%DATADIR%%/edge.frag", sf::Shader::Type::Fragment))
         return std::nullopt;
 
     shader.setUniform("texture", sf::Shader::CurrentTexture);
@@ -348,14 +348,14 @@ std::optional<Geometry> tryLoadGeometry()
 
     // Load the logo texture
     sf::Texture logoTexture;
-    if (!logoTexture.loadFromFile("resources/logo.png"))
+    if (!logoTexture.loadFromFile("%%DATADIR%%/logo.png"))
         return std::nullopt;
 
     logoTexture.setSmooth(true);
 
     // Load the shader
     sf::Shader shader;
-    if (!shader.loadFromFile("resources/billboard.vert", "resources/billboard.geom", "resources/billboard.frag"))
+    if (!shader.loadFromFile("%%DATADIR%%/billboard.vert", "%%DATADIR%%/billboard.geom", "%%DATADIR%%/billboard.frag"))
         return std::nullopt;
 
     shader.setUniform("texture", sf::Shader::CurrentTexture);
@@ -389,7 +389,7 @@ int main()
     window.setVerticalSyncEnabled(true);
 
     // Open the application font
-    const sf::Font font("resources/tuffy.ttf");
+    const sf::Font font("%%DATADIR%%/tuffy.ttf");
 
     // Create the effects
     std::optional pixelateEffect   = tryLoadPixelate();
@@ -413,7 +413,7 @@ int main()
     std::size_t current = 0;
 
     // Create the messages background
-    const sf::Texture textBackgroundTexture("resources/text-background.png");
+    const sf::Texture textBackgroundTexture("%%DATADIR%%/text-background.png");
     sf::Sprite        textBackground(textBackgroundTexture);
     textBackground.setPosition({0.f, 520.f});
     textBackground.setColor(sf::Color(255, 255, 255, 200));
