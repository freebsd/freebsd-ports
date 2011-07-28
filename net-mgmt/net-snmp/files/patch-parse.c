--- snmplib/parse.c
+++ snmplib/parse.c
@@ -3902,8 +3902,13 @@ read_module_internal(const char *name)
                 return MODULE_ALREADY_LOADED;
             }
             if ((fp = fopen(mp->file, "r")) == NULL) {
+                int rval;
+                if (errno == ENOTDIR || errno == ENOENT)
+                    rval = MODULE_NOT_FOUND;
+                else
+                    rval = MODULE_LOAD_FAILED;
                 snmp_log_perror(mp->file);
-                return MODULE_LOAD_FAILED;
+                return rval;
             }
             mp->no_imports = 0; /* Note that we've read the file */
             File = mp->file;
@@ -3917,10 +3922,7 @@ read_module_internal(const char *name)
             File = oldFile;
             mibLine = oldLine;
             current_module = oldModule;
-            if (np != NULL)
-                return MODULE_LOADED_OK;
-            else if (gMibError == MODULE_SYNTAX_ERROR) 
-                return MODULE_SYNTAX_ERROR;
+            return gMibError ? gMibError : MODULE_LOADED_OK;
         }
 
     return MODULE_NOT_FOUND;
@@ -4339,6 +4341,7 @@ parse(FILE * fp, struct node *root)
         case END:
             if (state != IN_MIB) {
                 print_error("Error, END before start of MIB", NULL, type);
+                gMibError = MODULE_SYNTAX_ERROR;
                 return NULL;
             } else {
                 struct module  *mp;
@@ -4403,6 +4406,7 @@ parse(FILE * fp, struct node *root)
                 nnp = parse_macro(fp, name);
                 if (nnp == NULL) {
                     print_error("Bad parse of MACRO", NULL, type);
+                    gMibError = MODULE_SYNTAX_ERROR;
                     /*
                      * return NULL;
                      */
@@ -4427,6 +4431,7 @@ parse(FILE * fp, struct node *root)
                 type = get_token(fp, token, MAXTOKEN);
             if (type == ENDOFFILE) {
                 print_error("Expected \"}\"", token, type);
+                gMibError = MODULE_SYNTAX_ERROR;
                 return NULL;
             }
             type = get_token(fp, token, MAXTOKEN);
@@ -4436,6 +4441,7 @@ parse(FILE * fp, struct node *root)
         case DEFINITIONS:
             if (state != BETWEEN_MIBS) {
                 print_error("Error, nested MIBS", NULL, type);
+                gMibError = MODULE_SYNTAX_ERROR;
                 return NULL;
             }
             state = IN_MIB;
@@ -4460,6 +4466,7 @@ parse(FILE * fp, struct node *root)
             nnp = parse_objecttype(fp, name);
             if (nnp == NULL) {
                 print_error("Bad parse of OBJECT-TYPE", NULL, type);
+                gMibError = MODULE_SYNTAX_ERROR;
                 return NULL;
             }
             break;
@@ -4467,6 +4474,7 @@ parse(FILE * fp, struct node *root)
             nnp = parse_objectgroup(fp, name, OBJECTS, &objects);
             if (nnp == NULL) {
                 print_error("Bad parse of OBJECT-GROUP", NULL, type);
+                gMibError = MODULE_SYNTAX_ERROR;
                 return NULL;
             }
             break;
@@ -4474,6 +4482,7 @@ parse(FILE * fp, struct node *root)
             nnp = parse_objectgroup(fp, name, NOTIFICATIONS, &notifs);
             if (nnp == NULL) {
                 print_error("Bad parse of NOTIFICATION-GROUP", NULL, type);
+                gMibError = MODULE_SYNTAX_ERROR;
                 return NULL;
             }
             break;
@@ -4481,6 +4490,7 @@ parse(FILE * fp, struct node *root)
             nnp = parse_trapDefinition(fp, name);
             if (nnp == NULL) {
                 print_error("Bad parse of TRAP-TYPE", NULL, type);
+                gMibError = MODULE_SYNTAX_ERROR;
                 return NULL;
             }
             break;
@@ -4488,6 +4498,7 @@ parse(FILE * fp, struct node *root)
             nnp = parse_notificationDefinition(fp, name);
             if (nnp == NULL) {
                 print_error("Bad parse of NOTIFICATION-TYPE", NULL, type);
+                gMibError = MODULE_SYNTAX_ERROR;
                 return NULL;
             }
             break;
@@ -4495,6 +4506,7 @@ parse(FILE * fp, struct node *root)
             nnp = parse_compliance(fp, name);
             if (nnp == NULL) {
                 print_error("Bad parse of MODULE-COMPLIANCE", NULL, type);
+                gMibError = MODULE_SYNTAX_ERROR;
                 return NULL;
             }
             break;
@@ -4502,6 +4514,7 @@ parse(FILE * fp, struct node *root)
             nnp = parse_capabilities(fp, name);
             if (nnp == NULL) {
                 print_error("Bad parse of AGENT-CAPABILITIES", NULL, type);
+                gMibError = MODULE_SYNTAX_ERROR;
                 return NULL;
             }
             break;
@@ -4509,6 +4522,7 @@ parse(FILE * fp, struct node *root)
             nnp = parse_macro(fp, name);
             if (nnp == NULL) {
                 print_error("Bad parse of MACRO", NULL, type);
+                gMibError = MODULE_SYNTAX_ERROR;
                 /*
                  * return NULL;
                  */
@@ -4520,6 +4534,7 @@ parse(FILE * fp, struct node *root)
             nnp = parse_moduleIdentity(fp, name);
             if (nnp == NULL) {
                 print_error("Bad parse of MODULE-IDENTITY", NULL, type);
+                gMibError = MODULE_SYNTAX_ERROR;
                 return NULL;
             }
             break;
@@ -4527,6 +4542,7 @@ parse(FILE * fp, struct node *root)
             nnp = parse_objectgroup(fp, name, OBJECTS, &objects);
             if (nnp == NULL) {
                 print_error("Bad parse of OBJECT-IDENTITY", NULL, type);
+                gMibError = MODULE_SYNTAX_ERROR;
                 return NULL;
             }
             break;
@@ -4534,16 +4550,19 @@ parse(FILE * fp, struct node *root)
             type = get_token(fp, token, MAXTOKEN);
             if (type != IDENTIFIER) {
                 print_error("Expected IDENTIFIER", token, type);
+                gMibError = MODULE_SYNTAX_ERROR;
                 return NULL;
             }
             type = get_token(fp, token, MAXTOKEN);
             if (type != EQUALS) {
                 print_error("Expected \"::=\"", token, type);
+                gMibError = MODULE_SYNTAX_ERROR;
                 return NULL;
             }
             nnp = parse_objectid(fp, name);
             if (nnp == NULL) {
                 print_error("Bad parse of OBJECT IDENTIFIER", NULL, type);
+                gMibError = MODULE_SYNTAX_ERROR;
                 return NULL;
             }
             break;
@@ -4555,6 +4574,7 @@ parse(FILE * fp, struct node *root)
             break;
         default:
             print_error("Bad operator", token, type);
+            gMibError = MODULE_SYNTAX_ERROR;
             return NULL;
         }
         if (nnp) {
