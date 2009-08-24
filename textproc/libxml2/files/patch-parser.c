--- parser.c.orig
+++ parser.c
@@ -5306,7 +5306,8 @@
 	if (name == NULL) {
 	    xmlFatalErrMsg(ctxt, XML_ERR_NAME_REQUIRED,
 			   "Name expected in NOTATION declaration\n");
-	    return(ret);
+		xmlFreeEnumeration(ret);
+		return(NULL);
 	}
 	tmp = ret;
 	while (tmp != NULL) {
@@ -5322,7 +5323,10 @@
 	}
 	if (tmp == NULL) {
 	    cur = xmlCreateEnumeration(name);
-	    if (cur == NULL) return(ret);
+	    if (cur == NULL) {
+			xmlFreeEnumeration(ret);
+			return(NULL);
+		}
 	    if (last == NULL) ret = last = cur;
 	    else {
 		last->next = cur;
@@ -5334,8 +5338,8 @@
     if (RAW != ')') {
 	xmlFatalErr(ctxt, XML_ERR_NOTATION_NOT_FINISHED, NULL);
 	if ((last != NULL) && (last != ret))
-	    xmlFreeEnumeration(last);
-	return(ret);
+	   xmlFreeEnumeration(ret);
+	return(NULL);
     }
     NEXT;
     return(ret);
@@ -5390,7 +5394,10 @@
 	    cur = xmlCreateEnumeration(name);
 	    if (!xmlDictOwns(ctxt->dict, name))
 		xmlFree(name);
-	    if (cur == NULL) return(ret);
+	    if (cur == NULL){
+			xmlFreeEnumeration(ret);
+			return(NULL);
+		}
 	    if (last == NULL) ret = last = cur;
 	    else {
 		last->next = cur;
@@ -5794,6 +5801,11 @@
     const xmlChar *elem;
     xmlChar type = 0;
 
+	if (ctxt->depth > 128) {
+		xmlFatalErrMsgInt(ctxt, XML_ERR_ELEMCONTENT_NOT_FINISHED, "xmlParseElementChildrenContentDecl : depth %d too deep\n", ctxt->depth);
+		return(NULL);
+	}
+
     SKIP_BLANKS;
     GROW;
     if (RAW == '(') {
@@ -5802,7 +5814,9 @@
         /* Recurse on first child */
 	NEXT;
 	SKIP_BLANKS;
+	ctxt->depth++;
         cur = ret = xmlParseElementChildrenContentDecl(ctxt, inputid);
+		ctxt->depth--;
 	SKIP_BLANKS;
 	GROW;
     } else {
@@ -5934,7 +5948,9 @@
 	    /* Recurse on second child */
 	    NEXT;
 	    SKIP_BLANKS;
+		ctxt->depth++;
 	    last = xmlParseElementChildrenContentDecl(ctxt, inputid);
+		ctxt->depth--;
 	    SKIP_BLANKS;
 	} else {
 	    elem = xmlParseName(ctxt);
