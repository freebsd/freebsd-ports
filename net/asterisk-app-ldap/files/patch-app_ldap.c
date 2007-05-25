--- app_ldap.c.orig	Tue Apr 17 14:14:56 2007
+++ app_ldap.c	Tue Apr 17 17:06:42 2007
@@ -9,6 +9,8 @@
  *
  */
 
+/*#define LDAP_DEPRECATED 1*/
+
 #include <stdlib.h>
 #include <stdio.h>
 #include <string.h>
@@ -33,36 +35,43 @@
 #include <ldap.h>
 
 #define AST_MODULE "app_notify"
-
 #define LDAP_CONFIG "ldap.conf"
+#define SIZELIMIT 2048
 
-int ldap_lookup(const char *host, int port, int version, int timeout, const char *user, const char *pass, const char *base, const char *scope, const char *filter, const char *attribute, char *result);
-int strconvert(const char *incharset, const char *outcharset,
-#ifdef __Darwin__
-               const char *in,
-#else
-               char *in,
-#endif
-               char *out);
+char *replace_ast_vars(struct ast_channel *chan, const char *string);
+LDAP* ldap_open_connection(const char *host, int port, int version);
+int ldap_bind_connection(LDAP *ld, const char *user, const char *pass);
+int ldap_search_in_connection(LDAP *ld, const char *base, const char *scope, const char *filter, const char *attribute, char *result);
+int ldap_lookup(const char *host, int port, int version, int timeout, const char *user, const char *pass, 
+		const char *base, const char *scope, const char *filter, const char *attribute, char *result);
+int strconvert(const char *incharset, const char *outcharset, const char *in, char *out);
+char *strtrim (char *string);
 
 static char *app = "LDAPget";
 static char *synopsis = "Retrieve a value from an ldap directory";
 
 static char *descrip =
