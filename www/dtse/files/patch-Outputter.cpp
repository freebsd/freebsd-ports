--- ./Outputter.cpp.orig	2008-08-23 04:00:12.000000000 -0700
+++ ./Outputter.cpp	2011-12-30 17:37:16.000000000 -0800
@@ -459,8 +459,8 @@
 
 		if (condition)
 		{
-			line.erase(start, strlen(tag));
-			line.erase(finish - strlen(tag), 9);
+			line.erase(start, std::strlen(tag));
+			line.erase(finish - std::strlen(tag), 9);
 
 			begin = finish - strlen(tag) - 9;
 		}
