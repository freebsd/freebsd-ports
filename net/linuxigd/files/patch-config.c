--- config.c.orig	Sat Jun 16 20:37:40 2007
+++ config.c	Sat Jun 16 20:39:05 2007
@@ -43,6 +43,12 @@
   return 0;
 }
 
+size_t strnlen(const char *s, size_t maxlen)
+{
+  int len = strlen(s);
+  return (len < maxlen) ? len : maxlen;
+}
+
 int parseConfigFile(globals_p vars)
 {
     FILE *conf_file;
@@ -50,11 +56,8 @@
     
     regex_t re_comment;
     regex_t re_empty_row;
-    regex_t re_iptables_location;
+    regex_t re_ipnat_location;
     regex_t re_debug_mode;
-    regex_t re_insert_forward_rules_yes;
-    regex_t re_forward_chain_name;
-    regex_t re_prerouting_chain_name;
     regex_t re_upstream_bitrate;
     regex_t re_downstream_bitrate;
     regex_t re_duration;
@@ -63,10 +66,7 @@
 
     // Make sure all vars are 0 or \0 terminated
     vars->debug = 0;
-    vars->forwardRules = 0;
-    strcpy(vars->iptables,"");
-    strcpy(vars->forwardChainName,"");
-    strcpy(vars->preroutingChainName,"");
+    strcpy(vars->ipnat,"");
     strcpy(vars->upstreamBitrate,"");
     strcpy(vars->downstreamBitrate,"");
     vars->duration = DEFAULT_DURATION;
@@ -78,14 +78,11 @@
     regcomp(&re_empty_row,"^[[:blank:]]*\r?\n$",REG_EXTENDED);
 
     // Regexps to match configuration file settings
-    regcomp(&re_iptables_location,"iptables_location[[:blank:]]*=[[:blank:]]*\"([^\"]+)\"",REG_EXTENDED);
+    regcomp(&re_ipnat_location,"ipnat_location[[:blank:]]*=[[:blank:]]*\"([^\"]+)\"",REG_EXTENDED);
     regcomp(&re_debug_mode,"debug_mode[[:blank:]]*=[[:blank:]]*([[:digit:]])",REG_EXTENDED);
-    regcomp(&re_insert_forward_rules_yes,"insert_forward_rules[[:blank:]]*=[[:blank:]]*yes",REG_ICASE);
-    regcomp(&re_forward_chain_name,"forward_chain_name[[:blank:]]*=[[:blank:]]*([[:alpha:]_-]+)",REG_EXTENDED);
-    regcomp(&re_prerouting_chain_name,"prerouting_chain_name[[:blank:]]*=[[:blank:]]([[:alpha:]_-]+)",REG_EXTENDED);
     regcomp(&re_upstream_bitrate,"upstream_bitrate[[:blank:]]*=[[:blank:]]*([[:digit:]]+)",REG_EXTENDED);
     regcomp(&re_downstream_bitrate,"downstream_bitrate[[:blank:]]*=[[:blank:]]*([[:digit:]]+)",REG_EXTENDED);
-    regcomp(&re_duration,"duration[[:blank:]]*=[[:blank:]]*(@?)([[:digit:]]+|[[:digit:]]+{2}:[[:digit:]]+{2})",REG_EXTENDED);
+    regcomp(&re_duration,"duration[[:blank:]]*=[[:blank:]]*(@?)([[:digit:]]+|[[:digit:]]{2}:[[:digit:]]{2})",REG_EXTENDED);
     regcomp(&re_desc_doc,"description_document_name[[:blank:]]*=[[:blank:]]*([[:alpha:].]{1,20})",REG_EXTENDED);
     regcomp(&re_xml_path,"xml_document_path[[:blank:]]*=[[:blank:]]*([[:alpha:]_/.]{1,50})",REG_EXTENDED);
 
@@ -99,21 +96,10 @@
 	    if ( (0 != regexec(&re_comment,line,0,NULL,0)  )  && 
 		 (0 != regexec(&re_empty_row,line,0,NULL,0))  )
 	    {
-		// Chec if iptables_location
-		if (regexec(&re_iptables_location,line,NMATCH,submatch,0) == 0)
-		{
-		  getConfigOptionArgument(vars->iptables, PATH_LEN, line, submatch);
-		}
-		
-		// Check is insert_forward_rules
-		else if (regexec(&re_insert_forward_rules_yes,line,0,NULL,0) == 0)
-		{
-		    vars->forwardRules = 1;
-		}
-		// Check forward_chain_name
-		else if (regexec(&re_forward_chain_name,line,NMATCH,submatch,0) == 0)
+		// Chec if ipnat_location
+		if (regexec(&re_ipnat_location,line,NMATCH,submatch,0) == 0)
 		{
-		  getConfigOptionArgument(vars->forwardChainName, CHAIN_NAME_LEN, line, submatch);
+		  getConfigOptionArgument(vars->ipnat, PATH_LEN, line, submatch);
 		}
 		else if (regexec(&re_debug_mode,line,NMATCH,submatch,0) == 0)
 		{
@@ -121,10 +107,6 @@
 		  getConfigOptionArgument(tmp,sizeof(tmp),line,submatch);
 		  vars->debug = atoi(tmp);
 		}
-		else if (regexec(&re_prerouting_chain_name,line,NMATCH,submatch,0) == 0)
-		{
-		  getConfigOptionArgument(vars->preroutingChainName, CHAIN_NAME_LEN, line, submatch);
-		}
 		else if (regexec(&re_upstream_bitrate,line,NMATCH,submatch,0) == 0)
 		{
 		  getConfigOptionArgument(vars->upstreamBitrate, BITRATE_LEN, line, submatch);
@@ -156,27 +138,13 @@
     }
     regfree(&re_comment);
     regfree(&re_empty_row);
-    regfree(&re_iptables_location);
+    regfree(&re_ipnat_location);
     regfree(&re_debug_mode);	
-    regfree(&re_insert_forward_rules_yes);	
-    regfree(&re_forward_chain_name);
-    regfree(&re_prerouting_chain_name);
     regfree(&re_upstream_bitrate);
     regfree(&re_downstream_bitrate);
     regfree(&re_duration);
     regfree(&re_desc_doc);
     regfree(&re_xml_path);
-    // Set default values for options not found in config file
-    if (strnlen(vars->forwardChainName, CHAIN_NAME_LEN) == 0)
-    {
-	// No forward chain name was set in conf file, set it to default
-	snprintf(vars->forwardChainName, CHAIN_NAME_LEN, IPTABLES_DEFAULT_FORWARD_CHAIN);
-    }
-    if (strnlen(vars->preroutingChainName, CHAIN_NAME_LEN) == 0)
-    {
-	// No prerouting chain name was set in conf file, set it to default
-	snprintf(vars->preroutingChainName, CHAIN_NAME_LEN, IPTABLES_DEFAULT_PREROUTING_CHAIN);
-    }
     if (strnlen(vars->upstreamBitrate, BITRATE_LEN) == 0)
     {
 	// No upstream_bitrate was found in the conf file, set it to default
@@ -195,8 +163,8 @@
     {
 	snprintf(vars->xmlPath, PATH_LEN, XML_PATH_DEFAULT);
     }
-    if (strnlen(vars->iptables, PATH_LEN) == 0) {
-	// Can't find the iptables executable, return -1 to 
+    if (strnlen(vars->ipnat, PATH_LEN) == 0) {
+	// Can't find the ipnat executable, return -1 to 
 	// indicate en error
 	return -1;
     }
