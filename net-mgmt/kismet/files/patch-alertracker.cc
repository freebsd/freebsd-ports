--- alertracker.cc.orig	2010-09-03 10:57:56.000000000 -0400
+++ alertracker.cc	2010-09-03 11:36:42.000000000 -0400
@@ -397,6 +397,7 @@
 						  &(rec->limit_burst)) < 0) {
 			_MSG("Invalid alert line in config file: " + clines[x], MSGFLAG_FATAL);
 			globalreg->fatal_condition = 1;
+			delete rec;
 			return -1;
 		}
 
