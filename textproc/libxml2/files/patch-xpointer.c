From d8e1faeaa99c7a7c07af01c1c72de352eb590a3e Mon Sep 17 00:00:00 2001
From: Jüri Aedla <asd@ut.ee>
Date: Mon, 07 May 2012 07:06:56 +0000
Subject: Fix an off by one pointer access

getting out of the range of memory allocated for xpointer decoding
CVE-2011-3102

---
diff --git a/xpointer.c b/xpointer.c
index 37afa3a..0b463dd 100644
--- xpointer.c
+++ xpointer.c
@@ -1007,21 +1007,14 @@ xmlXPtrEvalXPtrPart(xmlXPathParserContextPtr ctxt, xmlChar *name) {
 		NEXT;
 		break;
 	    }
-	    *cur++ = CUR;
 	} else if (CUR == '(') {
 	    level++;
-	    *cur++ = CUR;
 	} else if (CUR == '^') {
-	    NEXT;
-	    if ((CUR == ')') || (CUR == '(') || (CUR == '^')) {
-		*cur++ = CUR;
-	    } else {
-		*cur++ = '^';
-		*cur++ = CUR;
-	    }
-	} else {
-	    *cur++ = CUR;
+            if ((NXT(1) == ')') || (NXT(1) == '(') || (NXT(1) == '^')) {
+                NEXT;
+            }
 	}
+        *cur++ = CUR;
 	NEXT;
     }
     *cur = 0;
--
cgit v0.9.0.2
