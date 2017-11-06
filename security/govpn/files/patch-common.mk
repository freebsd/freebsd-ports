--- common.mk.orig	2017-08-18 15:46:39 UTC
+++ common.mk
@@ -38,7 +38,7 @@ install: all doc
 	cp -f utils/newclient.sh $(SHAREDIR)
 	chmod 755 $(SHAREDIR)/newclient.sh
 	mkdir -p $(DOCDIR)
-	cp -f -L AUTHORS INSTALL NEWS README README.RU THANKS $(DOCDIR)
+	cp -f -L AUTHORS INSTALL NEWS NEWS.RU README README.RU THANKS $(DOCDIR)
 	chmod 644 $(DOCDIR)/*
 
 install-strip: install
