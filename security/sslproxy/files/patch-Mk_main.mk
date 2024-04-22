--- Mk/main.mk.orig	2022-12-26 01:44:45 UTC
+++ Mk/main.mk
@@ -302,11 +302,13 @@ endif
 		&& echo sqlite3)
 endif
 endif
+PKGS:=		$(PKGS)
 TPKGS:=		
 ifndef CHECK_BASE
 TPKGS+=		$(shell $(PKGCONFIG) $(PCFLAGS) --exists check \
 		&& echo check)
 endif
+TPKGS:=		$(TPKGS)
 
 # Function: Generate list of base paths to search when locating packages
 # $1 packagename
@@ -422,18 +424,24 @@ ifneq (,$(strip $(PKGS)))
 endif
 
 ifneq (,$(strip $(PKGS)))
-PKG_CFLAGS+=	$(shell $(PKGCONFIG) $(PCFLAGS) --cflags-only-other $(PKGS))
-PKG_CPPFLAGS+=	$(shell $(PKGCONFIG) $(PCFLAGS) --cflags-only-I $(PKGS))
-PKG_LDFLAGS+=	$(shell $(PKGCONFIG) $(PCFLAGS) --libs-only-L \
-		--libs-only-other $(PKGS))
-PKG_LIBS+=	$(shell $(PKGCONFIG) $(PCFLAGS) --libs-only-l $(PKGS))
+PKGS_CFLAGS!=	$(PKGCONFIG) $(PCFLAGS) --cflags-only-other $(PKGS)
+PKG_CFLAGS+=	$(PKGS_CFLAGS)
+PKGS_CPPFLAGS!=	$(PKGCONFIG) $(PCFLAGS) --cflags-only-I $(PKGS)
+PKG_CPPFLAGS+=	$(PKGS_CPPFLAGS)
+PKGS_LDFLAGS!=	$(PKGCONFIG) $(PCFLAGS) --libs-only-L --libs-only-other $(PKGS)
+PKG_LDFLAGS+=	$(PKGS_LDFLAGS)
+PKGS_LIBS!=	$(PKGCONFIG) $(PCFLAGS) --libs-only-l $(PKGS)
+PKG_LIBS+=	$(PKGS_LIBS)
 endif
 ifneq (,$(strip $(TPKGS)))
-TPKG_CFLAGS+=	$(shell $(PKGCONFIG) $(PCFLAGS) --cflags-only-other $(TPKGS))
-TPKG_CPPFLAGS+=	$(shell $(PKGCONFIG) $(PCFLAGS) --cflags-only-I $(TPKGS))
-TPKG_LDFLAGS+=	$(shell $(PKGCONFIG) $(PCFLAGS) --libs-only-L \
-		--libs-only-other $(TPKGS))
-TPKG_LIBS+=	$(shell $(PKGCONFIG) $(PCFLAGS) --libs-only-l $(TPKGS))
+TPKGS_CFLAGS!=	$(PKGCONFIG) $(PCFLAGS) --cflags-only-other $(TPKGS)
+TPKG_CFLAGS+=	$(TPKGS_CFLAGS)
+TPKGS_CPPFLAGS!=$(PKGCONFIG) $(PCFLAGS) --cflags-only-I $(TPKGS)
+TPKG_CPPFLAGS+=$(TPKGS_CPPFLAGS)
+TPKGS_LDFLAGS!=	$(PKGCONFIG) $(PCFLAGS) --libs-only-L --libs-only-other $(TPKGS)
+TPKG_LDFLAGS+=	$(TPKGS_LDFLAGS)
+TPKGS_LIBS!=	$(PKGCONFIG) $(PCFLAGS) --libs-only-l $(TPKGS)
+TPKG_LIBS+=	$(TPKGS_LIBS)
 endif
 
 CPPDEFS+=	-D_GNU_SOURCE \
