--- ./devede_other.py.orig	2010-10-01 17:35:11.558220218 +0200
+++ ./devede_other.py	2010-10-01 17:35:51.631522099 +0200
@@ -233,7 +233,7 @@
 	
 	def convert_to_UTF8(self,infile_n,outfile_n,origin_format):
 		
-		command_line='iconv -f '+str(origin_format)+' -t UTF-8 "'+str(infile_n)+'" > "'+str(outfile_n)+'"'
+		command_line='iconv -f '+str(origin_format)+' -t UTF8 "'+str(infile_n)+'" > "'+str(outfile_n)+'"'
 		return self.launch_shell(command_line).wait()
 	
 	
