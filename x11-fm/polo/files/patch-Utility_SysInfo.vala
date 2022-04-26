--- Utility/SysInfo.vala.orig	2018-08-12 04:41:58 UTC
+++ Utility/SysInfo.vala
@@ -50,7 +50,7 @@ public class SysInfo : GLib.Object {
 		string std_out, std_err;
 		exec_sync("uname -m", out std_out, out std_err);
 
-		if (std_out.replace("\n","").strip().down() == "x86_64"){
+		if (std_out.replace("\n","").contains("64")){
 			arch = 64;
 		}
 		else{
@@ -61,7 +61,7 @@ public class SysInfo : GLib.Object {
 	public void query_cpu_cores(){
 
 		string std_out, std_err;
-		exec_sync("grep -c ^processor /proc/cpuinfo", out std_out, out std_err);
+		exec_sync("sysctl -n hw.ncpu", out std_out, out std_err);
 
 		cpu_cores = int.parse(std_out);
 	}
@@ -74,9 +74,9 @@ public class SysInfo : GLib.Object {
 	public void query_memory(){
 
 		string std_out, std_err;
-		exec_script_sync("grep MemTotal /proc/meminfo | awk '{print $2}'", out std_out, out std_err);
+		exec_sync("sysctl -n hw.physmem", out std_out, out std_err);
 
-		mem_total_mb = (int) (int.parse(std_out) / 1024.0);
+		mem_total_mb = (int) (int.parse(std_out) / 1024.0 / 1024.0);
 	}
 
 	public void print(){
