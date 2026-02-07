--- common/vbi-data.c.orig	2020-05-15 23:32:25 UTC
+++ common/vbi-data.c
@@ -86,8 +86,11 @@ vbi_open(char *dev, int debug, int sim)
 	vbi->cap = vbi_capture_v4l2_new(dev,16,&services,-1,&vbi->err,debug);
 	if (NULL == vbi->cap) {
 	    vbi->cap = vbi_capture_v4l_new(dev,16,&services,-1,&vbi->err,debug);
-	    if (NULL == vbi->cap)
-		goto oops;
+	    if (NULL == vbi->cap) {
+		vbi->cap = vbi_capture_bktr_new(dev,16,&services,-1,&vbi->err,debug);
+		if (NULL == vbi->cap)
+		    goto oops;
+	    }
 	}
 	vbi->par = vbi_capture_parameters(vbi->cap);
 	vbi->fd = vbi_capture_fd(vbi->cap);
