--- src/gvcver.mak.orig	2008-07-14 09:44:07.759575900 -0400
+++ src/gvcver.mak	2008-07-14 09:44:49.641971567 -0400
@@ -32,5 +32,5 @@
 	$(ECHOGSV) -a $(OD)gsvver.h -x 23 "define GSVIEW_VERSION " $(GSVIEW_VERSION)
 	$(ECHOGSV) -a $(OD)gsvver.h -x 23 "define GSVIEW_DOT_VERSION " -x 22 $(GSVIEW_DOT_VERSION) -x 22
 	$(ECHOGSV) -a $(OD)gsvver.h -x 23 "define GSVIEW_DATE " -x 22 $(GSVIEW_DATE) -x 22
-	$(ECHOGSV) -a $(OD)gsvver.h -x 23 "define GSVIEW_DOCPATH " -x 22 $(GSVIEW_DOCPATH) "/gsview-" $(GSVIEW_DOT_VERSION) "/" -x 22
+	$(ECHOGSV) -a $(OD)gsvver.h -x 23 "define GSVIEW_DOCPATH " -x 22 $(GSVIEW_DOCPATH) "/gsview/" -x 22
 	$(ECHOGSV) -a $(OD)gsvver.h -x 23 "define GSVIEW_ETCPATH " -x 22 $(GSVIEW_ETCPATH) "/gsview/" -x 22
