--- par.cc	2004-05-29 16:00:06.000000000 -0700
+++ par.cc	2005-10-20 20:25:31.000000000 -0700
@@ -65,7 +65,9 @@
 
 void LocalParFiles::addfrompath_par2(const string &path, t_nocase_map *nocase_map){
 	c_regex_r parfile_re("^(.+)\\.par2(\\.[0-9]+\\.[0-9]+)?$", REG_EXTENDED|REG_ICASE);
-	c_regex_r dupefile_re("^(.+)\\.[0-9]+\\.[0-9]+$");
+	c_regex_r dupefile1_re("^(.+)\\.[0-9]+$");
+	c_regex_r dupefile2_re("^(.+)\\.[0-9]+\\.[0-9]+$");
+	c_regex_r dupefile3_re("^(.+)\\.[0-9]+\\.[0-9]+\\.[0-9]+$");
 	static c_regex_r par2pxxre("^(.*).vol[0-9]+\\+[0-9]+$", REG_EXTENDED|REG_ICASE);
 	c_regex_subs rsubs;
 	DIR *dir=opendir(path.c_str());
@@ -89,7 +91,11 @@
 		}
 		if (nocase_map) {
 			if (strcmp(de->d_name,"..")!=0 && strcmp(de->d_name,".")!=0){
-				if (!dupefile_re.match(de->d_name, &rsubs)) //check for downloaded dupe files, and add them under their original name.
+				if (!dupefile1_re.match(de->d_name, &rsubs)) //check for downloaded dupe files, and add them under their original name.
+					add_to_nocase_map(nocase_map, rsubs.subs(1), de->d_name);
+				if (!dupefile2_re.match(de->d_name, &rsubs)) //check for downloaded dupe files, and add them under their original name.
+					add_to_nocase_map(nocase_map, rsubs.subs(1), de->d_name);
+				if (!dupefile3_re.match(de->d_name, &rsubs)) //check for downloaded dupe files, and add them under their original name.
 					add_to_nocase_map(nocase_map, rsubs.subs(1), de->d_name);
 				add_to_nocase_map(nocase_map, de->d_name, de->d_name);
 			}
