--- src/support.cc.bak	Sat Nov  6 13:35:51 2004
+++ src/support.cc	Sat Nov  6 13:36:16 2004
@@ -111,7 +111,7 @@
 		// generic case
 		if ((cpos=chars.find(format.at(pos+1)))==std::string::npos)
 			continue;
-		result+=toinsert.at(cpos);
+		result+=toinsert[cpos];
 	}
 	if (prevpos<len)
 		result.append(format,prevpos,len-prevpos);
