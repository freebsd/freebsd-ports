--- src/Applet.cc.bak	Mon May  3 22:05:00 2004
+++ src/Applet.cc	Mon May  3 22:05:19 2004
@@ -108,9 +108,7 @@
 		else if (_owner->_sound_type == SOUND_FILE) {
 			std::stringstream s;
 			s << _owner->_sound_volume/100.0;
-			std::string command = "play \"" + _owner->_sound_file + std::string ("\" -v ");
-			command += s.str();
-			command += " &";
+			std::string command = "esdplay \"" + _owner->_sound_file + std::string ("\" &");
 			system (command.c_str());
 		}
 	}
