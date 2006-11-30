--- panoptis/timeslot.cpp.orig	Tue Nov 28 13:58:22 2006
+++ panoptis/timeslot.cpp	Tue Nov 28 13:58:33 2006
@@ -109,7 +109,7 @@
 				continue;
 
 			// Create a new Distribution object
-			IfPair *ifpair = new IfPair((uint16_t)input, (uint16_t)output);
+			IfPair *ifpair = new IfPair((uint16_t&)input, (uint16_t&)output);
 			if (!ifpair){
 				perror("new");
 				exit(errno);
