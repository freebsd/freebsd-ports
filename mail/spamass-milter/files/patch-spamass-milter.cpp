--- spamass-milter.cpp	2006-03-23 22:41:36.000000000 +0100
+++ spamass-milter.cpp	2010-02-04 14:46:31.000000000 +0100
@@ -1002,9 +1002,9 @@
 
 		assassin->output((string)
 			"Received: from "+macro_s+" ("+macro__+")\r\n\t"+
-			"by "+macro_j+"("+macro_v+"/"+macro_Z+") with "+macro_r+" id "+macro_i+"\r\n\t"+
+			"by "+macro_j+" ("+macro_v+"/"+macro_Z+") with "+macro_r+" id "+macro_i+";\r\n\t"+
 			macro_b+"\r\n\t"+
-			"(envelope-from "+assassin->from()+"\r\n");
+			"(envelope-from "+assassin->from()+")\r\n");
 
 	} else
 		assassin->output((string)"X-Envelope-To: "+envrcpt[0]+"\r\n");
