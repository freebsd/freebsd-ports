
$FreeBSD$

--- src/ps.c.orig	Mon Jan 22 16:04:50 2001
+++ src/ps.c	Fri Oct 18 11:19:55 2002
@@ -282,7 +282,7 @@
 
 /* Jake Hamby patch 18/3/98 */
 
-	sscanf(line, "%*s %s", text);
+	sscanf(line, "%*s %256s", text);
 	/*doc->epsf = iscomment(text, "EPSF-");*/
 	doc->epsf = iscomment(text, "EPSF"); /* Hamby - This line changed */
 	doc->beginheader = position;
@@ -323,7 +323,7 @@
 	} else if (doc->date == NULL && iscomment(line+2, "CreationDate:")) {
 	    doc->date = gettextline(line+length("%%CreationDate:"));
 	} else if (bb_set == NONE && iscomment(line+2, "BoundingBox:")) {
-	    sscanf(line+length("%%BoundingBox:"), "%s", text);
+	    sscanf(line+length("%%BoundingBox:"), "%256s", text);
 	    if (strcmp(text, "(atend)") == 0) {
 		bb_set = ATEND;
 	    } else {
@@ -355,7 +355,7 @@
 	    }
 	} else if (orientation_set == NONE &&
 		   iscomment(line+2, "Orientation:")) {
-	    sscanf(line+length("%%Orientation:"), "%s", text);
+	    sscanf(line+length("%%Orientation:"), "%256s", text);
 	    if (strcmp(text, "(atend)") == 0) {
 		orientation_set = ATEND;
 	    } else if (strcmp(text, "Portrait") == 0) {
@@ -366,7 +366,7 @@
 		orientation_set = 1;
 	    }
 	} else if (page_order_set == NONE && iscomment(line+2, "PageOrder:")) {
-	    sscanf(line+length("%%PageOrder:"), "%s", text);
+	    sscanf(line+length("%%PageOrder:"), "%256s", text);
 	    if (strcmp(text, "(atend)") == 0) {
 		page_order_set = ATEND;
 	    } else if (strcmp(text, "Ascend") == 0) {
@@ -380,7 +380,7 @@
 		page_order_set = 1;
 	    }
 	} else if (pages_set == NONE && iscomment(line+2, "Pages:")) {
-	    sscanf(line+length("%%Pages:"), "%s", text);
+	    sscanf(line+length("%%Pages:"), "%256s", text);
 	    if (strcmp(text, "(atend)") == 0) {
 		pages_set = ATEND;
 	    } else {
@@ -579,7 +579,7 @@
 		/* Do nothing */
 	    } else if (doc->default_page_orientation == NONE &&
 		iscomment(line+2, "PageOrientation:")) {
-		sscanf(line+length("%%PageOrientation:"), "%s", text);
+		sscanf(line+length("%%PageOrientation:"), "%256s", text);
 		if (strcmp(text, "Portrait") == 0) {
 		    doc->default_page_orientation = PORTRAIT;
 		} else if (strcmp(text, "Landscape") == 0) {
@@ -703,7 +703,7 @@
 		/* Do nothing */
 	    } else if (doc->default_page_orientation == NONE &&
 		iscomment(line+2, "PageOrientation:")) {
-		sscanf(line+length("%%PageOrientation:"), "%s", text);
+		sscanf(line+length("%%PageOrientation:"), "%256s", text);
 		if (strcmp(text, "Portrait") == 0) {
 		    doc->default_page_orientation = PORTRAIT;
 		} else if (strcmp(text, "Landscape") == 0) {
@@ -842,7 +842,7 @@
 		/* Do nothing */
 	    } else if (doc->pages[doc->numpages].orientation == NONE &&
 		iscomment(line+2, "PageOrientation:")) {
-		sscanf(line+length("%%PageOrientation:"), "%s", text);
+		sscanf(line+length("%%PageOrientation:"), "%256s", text);
 		if (strcmp(text, "Portrait") == 0) {
 		    doc->pages[doc->numpages].orientation = PORTRAIT;
 		} else if (strcmp(text, "Landscape") == 0) {
@@ -874,7 +874,7 @@
 		g_free(cp);
 	    } else if ((page_bb_set == NONE || page_bb_set == ATEND) &&
 		       iscomment(line+2, "PageBoundingBox:")) {
-		sscanf(line+length("%%PageBoundingBox:"), "%s", text);
+		sscanf(line+length("%%PageBoundingBox:"), "%256s", text);
 		if (strcmp(text, "(atend)") == 0) {
 		    page_bb_set = ATEND;
 		} else {
@@ -988,14 +988,14 @@
 	    }
 	} else if (orientation_set == ATEND &&
 		   iscomment(line+2, "Orientation:")) {
-	    sscanf(line+length("%%Orientation:"), "%s", text);
+	    sscanf(line+length("%%Orientation:"), "%256s", text);
 	    if (strcmp(text, "Portrait") == 0) {
 		doc->orientation = PORTRAIT;
 	    } else if (strcmp(text, "Landscape") == 0) {
 		doc->orientation = LANDSCAPE;
 	    }
 	} else if (page_order_set == ATEND && iscomment(line+2, "PageOrder:")) {
-	    sscanf(line+length("%%PageOrder:"), "%s", text);
+	    sscanf(line+length("%%PageOrder:"), "%256s", text);
 	    if (strcmp(text, "Ascend") == 0) {
 		doc->pageorder = ASCEND;
 	    } else if (strcmp(text, "Descend") == 0) {
@@ -1277,7 +1277,7 @@
    else if IS_BEGIN("Data:")      {
 	text[0] = '\0';
 	strcpy(save, line+7);
-	if (sscanf(line+length("%%BeginData:"), "%d %*s %s", &num, text) >= 1) {
+	if (sscanf(line+length("%%BeginData:"), "%d %*s %256s", &num, text) >= 1) {
 	    if (strcmp(text, "Lines") == 0) {
 		for (i=0; i < num; i++) {
 		    cp = fgets(line, size, fp);
@@ -1394,7 +1394,7 @@
     } else if (iscomment(line+7, "Data:")) {
 	text[0] = '\0';
 	strcpy(save, line+7);
-	if (sscanf(line+length("%%BeginData:"), "%d %*s %s", &num, text) >= 1) {
+	if (sscanf(line+length("%%BeginData:"), "%d %*s %256s", &num, text) >= 1) {
 	    if (strcmp(text, "Lines") == 0) {
 		for (i=0; i < num; i++) {
 		    cp = fgets(line, size, fp);
@@ -1470,7 +1470,7 @@
 	} else if (iscomment(line+7, "Data:")) {
 	    text[0] = '\0';
 	    if (sscanf(line+length("%%BeginData:"),
-		       "%d %*s %s", &num, text) >= 1) {
+		       "%d %*s %256s", &num, text) >= 1) {
 		if (strcmp(text, "Lines") == 0) {
 		    for (i=0; i < num; i++) {
 			fgets(line, sizeof line, from);
@@ -1538,7 +1538,7 @@
 	} else if (iscomment(line+7, "Data:")) {
 	    text[0] = '\0';
 	    if (sscanf(line+length("%%BeginData:"),
-		       "%d %*s %s", &num, text) >= 1) {
+		       "%d %*s %256s", &num, text) >= 1) {
 		if (strcmp(text, "Lines") == 0) {
 		    for (i=0; i < num; i++) {
 			fgets(line, sizeof line, from);
@@ -1623,7 +1623,7 @@
           g_free(comment);
           continue;
        }
-       sscanf(comment+length("%%Pages:"), "%s", text);
+       sscanf(comment+length("%%Pages:"), "%256s", text);
        if (strcmp(text, "(atend)") == 0) {
           fputs(comment, dest_file);
           pages_atend = TRUE;
