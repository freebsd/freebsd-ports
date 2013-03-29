
--- parser.c.orig	2013-03-13 09:36:07.000000000 +0000
+++ parser.c	2013-03-13 09:35:54.000000000 +0000
@@ -40,6 +40,7 @@
 #endif
 
 #include <stdlib.h>
+#include <limits.h>
 #include <string.h>
 #include <stdarg.h>
 #include <libxml/xmlmemory.h>
@@ -117,16 +118,33 @@
  * parser option.
  */
 static int
-xmlParserEntityCheck(xmlParserCtxtPtr ctxt, unsigned long size,
-                     xmlEntityPtr ent)
+xmlParserEntityCheck(xmlParserCtxtPtr ctxt, size_t size,
+                     xmlEntityPtr ent, size_t replacement)
 {
-    unsigned long consumed = 0;
+    size_t consumed = 0;
 
     if ((ctxt == NULL) || (ctxt->options & XML_PARSE_HUGE))
         return (0);
     if (ctxt->lastError.code == XML_ERR_ENTITY_LOOP)
         return (1);
-    if (size != 0) {
+    if (replacement != 0) {
+	if (replacement < XML_MAX_TEXT_LENGTH)
+	    return(0);
+
+        /*
+	 * If the volume of entity copy reaches 10 times the
+	 * amount of parsed data and over the large text threshold
+	 * then that's very likely to be an abuse.
+	 */
+        if (ctxt->input != NULL) {
+	    consumed = ctxt->input->consumed +
+	               (ctxt->input->cur - ctxt->input->base);
+	}
+        consumed += ctxt->sizeentities;
+
+        if (replacement < XML_PARSER_NON_LINEAR * consumed)
+	    return(0);
+    } else if (size != 0) {
         /*
          * Do the check based on the replacement size of the entity
          */
@@ -172,7 +190,6 @@
          */
         return (0);
     }
-
     xmlFatalErr(ctxt, XML_ERR_ENTITY_LOOP, NULL);
     return (1);
 }
@@ -2589,15 +2606,17 @@
 
 /*
  * Macro used to grow the current buffer.
+ * buffer##_size is expected to be a size_t
+ * mem_error: is expected to handle memory allocation failures
  */
 #define growBuffer(buffer, n) {						\
     xmlChar *tmp;							\
-    buffer##_size *= 2;							\
-    buffer##_size += n;							\
-    tmp = (xmlChar *)							\
-		xmlRealloc(buffer, buffer##_size * sizeof(xmlChar));	\
+    size_t new_size = buffer##_size * 2 + n;                            \
+    if (new_size < buffer##_size) goto mem_error;                       \
+    tmp = (xmlChar *) xmlRealloc(buffer, new_size);                     \
     if (tmp == NULL) goto mem_error;					\
     buffer = tmp;							\
+    buffer##_size = new_size;                                           \
 }
 
 /**
@@ -2623,14 +2642,14 @@
 xmlStringLenDecodeEntities(xmlParserCtxtPtr ctxt, const xmlChar *str, int len,
 		      int what, xmlChar end, xmlChar  end2, xmlChar end3) {
     xmlChar *buffer = NULL;
-    int buffer_size = 0;
+    size_t buffer_size = 0;
+    size_t nbchars = 0;
 
     xmlChar *current = NULL;
     xmlChar *rep = NULL;
     const xmlChar *last;
     xmlEntityPtr ent;
     int c,l;
-    int nbchars = 0;
 
     if ((ctxt == NULL) || (str == NULL) || (len < 0))
 	return(NULL);
@@ -2647,7 +2666,7 @@
      * allocate a translation buffer.
      */
     buffer_size = XML_PARSER_BIG_BUFFER_SIZE;
-    buffer = (xmlChar *) xmlMallocAtomic(buffer_size * sizeof(xmlChar));
+    buffer = (xmlChar *) xmlMallocAtomic(buffer_size);
     if (buffer == NULL) goto mem_error;
 
     /*
@@ -2667,7 +2686,7 @@
 	    if (val != 0) {
 		COPY_BUF(0,buffer,nbchars,val);
 	    }
-	    if (nbchars > buffer_size - XML_PARSER_BUFFER_SIZE) {
+	    if (nbchars + XML_PARSER_BUFFER_SIZE > buffer_size) {
 	        growBuffer(buffer, XML_PARSER_BUFFER_SIZE);
 	    }
 	} else if ((c == '&') && (what & XML_SUBSTITUTE_REF)) {
@@ -2685,7 +2704,7 @@
 		(ent->etype == XML_INTERNAL_PREDEFINED_ENTITY)) {
 		if (ent->content != NULL) {
 		    COPY_BUF(0,buffer,nbchars,ent->content[0]);
-		    if (nbchars > buffer_size - XML_PARSER_BUFFER_SIZE) {
+		    if (nbchars + XML_PARSER_BUFFER_SIZE > buffer_size) {
 			growBuffer(buffer, XML_PARSER_BUFFER_SIZE);
 		    }
 		} else {
@@ -2702,9 +2721,8 @@
 		    current = rep;
 		    while (*current != 0) { /* non input consuming loop */
 			buffer[nbchars++] = *current++;
-			if (nbchars >
-		            buffer_size - XML_PARSER_BUFFER_SIZE) {
-			    if (xmlParserEntityCheck(ctxt, nbchars, ent))
+			if (nbchars + XML_PARSER_BUFFER_SIZE > buffer_size) {
+			    if (xmlParserEntityCheck(ctxt, nbchars, ent, 0))
 				goto int_error;
 			    growBuffer(buffer, XML_PARSER_BUFFER_SIZE);
 			}
@@ -2717,7 +2735,7 @@
 		const xmlChar *cur = ent->name;
 
 		buffer[nbchars++] = '&';
-		if (nbchars > buffer_size - i - XML_PARSER_BUFFER_SIZE) {
+		if (nbchars + i + XML_PARSER_BUFFER_SIZE > buffer_size) {
 		    growBuffer(buffer, i + XML_PARSER_BUFFER_SIZE);
 		}
 		for (;i > 0;i--)
@@ -2745,9 +2763,8 @@
 		    current = rep;
 		    while (*current != 0) { /* non input consuming loop */
 			buffer[nbchars++] = *current++;
-			if (nbchars >
-		            buffer_size - XML_PARSER_BUFFER_SIZE) {
-			    if (xmlParserEntityCheck(ctxt, nbchars, ent))
+			if (nbchars + XML_PARSER_BUFFER_SIZE > buffer_size) {
+			    if (xmlParserEntityCheck(ctxt, nbchars, ent, 0))
 			        goto int_error;
 			    growBuffer(buffer, XML_PARSER_BUFFER_SIZE);
 			}
@@ -2759,8 +2776,8 @@
 	} else {
 	    COPY_BUF(l,buffer,nbchars,c);
 	    str += l;
-	    if (nbchars > buffer_size - XML_PARSER_BUFFER_SIZE) {
-	      growBuffer(buffer, XML_PARSER_BUFFER_SIZE);
+	    if (nbchars + XML_PARSER_BUFFER_SIZE > buffer_size) {
+	        growBuffer(buffer, XML_PARSER_BUFFER_SIZE);
 	    }
 	}
 	if (str < last)
@@ -3764,8 +3781,8 @@
     xmlChar limit = 0;
     xmlChar *buf = NULL;
     xmlChar *rep = NULL;
-    int len = 0;
-    int buf_size = 0;
+    size_t len = 0;
+    size_t buf_size = 0;
     int c, l, in_space = 0;
     xmlChar *current = NULL;
     xmlEntityPtr ent;
@@ -3787,7 +3804,7 @@
      * allocate a translation buffer.
      */
     buf_size = XML_PARSER_BUFFER_SIZE;
-    buf = (xmlChar *) xmlMallocAtomic(buf_size * sizeof(xmlChar));
+    buf = (xmlChar *) xmlMallocAtomic(buf_size);
     if (buf == NULL) goto mem_error;
 
     /*
@@ -3804,7 +3821,7 @@
 
 		if (val == '&') {
 		    if (ctxt->replaceEntities) {
-			if (len > buf_size - 10) {
+			if (len + 10 > buf_size) {
 			    growBuffer(buf, 10);
 			}
 			buf[len++] = '&';
@@ -3813,7 +3830,7 @@
 			 * The reparsing will be done in xmlStringGetNodeList()
 			 * called by the attribute() function in SAX.c
 			 */
-			if (len > buf_size - 10) {
+			if (len + 10 > buf_size) {
 			    growBuffer(buf, 10);
 			}
 			buf[len++] = '&';
@@ -3823,7 +3840,7 @@
 			buf[len++] = ';';
 		    }
 		} else if (val != 0) {
-		    if (len > buf_size - 10) {
+		    if (len + 10 > buf_size) {
 			growBuffer(buf, 10);
 		    }
 		    len += xmlCopyChar(0, &buf[len], val);
@@ -3835,7 +3852,7 @@
 		    ctxt->nbentities += ent->owner;
 		if ((ent != NULL) &&
 		    (ent->etype == XML_INTERNAL_PREDEFINED_ENTITY)) {
-		    if (len > buf_size - 10) {
+		    if (len + 10 > buf_size) {
 			growBuffer(buf, 10);
 		    }
 		    if ((ctxt->replaceEntities == 0) &&
@@ -3863,7 +3880,7 @@
                                     current++;
                                 } else
                                     buf[len++] = *current++;
-				if (len > buf_size - 10) {
+				if (len + 10 > buf_size) {
 				    growBuffer(buf, 10);
 				}
 			    }
@@ -3871,7 +3888,7 @@
 			    rep = NULL;
 			}
 		    } else {
-			if (len > buf_size - 10) {
+			if (len + 10 > buf_size) {
 			    growBuffer(buf, 10);
 			}
 			if (ent->content != NULL)
@@ -3899,7 +3916,7 @@
 		     * Just output the reference
 		     */
 		    buf[len++] = '&';
-		    while (len > buf_size - i - 10) {
+		    while (len + i + 10 > buf_size) {
 			growBuffer(buf, i + 10);
 		    }
 		    for (;i > 0;i--)
@@ -3912,7 +3929,7 @@
 	        if ((len != 0) || (!normalize)) {
 		    if ((!normalize) || (!in_space)) {
 			COPY_BUF(l,buf,len,0x20);
-			while (len > buf_size - 10) {
+			while (len + 10 > buf_size) {
 			    growBuffer(buf, 10);
 			}
 		    }
@@ -3921,7 +3938,7 @@
 	    } else {
 	        in_space = 0;
 		COPY_BUF(l,buf,len,c);
-		if (len > buf_size - 10) {
+		if (len + 10 > buf_size) {
 		    growBuffer(buf, 10);
 		}
 	    }
@@ -3931,7 +3948,7 @@
 	c = CUR_CHAR(l);
     }
     if ((in_space) && (normalize)) {
-        while (buf[len - 1] == 0x20) len--;
+        while ((len > 0) && (buf[len - 1] == 0x20)) len--;
     }
     buf[len] = 0;
     if (RAW == '<') {
@@ -3946,7 +3963,18 @@
         }
     } else
 	NEXT;
-    if (attlen != NULL) *attlen = len;
+
+    /*
+     * There we potentially risk an overflow, don't allow attribute value of
+     * lenght more than INT_MAX it is a very reasonnable assumption !
+     */
+    if (len >= INT_MAX) {
+        xmlFatalErrMsg(ctxt, XML_ERR_ATTRIBUTE_NOT_FINISHED,
+                       "AttValue lenght too long\n");
+        goto mem_error;
+    }
+
+    if (attlen != NULL) *attlen = (int) len;
     return(buf);
 
 mem_error:
@@ -6964,7 +6992,7 @@
 	    xmlFreeNodeList(list);
 	    return;
 	}
-	if (xmlParserEntityCheck(ctxt, 0, ent)) {
+	if (xmlParserEntityCheck(ctxt, 0, ent, 0)) {
 	    xmlFreeNodeList(list);
 	    return;
 	}
@@ -7124,6 +7152,13 @@
 		xmlNodePtr nw = NULL, cur, firstChild = NULL;
 
 		/*
+		 * We are copying here, make sure there is no abuse
+		 */
+		ctxt->sizeentcopy += ent->length;
+		if (xmlParserEntityCheck(ctxt, 0, ent, ctxt->sizeentcopy))
+		    return;
+
+		/*
 		 * when operating on a reader, the entities definitions
 		 * are always owning the entities subtree.
 		if (ctxt->parseMode == XML_PARSE_READER)
@@ -7163,6 +7198,14 @@
 	    } else if (list == NULL) {
 		xmlNodePtr nw = NULL, cur, next, last,
 			   firstChild = NULL;
+
+		/*
+		 * We are copying here, make sure there is no abuse
+		 */
+		ctxt->sizeentcopy += ent->length;
+		if (xmlParserEntityCheck(ctxt, 0, ent, ctxt->sizeentcopy))
+		    return;
+
 		/*
 		 * Copy the entity child list and make it the new
 		 * entity child list. The goal is to make sure any
@@ -14343,6 +14386,7 @@
     ctxt->catalogs = NULL;
     ctxt->nbentities = 0;
     ctxt->sizeentities = 0;
+    ctxt->sizeentcopy = 0;
     xmlInitNodeInfoSeq(&ctxt->node_seq);
 
     if (ctxt->attsDefault != NULL) {
