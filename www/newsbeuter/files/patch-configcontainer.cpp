--- src/configcontainer.cpp.orig	2007-06-06 15:23:55.000000000 +0200
+++ src/configcontainer.cpp	2007-08-05 14:19:34.000000000 +0200
@@ -85,43 +85,13 @@
 			return AHS_OK;	
 
 		case configdata::STR:
+		case configdata::PATH:
 			if (params.size() < 1) {
 				return AHS_TOO_FEW_PARAMS;
 			}
 			cfgdata.value = params[0];
 			return AHS_OK;	
 
-		case configdata::PATH: {
-			if (params.size() < 1) {
-				return AHS_TOO_FEW_PARAMS;
-			}
-
-			// a path config option is a bit more difficult to handle, because we need to replace 
-			// a possible "~/" at the beginning of the string with the user's home directory.
-
-			const char * homedir;
-			std::string filepath;
-
-			if (!(homedir = ::getenv("HOME"))) {
-				struct passwd * spw = ::getpwuid(::getuid());
-				if (spw) {
-						homedir = spw->pw_dir;
-				} else {
-						homedir = "";
-				}
-			}
-
-			if (strcmp(homedir,"")!=0 && params[0].substr(0,2) == "~/") {
-				filepath.append(homedir);
-				filepath.append(1,'/');
-				filepath.append(params[0].substr(2,params[0].length()-2));
-			} else {
-				filepath.append(params[0]);
-			}
-
-			cfgdata.value = filepath;
-			return AHS_OK;
-		}
 		default:
 			// should not happen
 			return AHS_INVALID_COMMAND;	
@@ -150,7 +120,37 @@
 }
 
 std::string configcontainer::get_configvalue(const std::string& key) {
-	return config_data[key].value;
+	std::string retval = config_data[key].value;
+	if (config_data[key].type == configdata::PATH) {
+		const char * homedir;
+		std::string filepath;
+
+		if (!(homedir = ::getenv("HOME"))) {
+			struct passwd * spw = ::getpwuid(::getuid());
+			if (spw) {
+					homedir = spw->pw_dir;
+			} else {
+					homedir = "";
+			}
+		}
+
+		if (strcmp(homedir,"")!=0) {
+			if (retval == "~") {
+				filepath.append(homedir);
+			} else if (retval.substr(0,2) == "~/") {
+				filepath.append(homedir);
+				filepath.append(1,'/');
+				filepath.append(retval.substr(2,retval.length()-2));
+			} else {
+				filepath.append(retval);
+			}
+		} else {
+			filepath.append(retval);
+		}
+		retval = filepath;
+	}
+
+	return retval;
 }
 
 int configcontainer::get_configvalue_as_int(const std::string& key) {
