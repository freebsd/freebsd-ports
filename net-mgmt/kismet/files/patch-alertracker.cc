--- alertracker.cc.orig	2016-07-02 18:06:10 UTC
+++ alertracker.cc
@@ -405,6 +405,7 @@ int Alertracker::ParseAlertConfig(ConfigFile *in_conf)
 						  &(rec->limit_burst)) < 0) {
 			_MSG("Invalid alert line in config file: " + clines[x], MSGFLAG_FATAL);
 			globalreg->fatal_condition = 1;
+			delete rec;
 			return -1;
 		}
 
