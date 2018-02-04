--- src/log.cc.orig	2018-02-04 09:36:17 UTC
+++ src/log.cc
@@ -37,7 +37,7 @@ int CommonLogParser::parse(char *logline, struct logbi
 	if (!bufcp)
 		return -1;
 	
-	*bufcp = (char) NULL;
+	*bufcp = '\0';
 	++bufcp;
 
 	/* quickly figure out if this is an IP or a host. We do this by
@@ -172,7 +172,7 @@ int CommonLogParser::parse(char *logline, struct logbi
 	/* find the end of referrer and null it */
 	if (!(bufcp = strchr(bufsp, '"')))
 		return -1;
-	*bufcp = (char) NULL;
+	*bufcp = '\0';
 
 	/* unless they want to keep it, skip over the protocol, ie http:// */
 	if ((cf.preserve_ref_protocol == 0) && (bufcp = strstr(bufsp, "://")))
@@ -230,7 +230,7 @@ char *LogParser::processURL(char **buf) /* {{{ */
 		return NULL;
 
 	/* null the space in front of it */
-	*endptr = (char) NULL;
+	*endptr = '\0';
 
 	/* TODO maybe we can use the protocol someday.. */
 
@@ -258,7 +258,7 @@ int LogParser::mungeURL(char **url, int *length) /* {{
 	char *bufcp, *endptr, *workptr;
 
 	endptr = *url + *length;
-	*endptr = (char) NULL;
+	*endptr = '\0';
 
 	/* do we want to keep the query string? */
 	if (!cf.keep_querystring)
@@ -273,7 +273,7 @@ int LogParser::mungeURL(char **url, int *length) /* {{
 			if (workptr < endptr)
 			{
 				/* we're ok */
-				*workptr = (char) NULL;
+				*workptr = '\0';
 				bufcp = workptr+1;
 			}
 		}
@@ -308,7 +308,7 @@ int LogParser::mungeURL(char **url, int *length) /* {{
 			if (workptr == endptr)
 				bufcp = workptr;
 		}
-		*bufcp = (char) NULL;
+		*bufcp = '\0';
 	}
 
 
