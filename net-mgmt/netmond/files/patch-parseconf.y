--- parseconf.y.orig	Tue Aug 26 10:53:30 2003
+++ parseconf.y	Thu Dec 28 13:31:06 2006
@@ -13,6 +13,7 @@
 #endif
 
 #include <sys/types.h>
+#include <sys/limits.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
 #include <stdio.h>
@@ -117,6 +118,7 @@
 	first_save = NULL;
 
 	global_var_list = 0;
+	config.compatibility_flag = 1;
 }
 
 static char *
@@ -197,11 +199,37 @@
 	BGP_AS *bgp;
 	ENV_MON *env;
 	char *cp, buf[1024];
+	struct	passwd *pwentry;
+	struct	group  *grentry;
 
 	if (!config.rootdir) {
 		report(LOG_ERR, "%s: rootdir unspecified", config_file);
 		return NULL;
 	}
+	compatibility_flag = config.compatibility_flag;
+	if (!config.srcaddress)
+    		bzero(&config.ip_srcaddr, sizeof(struct in_addr));
+	if (!config.ns_address)
+    		bzero(&config.ns_ip_addr, sizeof(struct in_addr));
+	if (!config.trap_address)
+    		bzero(&config.trap_ip_addr, sizeof(struct in_addr));
+		
+	if(!config.username) {
+	    config.username = strdup(USERNAME);
+	    if ((pwentry = getpwnam(USERNAME)) == (struct passwd *) NULL) {
+		report(LOG_ERR, "Bad default username: %s.",config.username);
+		return NULL;
+	    }
+	    config.uid = pwentry->pw_uid;
+	}
+	if(!config.groupname) {
+	    config.groupname = strdup(GROUPNAME);
+	    if ((grentry = getgrnam(GROUPNAME)) == (struct group *) NULL) {
+		report(LOG_ERR, "Bad default groupname: %s.",config.groupname);
+		return NULL;
+	    }
+	    config.gid = (gid_t)grentry->gr_gid;
+	}
 	if (config.polling) {
 		if (!config.timeout)
 			config.timeout = TIMEOUT_DEFAULT;
@@ -273,6 +301,7 @@
 
 		for (service = target->service; service; service = service->next) {
 			service->ip_addr = target->ip_addr;
+			service->ip_srcaddr = target->ip_srcaddr;
 			service->parent = target;
 
 			(void)strcpy(cp, "/");
@@ -329,6 +358,8 @@
 	METHOD *method;
 	CHATSCRIPT *cs;
 	REFERENCE *ref;
+	char *buf;
+	ssize_t buf_len;
 
 	/* sanity check */
 	if (!chain || !item) {
@@ -362,6 +393,16 @@
 			yyerror("Out of memory");
 			return 0;
 		}
+		buf_len =  strlen(method->name)+4 ;
+		buf = malloc( buf_len );
+		if (buf) 
+		    snprintf(buf,buf_len,"%s.ok",method->name);
+		if (!buf || !add_var(&curr->var_list, buf)) {
+			yyerror("Out of memory");
+			return 0;
+		}
+		free(buf);
+		
 		/* bind variable references */
 		for (cs = method->chatscript; cs; cs = cs->next) {
 			for (ref = cs->var_ref; ref; ref = ref->next) {
@@ -854,7 +895,7 @@
 	}
 	/* check for duplicates */
 	for (curr = *chain; curr; curr = curr->next) {
-		if (!strcasecmp(curr->name, item->name)) {
+		if ( chain == &first_save && !strcasecmp(curr->name, item->name)) {
 			yyerror("save name \"%s\" duplicated", item->name);
 			return 0;
 		}
@@ -901,7 +942,9 @@
 	char *argument;
 {
 	METHOD *new;
-
+        char arg_list[1024], *av[MAX_ARGS+2];
+	int ac = 0;
+		
 	if ((new = (METHOD *)malloc(sizeof(METHOD))) == NULL) {
 		yyerror("Out of memory");
 		return NULL;
@@ -915,10 +958,24 @@
 		yyerror("Out of memory");
 		return 0;
 	}
-	if (argument)
+	if (argument) {
 		new->argument = argument;
-	else if (new->argument)
+                (void)strncpy(arg_list, argument, sizeof(arg_list));
+		arg_list[sizeof(arg_list)-1] = '\0';
+	} else if (new->argument) {
 		new->argument = strdup(new->argument);
+                (void)strncpy(arg_list, new->argument, sizeof(arg_list));
+		arg_list[sizeof(arg_list)-1] = '\0';	
+	} else  arg_list[0] = '\0';
+        av[ac++] = new->name;
+        ac += make_argv(arg_list, (char ***)&av[ac], MAX_ARGS);
+	av[ac] = NULL;
+
+        if (new->when && (new->when = insert_args(new->when, av, ac)) == NULL)
+	        return NULL;
+	if (new->when_fmt && (new->when_fmt = insert_args(new->when_fmt, av, ac)) == NULL)
+                return NULL;
+	
 	if (new->chatscript) {
 		new->chatscript = dup_chatscript(new->name, new->argument, new->chatscript);
 		if (!new->chatscript) return NULL;
@@ -1342,11 +1399,15 @@
 
 /* Lexical analyzer return values */
 %token TOKEN_ROOTDIR
+%token TOKEN_CHROOTDIR
+%token TOKEN_USERNAME
+%token TOKEN_GROUPNAME
 %token TOKEN_TIMEFMT
 %token TOKEN_POLLING
 %token TOKEN_SAVING
 %token TOKEN_TIMEOUT
 %token TOKEN_RETRIES
+%token TOKEN_OMULSTATES
 
 %token TOKEN_GROUP
 %token TOKEN_PERMIT
@@ -1354,6 +1415,7 @@
 
 %token TOKEN_NETSTATE
 %token TOKEN_PORT
+%token TOKEN_BINDADDRESS
 
 %token TOKEN_SAVE
 %token TOKEN_FILE
@@ -1365,6 +1427,7 @@
 
 %token TOKEN_OBJECT
 %token TOKEN_ADDRESS
+%token TOKEN_SRCADDRESS
 %token TOKEN_DESCRIPTION
 %token TOKEN_SERVICE
 %token TOKEN_INTERFACE
@@ -1398,11 +1461,13 @@
 %token TOKEN_V2
 
 %token TOKEN_TRAP
+%token TOKEN_TRAPBINDADDRESS
 %token TOKEN_SOURCECHECK
 %token TOKEN_COMMUNITY
 %token TOKEN_ENTERPRISE
 %token TOKEN_SPECIFIC
 %token TRAP_GENERIC
+%token TOKEN_IGNORESTATE
 
 %token <number> TOKEN_NUMBER
 %token <string> TOKEN_STRING
@@ -1410,7 +1475,7 @@
 %token <string> VAR_OID
 
 %type <number> optional_number
-%type <string> optional_string quoted_string legal_string multiline_string
+%type <string> optional_string quoted_string legal_string multiline_string optional_multiline_string
 %type <save> get_save
 %type <method> get_method
 %type <trap> get_trap
@@ -1442,6 +1507,60 @@
 				YYABORT;
 			}
 		}
+	|	TOKEN_CHROOTDIR quoted_string
+		{
+			if (config.chrootdir) {
+				yyerror("ChRootDir statement duplicated");
+				YYABORT;
+			}
+			config.chrootdir = $2;
+		}
+	|	TOKEN_USERNAME quoted_string
+		{
+			struct passwd *pwentry;
+			
+			if (config.username) {
+				yyerror("UserName statement duplicated");
+				YYABORT;
+			}
+    			if ((pwentry = getpwnam($2)) == (struct passwd *)NULL) {
+				yyerror("UserName %s unknown.", $2);
+				YYABORT;			    
+			}			
+			config.uid = pwentry->pw_uid;
+			config.username = $2;			
+		}
+
+	|	TOKEN_GROUPNAME quoted_string
+		{
+			struct group *grentry;
+			
+			if (config.groupname) {
+				yyerror("GroupName statement duplicated");
+				YYABORT;
+			}
+    			if ((grentry = getgrnam($2)) == (struct group *)NULL) {
+				yyerror("GroupName %s unknown.", $2);
+				YYABORT;			    
+			}			
+			config.gid = grentry->gr_gid;
+			config.groupname = $2;			
+		}
+
+	|	TOKEN_SRCADDRESS quoted_string
+		{
+			struct in_addr ip_srcaddr;
+
+			if (config.srcaddress) {
+				yyerror("config source address duplicated");
+				YYABORT;
+			}
+			if (!gethostaddr(&ip_srcaddr, $2)) {
+				YYABORT;
+			}
+			config.srcaddress = $2;
+			memcpy(&config.ip_srcaddr, &ip_srcaddr, sizeof(struct in_addr));
+		}	
 	|	TOKEN_TIMEFMT quoted_string
 		{
 			if (config.timefmt) {
@@ -1485,6 +1604,10 @@
 			}
 			config.retries = $2;
 		}
+	|	TOKEN_OMULSTATES
+		{
+			config.compatibility_flag = 0;
+		}	    
 	|	TOKEN_NETSTATE '{' netstate_config '}'
 		{
 			if (!config.ns_port) {
@@ -1531,6 +1654,17 @@
 		{
 			config.source_traps = 1;
 		}
+	|	TOKEN_TRAPBINDADDRESS quoted_string
+		{
+			if (config.trap_address) {
+				yyerror("bindaddress duplicated");
+				YYABORT;
+			}
+    			if (!gethostaddr(&config.trap_ip_addr, $2)) {
+				YYABORT;
+			}
+			config.trap_address = $2;
+		}
 	|	TOKEN_TRAP legal_string '{' trap_config '}'
 		{
 			trap.name = $2;
@@ -1556,6 +1690,13 @@
 				yyerror("object address unspecified");
 				YYABORT;
 			}
+			if (!object.srcaddress) {
+				if (!config.srcaddress) {
+    				    bzero(&object.ip_srcaddr, sizeof(struct in_addr));
+				} else {
+				    memcpy(&object.ip_srcaddr, &config.ip_srcaddr, sizeof(struct in_addr));
+				}
+			}
 /*			if ((object.interface || object.ifgroup ||
 			     object.bgp || object.env) &&
 			    !find_method(object.method_list, "ROUTER")) {
@@ -1637,6 +1778,17 @@
 				YYABORT;
 			}
 		}
+	|	TOKEN_BINDADDRESS quoted_string
+		{
+			if (config.ns_address) {
+				yyerror("bindaddress duplicated");
+				YYABORT;
+			}
+			if (!gethostaddr(&config.ns_ip_addr, $2)) {
+				YYABORT;
+			}
+			config.ns_address = $2;
+		}
 	|	TOKEN_PERMIT quoted_string
 		{
 			/* for backward compatibility */
@@ -1701,7 +1853,7 @@
 			}
 			save.state = $2;
 		}
-	|	TOKEN_WHEN multiline_string TOKEN_NUMBER optional_string
+	|	TOKEN_WHEN multiline_string TOKEN_NUMBER optional_multiline_string
 		{
 			if (save.when) {
 				yyerror("save when condition duplicated");
@@ -1763,6 +1915,19 @@
 			method.start = echo_start;
 			method.stop = echo_stop;
 		}
+	|	TOKEN_PIPE quoted_string
+		{
+			if (method.protocol) {
+				yyerror("method protocol duplicated");
+				YYABORT;
+			}
+			method.protocol = PIPE_PROTO;
+			method.when = $2;
+			method.init = pipe_init;
+			method.start = pipe_start;
+			method.stop = tcp_stop;
+			method.retries = 1;		
+		}
 	|	TOKEN_PORT TOKEN_NUMBER
 		{
 			if (method.protocol &&
@@ -1808,12 +1973,30 @@
 				}
 			}
 		}
+	|	TOKEN_WHEN multiline_string TOKEN_NUMBER  optional_multiline_string
+		{
+			method.protocol = WHEN_PROTO;
+			if (method.when) {
+				yyerror("Method 'when condition' duplicated");
+				YYABORT;
+			}
+			method.init = when_init;
+			method.start = when_start;
+			method.stop = when_stop;
+			method.when = $2;
+			method.timeout = $3;
+			method.when_fmt = $4;
+		}
 	|	TOKEN_TIMEOUT TOKEN_NUMBER
 		{
 			if (method.timeout) {
 				yyerror("timeout statement duplicated");
 				YYABORT;
 			}
+			if (method.protocol == WHEN_PROTO) {
+				yyerror("timeout was defined in WHEN statement");
+				YYABORT;			
+			}
 			if ($2 < 1 || $2 > POLLING_MIN) {
 				yyerror("invalid timeout value (min 1 max %d sec.)",
 					POLLING_MIN);
@@ -1827,6 +2010,10 @@
 				yyerror("retries statement duplicated");
 				YYABORT;
 			}
+			if (method.protocol == PIPE_PROTO) {
+				yyerror("no retries possible in PIPE method");
+				YYABORT;			
+			}
 			if ($2 < 1 || $2 > POLLING_MIN) {
 				yyerror("invalid retries number (min 1 max %d)",
 					POLLING_MIN);
@@ -1838,7 +2025,8 @@
 		{
 			if (method.protocol &&
 			    method.protocol != IPPROTO_TCP &&
-			    method.protocol != IPPROTO_UDP) {
+			    method.protocol != IPPROTO_UDP &&
+			    method.protocol != PIPE_PROTO) {
 				yyerror("no suitable method protocol");
 				YYABORT;
 			}
@@ -2095,6 +2283,18 @@
 			}
 			object.address = $2;
 		}
+	|	TOKEN_SRCADDRESS quoted_string
+		{
+			if (object.srcaddress) {
+				yyerror("object source address duplicated");
+				YYABORT;
+			}
+			if (!gethostaddr(&object.ip_srcaddr, $2)) {
+				YYABORT;
+			}
+			object.srcaddress = $2;
+		}
+		
 	|	TOKEN_POLLING TOKEN_NUMBER
 		{
 			if (object.polling) {
@@ -2241,7 +2441,7 @@
 		}
 	|	TOKEN_INTERFACE TOKEN_NUMBER
 		{
-			if ($2 < 1 || $2 > 65535) {
+			if ($2 < 1 || $2 > INT_MAX) {
 				yyerror("interface index out of range");
 				YYABORT;
 			}
@@ -2252,7 +2452,7 @@
 		}
 	|	TOKEN_INTERFACE TOKEN_NUMBER '{' interface_config '}'
 		{
-			if ($2 < 1 || $2 > 65535) {
+			if ($2 < 1 || $2 > INT_MAX ) {
 				yyerror("interface index out of range");
 				YYABORT;
 			}
@@ -2473,6 +2673,10 @@
 				YYABORT;
 			}
 		}
+	|	TOKEN_IGNORESTATE
+		{
+			subobject.ignore_state = 1;
+		}
 	;
 
 interface_config:	/* empty */
@@ -2530,6 +2734,10 @@
 				YYABORT;
 			}
 		}
+	|	TOKEN_IGNORESTATE
+		{
+			interface.ignore_state = 1;
+		}
 	;
 
 bgp_config:	/* empty */
@@ -2580,6 +2788,10 @@
 			}
 			free($2);
 		}
+	|	TOKEN_IGNORESTATE
+		{
+			bgp_as.ignore_state = 1;
+		}
 	;
 
 env_config:	/* empty */
@@ -2629,6 +2841,10 @@
 				YYABORT;
 			}
 		}
+	|	TOKEN_IGNORESTATE
+		{
+			env_mon.ignore_state = 1;
+		}
 	;
 
 get_save:	legal_string optional_string
@@ -2918,6 +3134,12 @@
 			$$ = NULL;
 		}
 	|	quoted_string
+	;
+optional_multiline_string:
+		{
+			$$ = NULL;
+		}
+	|	multiline_string
 	;
 
 %%
