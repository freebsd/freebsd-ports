--- src/cfgparser/local.mk.orig	2019-08-11 08:09:47 UTC
+++ src/cfgparser/local.mk
@@ -74,12 +74,9 @@ $(C)oparse.c: $(C)oparse.y $(C)olsrd_conf.h $(C)Makefi
 ifeq ($(VERBOSE),0)
 	@echo "[BISON] $@"
 endif
-	$(MAKECMDPREFIX)$(BISON) -d -o "$@-tmp" "$<"
-	$(MAKECMDPREFIX)sed	-e 's/register //' \
-		-e '/^#line/s/$(call quote,$@-tmp)/$(call quote,$@)/' \
-		< "$@-tmp" >"$@"
-	$(MAKECMDPREFIX)mv "$(subst .c,.h,$@-tmp)" "$(subst .c,.h,$@)"
-	$(MAKECMDPREFIX)$(RM) "$@-tmp" "$(subst .c,.h,$@-tmp)"
+	$(MAKECMDPREFIX)$(BISON) -d -o "$@" "$<"
+	$(MAKECMDPREFIX)sed -e 's/register //' < "$@" >"$@.o"
+	$(MAKECMDPREFIX)mv "$@.o" "$@"
 
 $(C)oparse.o: CFLAGS := $(filter-out -Wunreachable-code,$(CFLAGS))
 
