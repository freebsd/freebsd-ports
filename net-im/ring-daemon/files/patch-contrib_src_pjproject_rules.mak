--- contrib/src/pjproject/rules.mak.orig	2016-05-10 20:45:50 UTC
+++ contrib/src/pjproject/rules.mak
@@ -42,17 +42,17 @@ endif
 DEPS_pjproject += gnutls
 ifndef HAVE_WIN32
 ifndef HAVE_MACOSX
-DEPS_pjproject += uuid
+#DEPS_pjproject += uuid
 endif
 endif
 
 $(TARBALLS)/pjproject-$(PJPROJECT_VERSION).tar.bz2:
-	$(call download,$(PJPROJECT_URL))
+	#$(call download,$(PJPROJECT_URL))
 
-.sum-pjproject: pjproject-$(PJPROJECT_VERSION).tar.bz2
+#.sum-pjproject: pjproject-$(PJPROJECT_VERSION).tar.bz2
 
-pjproject: pjproject-$(PJPROJECT_VERSION).tar.bz2 .sum-pjproject
-	$(UNPACK)
+pjproject: pjproject-$(PJPROJECT_VERSION).tar.bz2
+	#$(UNPACK)
 ifdef HAVE_WIN32
 	$(APPLY) $(SRC)/pjproject/intptr_t.patch
 	$(APPLY) $(SRC)/pjproject/pj_win.patch
@@ -68,6 +68,6 @@ endif
 	$(MOVE)
 
 .pjproject: pjproject
-	cd $< && $(HOSTVARS) ./aconfigure $(HOSTCONF) $(PJPROJECT_OPTIONS)
+	cd $< && $(HOSTVARS) ./aconfigure $(HOSTCONF) $(PJPROJECT_OPTIONS) CPPFLAGS=-I/usr/local/include/ CFLAGS="-I/usr/local/include/ -fPIC" CPPFLAGS=-I/usr/local/include/ CFLAGS="-I/usr/local/include/ -fPIC"
 	cd $< && CFLAGS="$(PJPROJECT_EXTRA_CFLAGS)" $(MAKE) && $(MAKE) install
 	touch $@
