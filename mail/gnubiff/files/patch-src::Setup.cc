--- src/Setup.cc.bak	Mon May  3 22:05:03 2004
+++ src/Setup.cc	Mon May  3 22:05:14 2004
@@ -765,9 +765,7 @@
 		gchar *data = (gchar *) g_object_get_data (G_OBJECT(get("soundfile")), "_file_");
 		std::stringstream s;
 		s << gfloat(gtk_range_get_value (GTK_RANGE (get ("volume"))))/100.0;
-		std::string command = "play \"" + std::string (data) + std::string ("\" -v ");
-		command += s.str();
-		command += " &";
+		std::string command = "esdplay \"" + std::string (data) + std::string ("\" &");
 		system (command.c_str());
 	}
 }
