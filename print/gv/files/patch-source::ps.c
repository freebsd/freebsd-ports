--- source/ps.c.orig	Sat Feb  1 00:56:20 2003
+++ source/ps.c	Sat Feb  1 01:17:43 2003
@@ -1770,8 +1770,6 @@
            (DSCcomment(line) && iscomment(line+2,(comment)))
 #define IS_BEGIN(comment)				\
            (iscomment(line+7,(comment)))
-#define IS_END(comment)				\
-           (iscomment(line+5,(comment)))
 #define SKIP_WHILE(cond)				\
 	   while (readline(fd, &line, NULL, &nbytes) && (cond)) *line_lenP += nbytes;\
            skipped=1;
@@ -1808,10 +1806,10 @@
 #endif
    if  (!IS_COMMENT("Begin"))     {} /* Do nothing */
    else if IS_BEGIN("Document:")  {  /* Skip the EPS without handling its content */
-            while (line && !IS_END("Document")) {
-               line = ps_io_fgetchars(fd,-1);
-               if (line) *line_lenP += FD_LINE_LEN;
-            }
+            while ((line = ps_io_fgetchars(fd,-1)) && !IS_COMMENT("EndDocument"))
+               *line_lenP += FD_LINE_LEN;
+	    nbytes = line ? FD_LINE_LEN : 0;
+	    skipped = 1;
    }
    else if IS_BEGIN("Feature:")   SKIP_UNTIL_1("EndFeature")
 #ifdef USE_ACROREAD_WORKAROUND
