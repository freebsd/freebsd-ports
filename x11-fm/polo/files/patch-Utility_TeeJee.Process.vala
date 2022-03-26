--- Utility/TeeJee.Process.vala.orig	2018-08-12 04:41:58 UTC
+++ Utility/TeeJee.Process.vala
@@ -192,7 +192,7 @@ namespace TeeJee.ProcessHelper{
 		 * Returns the script file path */
 
 		string sh = "";
-		sh += "#!/bin/bash\n";
+		sh += "#!/bin/sh\n";
 		sh += "\n";
 		if (force_locale){
 			sh += "LANG=C\n";
@@ -216,7 +216,7 @@ namespace TeeJee.ProcessHelper{
 		if (admin_mode){
 			
 			sh = "";
-			sh += "#!/bin/bash\n";
+			sh += "#!/bin/sh\n";
 			sh += "pkexec env DISPLAY=$DISPLAY XAUTHORITY=$XAUTHORITY";
 			sh += " '%s'\n".printf(escape_single_quote(sh_path));
 			sh += "if [ -f status ]; then exit $(cat status); else exit 0; fi\n";
@@ -293,7 +293,7 @@ namespace TeeJee.ProcessHelper{
 		/* Get the process ID for a process with given name */
 
 		string std_out, std_err;
-		exec_sync("pidof \"%s\"".printf(name), out std_out, out std_err);
+		exec_sync("pgrep -d'' \"%s\"".printf(name), out std_out, out std_err);
 		
 		if (std_out != null){
 			string[] arr = std_out.split ("\n");
