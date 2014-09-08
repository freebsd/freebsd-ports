--- courier/cmlmfetch.C.orig	2009-11-08 18:14:47 UTC
+++ courier/cmlmfetch.C
@@ -334,7 +334,7 @@ int doindex(const char *n)
 			ack << std::setiosflags(std::ios::right)
 			    << std::setw(10)
 			    << msgs[i]
-			    << resetiosflags(std::ios::right) << " "
+			    << std::resetiosflags(std::ios::right) << " "
 			    << std::setw(0) << msginfo[i].msgsubj << std::endl;
 			ack << std::setiosflags(std::ios::right)
 			    << std::setw(10)
