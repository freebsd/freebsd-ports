--- common/vbi-data.c.orig	Tue Feb 10 22:07:49 2004
+++ common/vbi-data.c	Tue Feb 10 22:09:03 2004
@@ -71,8 +71,11 @@
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