-  "  LDAPget(varname=config-file-section/key): Retrieves a value from an LDAP\n"
-  "directory and stores it in the given variable. Always returns 0.  If the\n"
-  "requested key is not found, jumps to priority n+101 if available.\n";
+"  LDAPget(varname=config-file-section/key): Retrieves a value from an LDAP\n"
+"directory and stores it in the given variable. Always returns 0.  If the\n"
+"requested key is not found, jumps to priority n+101 if available.\n";
+
 
 static int ldap_exec (struct ast_channel *chan, void *data)
 {
   int arglen;
   struct ast_module_user *u;
   char *argv, *varname, *config, *keys = NULL, *key = NULL, *tail = NULL;
+#ifdef __FreeBSD__
+  char result[SIZELIMIT+1];
+#else
   char result[2048];
+#endif
+  memset(result,0,sizeof(result));
+  
   char *result_conv;
   struct ast_config *cfg;
 
-  int port = LDAP_PORT, version = LDAP_VERSION2, timeout = 10;
+  int port = LDAP_PORT, version = LDAP_VERSION3, timeout = 10;
   const char *temp, *host, *user, *pass, *_base, *scope, *_filter, *attribute;
   char *convert, *convert_from = NULL, *convert_to = NULL, *filter, *base;
 
@@ -127,8 +136,8 @@ static int ldap_exec (struct ast_channel
   if (!(scope = ast_variable_retrieve(cfg, config, "scope"))) {
     scope = "sub";
   }
-  if(!(_base = ast_variable_retrieve(cfg, config, "base"))) {
-    _base = "";
+  if(!(_base = ast_variable_retrieve(cfg, config, "base"))){
+     _base = "";
   }
   if(!(_filter = ast_variable_retrieve(cfg, config, "filter"))) {
     _filter = "(&(objectClass=*)(telephoneNumber=${CALLERID(number)}))";
@@ -136,7 +145,7 @@ static int ldap_exec (struct ast_channel
   if(!(attribute = ast_variable_retrieve(cfg, config, "attribute"))) {
     attribute = "cn";
   }
-	
+
   if((temp = ast_variable_retrieve(cfg, config, "convert"))) {
     convert = ast_strdupa(temp);
     if(strchr(convert, ',')) {
@@ -146,7 +155,7 @@ static int ldap_exec (struct ast_channel
       ast_log(LOG_WARNING, "syntax error: convert = <source-charset>,<destination charset>\n");
     }
   }
-	
+
   if(option_verbose > 3)
     ast_verbose (VERBOSE_PREFIX_4 "LDAPget: ldap://%s/%s?%s?%s?%s\n", host, _base, attribute, scope, _filter);
 
@@ -160,12 +169,16 @@ static int ldap_exec (struct ast_channel
   memset(base, 0, slen);
   pbx_substitute_variables_helper(chan, _base, base, slen);
 
+//  ast_log(LOG_WARNING, "LDAPget: filter: after replace_ast_vars in main: -%s-\n", filter);
+  if(option_verbose > 3)
+    ast_verbose (VERBOSE_PREFIX_4 "LDAPget: replaced string: %s\n", filter);
+
   if(keys && strstr(filter, "%s") != NULL) {
     filter = (char *)ast_realloc(filter, (strlen(filter)+strlen(keys)+1)*sizeof(char));
     while((key = strsep(&keys, "|")) != NULL) {
       if((tail = strstr(filter, "%s")) != NULL) {
-				memmove(tail+strlen(key), tail+2, strlen(tail+2)+1);
-				memcpy(tail, key, strlen(key));
+	 memmove(tail+strlen(key), tail+2, strlen(tail+2)+1);
+	 memcpy(tail, key, strlen(key));
       }
     }
   }
@@ -173,86 +186,146 @@ static int ldap_exec (struct ast_channel
   if(option_verbose > 2)
     ast_verbose (VERBOSE_PREFIX_3 "LDAPget: ldap://%s/%s?%s?%s?%s\n", host, base, attribute, scope, filter);
 
+//  ast_log(LOG_WARNING, "LDAPget: filter before ldap_lookup: -%s-\n", filter);
   if(ldap_lookup(host, port, version, timeout, user, pass, base, scope, filter, attribute, result)) {
 
-    if(convert_from) {
+    if(convert_from && strlen(result)>0) {
       if(option_verbose > 2)
-				ast_verbose(VERBOSE_PREFIX_3 "LDAPget: convert: %s -> %s\n", convert_from, convert_to);
+	ast_verbose(VERBOSE_PREFIX_3 "LDAPget: convert: %s -> %s\n", convert_from, convert_to);
       result_conv = alloca(strlen(result) * 2);
-      strconvert(convert_from, convert_to, result, result_conv);
+      strconvert(convert_from, convert_to, (const char*)result, result_conv);
       strcpy(result, result_conv);
     }
-
-
+		
     if(strcmp("CALLERIDNAME", varname)==0 || strcmp("CALLERID(name)", varname)==0) {
 #ifdef CHANNEL_HAS_CID
+       if(option_verbose > 2)
+	  ast_verbose(VERBOSE_PREFIX_3 "LDAPget: set callerid with HAS_CID ast_set_callerid\n");
       ast_set_callerid(chan, NULL, result, NULL);
 #else
       char *cidnum, *cidname, newcid[512] = "";
       ast_callerid_parse(chan->callerid, &cidname, &cidnum);
       snprintf(newcid, sizeof(newcid), "\"%s\" <%s>", result, cidnum);
+      if(option_verbose > 2)
+	 ast_verbose(VERBOSE_PREFIX_3 "LDAPget: set callerid with NO HAS_CID ast_set_callerid\n");
       ast_set_callerid(chan, newcid, 0);
 #endif
     } else {
       pbx_builtin_setvar_helper(chan, varname, result);
     }
-		if(option_verbose > 2)
-			ast_verbose (VERBOSE_PREFIX_3 "LDAPget: set %s='%s'\n", varname, result);
+    if(option_verbose > 2)
+       ast_verbose (VERBOSE_PREFIX_3 "LDAPget: set %s='%s'\n", varname, result);
+		
   } else {
     /* Send the call to n+101 priority, where n is the current priority */
     if(ast_exists_extension (chan, chan->context, chan->exten, chan->priority + 101, 
 #ifdef CHANNEL_HAS_CID
-														 chan->cid.cid_num
+			     chan->cid.cid_num
 #else
-														 chan->callerid
+			     chan->callerid
 #endif
-														 ))
+			     ))
       chan->priority += 100;
   }
-	
 #ifdef NEW_CONFIG
   ast_config_destroy(cfg);
 #else
   ast_destroy(cfg);
 #endif
-	
   ast_module_user_remove(u);
+  
   return 0;
 }
 
-
-int ldap_lookup(const char *host, int port, int version, int timeout, const char *user, const char *pass, 
-		const char *base, const char *scope, const char *filter, const char *attribute, char *result) {
-  char *attrs[] = { NULL };
-  char **values;
-  LDAP *ld;
-  LDAPMessage *res, *entry;
-  int ret, ldap_scope = LDAP_SCOPE_SUBTREE;
-
-  ld = ldap_init(host, port);
-  if(!ld) {
-    ast_log(LOG_WARNING, "LDAPget: unable to initialize ldap connection to %s:%d\n", host, port);
+LDAP* ldap_open_connection(const char *host, int port, int version)
+{
+   LDAP *ld=NULL;
+   LDAPURLDesc url;
+   char *ldapuri=NULL;
+   int ret;
+//   int ldap_debug=0xffff;
+   int ldap_debug=0;
+   
+   // Open connection to the LDAP server
+   memset(&url, 0, sizeof(url));
+   url.lud_host=host;
+   url.lud_port=port;
+   url.lud_scope=LDAP_SCOPE_DEFAULT;
+   url.lud_scheme="ldap";
+   
+   ldapuri=ldap_url_desc2str(&url);
+   (void) ldap_set_option(NULL, LDAP_OPT_DEBUG_LEVEL, &ldap_debug);
+   
+   if(option_verbose > 2)
+      ast_verbose(VERBOSE_PREFIX_3 "LDAPget: open connection to %s with version: %d\n", ldapuri, version);
+   ret = ldap_initialize(&ld, ldapuri);
+  if(ret != LDAP_SUCCESS) {
+    ast_log(LOG_WARNING, "LDAPget: unable to initialize ldap connection to %s(%d)\n", ldap_err2string(ret),ret);
     return 0;
   }
+  
+  // Disable option referrals
+  if(ldap_set_option(ld, LDAP_OPT_REFERRALS, LDAP_OPT_OFF) != LDAP_OPT_SUCCESS)
+  {
+     ast_log(LOG_WARNING, "LDAPget: unable to disable LDAP_OPT_REFERRALS\n");
+     return 0;
+  }
 
-  ldap_set_option(ld, LDAP_OPT_TIMELIMIT, &timeout);
-  ldap_set_option(ld, LDAP_OPT_PROTOCOL_VERSION, &version);
-
-  if(user) {
-    if (option_verbose > 2)
-      ast_verbose(VERBOSE_PREFIX_3 "LDAPget: bind to %s as %s\n", host, user);
-    ret = ldap_simple_bind_s(ld, user, pass);
-  } else {
-    if (option_verbose > 2)
-      ast_verbose(VERBOSE_PREFIX_3 "LDAPget: bind to %s anonymously\n", host);
-    ret = ldap_simple_bind_s(ld, NULL, NULL);
-  }
-  if(ret) {
-    ast_log(LOG_WARNING, "LDAPget: bind failed: %s\n", ldap_err2string(ret));
-    ldap_unbind(ld);
-    return 0;
+  // set protocol to version
+  if(ldap_set_option(ld, LDAP_OPT_PROTOCOL_VERSION, &version)!= LDAP_OPT_SUCCESS)
+  {
+     ast_log(LOG_WARNING, "LDAPget: unable to set LDAP_OPT_PROTOCOL_VERSION %d\n",version);
+     return 0;
   }
+  return ld;
+}
 
+int ldap_bind_connection(LDAP *ld, const char *user, const char *pass)
+{
+   int rc;
+   char *sasl_secprops=NULL;
+   
+   if( sasl_secprops != NULL)
+   {
+      rc= ldap_set_option( ld, LDAP_OPT_X_SASL_SECPROPS, (void *) sasl_secprops);
+      if(rc != LDAP_OPT_SUCCESS)
+      {
+	 ast_log(LOG_WARNING, "LDAPget: Could not set LDAP_OPT_X_SASL_SECPROPS: %s\n", sasl_secprops);
+	 return 0;
+      }
+   }
+   if(option_verbose > 2)
+      ast_verbose(VERBOSE_PREFIX_3 "LDAPget: bind as %s\n", user);
+
+   struct berval passwd= {0, NULL};
+   passwd.bv_val=ber_strdup(pass);
+   passwd.bv_len=strlen(passwd.bv_val);
+   
+   rc=ldap_sasl_bind_s(ld, user, NULL, &passwd, NULL, NULL, NULL);
+   
+   if(rc != LDAP_SUCCESS)
+   {
+	 ast_log(LOG_WARNING, "LDAPget: ldap_sasl_interactive_bind_s failed: %s (%d)\n", ldap_err2string(rc),rc);
+	 return 0;
+   }
+   
+   return 1;
+}
+
+
+int ldap_search_in_connection(LDAP *ld, const char *base, const char *scope, const char *filter, const char *attribute, char *result)
+{
+  char *attrs[] = { NULL };
+  int ret, ldap_scope = LDAP_SCOPE_SUBTREE;
+  LDAPMessage *msg, *res;
+  int num_entries=0;
+  int msgtype;
+  char *dn, *a;
+  BerElement *ber=NULL;
+  struct berval **vals;
+  struct berval val;
+  
+//  ast_log(LOG_WARNING, "LDAPget: filter start of ldap_search_in_connections: -%s-\n", filter);
   if(strncmp(scope,"sub",3)==0) {
     ldap_scope = LDAP_SCOPE_SUBTREE;
   } else if(strncmp(scope,"base",4)==0) {
@@ -261,82 +334,146 @@ int ldap_lookup(const char *host, int po
     ldap_scope = LDAP_SCOPE_ONELEVEL;
   }
 
-  ret = ldap_search_s(ld, base, ldap_scope, filter, attrs, 0, &res);
-  if(ret) {
-    ast_log(LOG_WARNING, "LDAPget: search failed: %s\n", ldap_err2string(ret));
-    if(version==2)
-      ast_log(LOG_WARNING, "LDAPget: you may try version=3 in your asterisk ldap.conf file.\n");
+  if(option_verbose > 2)
+     ast_verbose(VERBOSE_PREFIX_3 "LDAPget: send search command to LDAP server\n");
+  ret = ldap_search_ext_s(ld, base, ldap_scope, filter, attrs, 0, NULL, NULL, NULL, SIZELIMIT, &res);
+  if(ret != LDAP_SUCCESS) {
+    ast_log(LOG_WARNING, "LDAPget: search failed: %s (%d)\n", ldap_err2string(ret),ret);
+    ast_log(LOG_WARNING, "LDAPget: filter: %s\n", filter);
+// XXXX need to check
     ldap_msgfree(res);
-    ldap_unbind(ld);
+    ldap_unbind_ext_s(ld,NULL,NULL);
+    ast_log(LOG_WARNING, "LDAPget: search failed resourceses released, cancel search\n");
     return 0;
   }
+  num_entries=ldap_count_entries(ld, res);
+  msg=ldap_first_message(ld, res);
+  msgtype=ldap_msgtype(msg);
 
-  entry = ldap_first_entry(ld, res);
-  if(!entry) {
-    if(option_verbose > 2)
-      ast_verbose (VERBOSE_PREFIX_3 "LDAPget: Value not found in directory.\n");
-    ldap_msgfree(res);
-    ldap_unbind(ld);
-    return 0;
-  }
+  if(option_verbose > 2)
+     ast_verbose(VERBOSE_PREFIX_3 "LDAPget: found %d entry in LDAP server\n", num_entries);
 
-  values = ldap_get_values(ld, entry, attribute);
-  if(values && values[0]) {
-    memset(result, 0, strlen(values[0]));
-    strncpy(result, values[0], strlen(values[0]));
-    result[strlen(values[0])] = '\0';
-    if (option_verbose > 2)
-      ast_verbose(VERBOSE_PREFIX_3 "LDAPget: %s=%s\n", attribute, result);
-  } else {
-    if (option_verbose > 2)
-      ast_verbose (VERBOSE_PREFIX_3 "LDAPget: %s not found.\n", attribute);
-    ldap_msgfree(res);
-    ldap_unbind(ld);
-    return 0;
+  for ( msg = ldap_first_message( ld, res ); msg != NULL; msg = ldap_next_message( ld, msg ) ) {
+     /* Determine what type of message was sent from the server. */
+     
+     msgtype = ldap_msgtype( msg );
+     switch( msgtype ) {
+	/* If the result was an entry found by the search, get and print the
+	   attributes and values of the entry. */
+	case LDAP_RES_SEARCH_ENTRY:
+	   /* Get and print the DN of the entry. */
+	   if(option_verbose > 2)
+	      ast_verbose(VERBOSE_PREFIX_3 "Found a LDAP_RES_SEARCH_ENTRY\n");
+	   ret=ldap_get_dn_ber(ld,msg,&ber,&val);
+	   
+	   if (( dn = ldap_get_dn( ld, res )) != NULL ) {
+	      ldap_memfree( dn );
+	   }
+	   /* Iterate through each attribute in the entry. */
+	   for ( a = ldap_first_attribute( ld, res, &ber );
+		 a != NULL; a = ldap_next_attribute( ld, res, ber ) ) {
+	      /* Get the searched attribute and value */
+	      if(!strcmp(a,attribute))
+	      {
+		 
+		 if (( vals = ldap_get_values_len( ld, res, a )) != NULL ) {
+		    val=*vals[0];
+		    // remove space at end of string
+		    if(val.bv_val[val.bv_len-1]==' ')
+		    {
+		       val.bv_len--;
+//		       val.bv_val[val.bv_len]=NULL;
+		    }
+		    if(option_verbose > 2)
+		       ast_verbose(VERBOSE_PREFIX_3 "Found <%s>: <%s>\n", a, val.bv_val);
+		    memcpy(result,val.bv_val,val.bv_len);
+		    ldap_value_free_len( vals );
+		    ldap_memfree(a);
+		    break;
+		 }
+	      }
+	      ldap_memfree( a );
+	   }
+	   if ( ber != NULL ) {
+	      ber_free( ber, 0 );
+	   }
+	   break;
+	case LDAP_RES_SEARCH_REFERENCE:
+	   if(option_verbose > 2)
+	      ast_verbose(VERBOSE_PREFIX_3 "LDAP_RES_SEARCH_REFERENCE\n");
+	   break;
+	case LDAP_RES_SEARCH_RESULT:
+	   if(option_verbose > 2)
+	      ast_verbose(VERBOSE_PREFIX_3 "LDAPRES_SERCH_RESULT\n");
+	   break;
+	default:
+	   break;
+     }
   }
-  ldap_value_free(values);
-
-  ldap_msgfree(res);
-  ldap_unbind_s(ld);
-  
   return 1;
 }
 
-int strconvert(const char *incharset, const char *outcharset,
-#ifdef __Darwin__
-               const char *in,
-#else
-               char *in,
-#endif
-               char *out) {
+int ldap_lookup(const char *host, int port, int version, int timeout, const char *user, const char *pass, 
+		const char *base, const char *scope, const char *filter, const char *attribute, char *result) {
+   LDAP *ld=NULL;
+   
+//   ast_log(LOG_WARNING, "LDAPget: filter in ldap_lookup: -%s-\n", filter);
+   // open connection to LDAP server
+   if(option_verbose > 2)
+      ast_verbose(VERBOSE_PREFIX_3 "LDAPget: Initialize connection to LDAP server\n");
+   ld=ldap_open_connection(host, port, version);
+   if(ld==0)
+      return 0;
+   
+   // authenticate to the LDAP-Server
+   if(option_verbose > 2)
+      ast_verbose(VERBOSE_PREFIX_3 "LDAPget: bind to LDAP server\n");
+   if(ldap_bind_connection(ld, user, pass) == 0)
+      return 0;
+   
+   // Search in the LDAP directory
+   if(option_verbose > 2)
+      ast_verbose(VERBOSE_PREFIX_3 "LDAPget: search attribute %s in LDAP directory\n", attribute);
+   if(ldap_search_in_connection(ld, base, scope, filter, attribute, result)==0)
+      return 0;
+   
+   // Close connection to the LDAP server
+   int err = ldap_set_option(ld, LDAP_OPT_SERVER_CONTROLS, NULL);
+   if(err != LDAP_OPT_SUCCESS)
+   {
+      ast_log(LOG_WARNING, "LDAPget: Could not unset controls\n");
+   }
+   
+   ldap_unbind_ext_s(ld, NULL, NULL);
+   return 1;
+}
+
+
+int strconvert(const char *incharset, const char *outcharset, const char *in, char *out) 
+{
   iconv_t cd;
-  size_t incount = strlen(in), outcount = strlen(in)*2, result;
-  cd = iconv_open(outcharset, incharset);
-  if(cd == (iconv_t) -1) {
-    ast_log(LOG_ERROR, "conversion from '%s' to '%s' not available. type 'iconv -l' in a shell to list the supported charsets.\n", incharset, outcharset);
-    memcpy(out, in, strlen(in)+1);
+  size_t incount, outcount, result;
+  incount = outcount = strlen(in) * 2;
+  if((cd = iconv_open(outcharset, incharset)) == (iconv_t)-1) {
+    if(errno == EINVAL) ast_log(LOG_DEBUG, "conversion from '%s' to '%s' not available", incharset, outcharset);
+    *out = L'\0';
     return -1;
   }
+  if(option_verbose > 2)
+     ast_verbose(VERBOSE_PREFIX_3 "LDAPget: convert: now with icon string: %s\n", in);
   result = iconv(cd, &in, &incount, &out, &outcount);
-  if(result == (size_t)-1) {
-    if(errno == E2BIG) {
-      ast_log(LOG_WARNING, "Iconv: output buffer too small.\n");
-    } else if(errno == EILSEQ) {
-      ast_log(LOG_WARNING,  "Iconv: illegal character.\n");
-    } else if(errno == EINVAL) {
-      ast_log(LOG_WARNING,  "Iconv: incomplete character sequence.\n");
-    } else {
-      ast_log(LOG_WARNING,  "Iconv: error.\n");
-    }
-  }
+  if(option_verbose > 2)
+     ast_verbose(VERBOSE_PREFIX_3 "LDAPget: convert: close inconv %d\n",result);
   iconv_close(cd);
-  *out = '\0';
+  if(option_verbose > 2)
+     ast_verbose(VERBOSE_PREFIX_3 "LDAPget: result with icon\n");
+  out[strlen(out)] = '\0';
   return 1;
 }
 
 static int load_module(void)
 {
-  return ast_register_application(app, ldap_exec, synopsis, descrip);
+   return ast_register_application(app, ldap_exec, synopsis, descrip);
 }
 
 static int unload_module(void)
