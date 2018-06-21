--- src/main.cc.orig	2018-06-10 01:20:01 UTC
+++ src/main.cc
@@ -73,7 +73,7 @@ extern const float TWO_PI = 2 * PI;
 extern const float PI_BY_180 = PI / 180.;
 extern const int MILLION = 1000000;
 extern const char SPC = ' ';
-extern const string tokenizer::DEFAULT_DELIMITER (" ");
+const string tokenizer::DEFAULT_DELIMITER (" ");
 float widget::R = 0.980392, widget::G = 0.792157, widget::B = 0.509804; // default color for all widgets
 
 // for attack, decay and deltas [see keyboard-keyboard.cc, mondrian.cc, triggered_note.cc]
