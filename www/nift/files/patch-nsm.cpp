--- nsm.cpp.orig	2024-01-13 12:54:06 UTC
+++ nsm.cpp
@@ -1452,7 +1452,7 @@ int main(int argc, const char* argv[])
 		else if(cmd == "watch")
 		{
 			//ensures correct number of parameters given
-			if(noParams < 2 && noParams > 5)
+			if(noParams < 2 || noParams > 5)
 				return parError(noParams, argv, "2-5");
 
 			WatchList wl;
