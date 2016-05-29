--- contrib/src/uuid/rules.mak.orig	2016-05-10 20:45:50 UTC
+++ contrib/src/uuid/rules.mak
@@ -1,6 +1,6 @@
 # libuuid part of util-linux
 
-UUID_VERSION := 1.0.2
+UUID_VERSION := 1.0.3
 UUID_URL := $(SF)/libuuid/libuuid-$(UUID_VERSION).tar.gz
 
 ifeq ($(call need_pkg,"uuid >= 2.0.0"),)
@@ -8,16 +8,16 @@ PKGS_FOUND += uuid
 endif
 
 $(TARBALLS)/libuuid-$(UUID_VERSION).tar.gz:
-	$(call download,$(UUID_URL))
+	#$(call download,$(UUID_URL))
 
 .sum-uuid: libuuid-$(UUID_VERSION).tar.gz
 
 uuid: libuuid-$(UUID_VERSION).tar.gz .sum-uuid
-	$(UNPACK)
-	$(APPLY) $(SRC)/uuid/android.patch
-	$(MOVE)
+	#$(UNPACK)
+	#$(APPLY) $(SRC)/uuid/android.patch
+	#$(MOVE)
 
 .uuid: uuid
-	cd $< && $(HOSTVARS) ./configure $(HOSTCONF)
-	cd $< && $(MAKE) install
-	touch $@
+	#cd $< && $(HOSTVARS) ./configure $(HOSTCONF)
+	#cd $< && $(MAKE) install
+	#touch $@
