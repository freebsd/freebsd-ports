--- fdep/fortran_dependencies.mk.orig	2026-04-10 00:39:59 UTC
+++ fdep/fortran_dependencies.mk
@@ -64,12 +64,12 @@ $(call modinfo_name,$1,$2,$3,use): $1 $(dir $1)$(am__d
 define module_targets
 $(eval _$(3)_use_mods += $(call modinfo_name,$1,$2,$3,use))
 $(call modinfo_name,$1,$2,$3,use): $1 $(dir $1)$(am__dirstamp)
-	$(call _f90_verbose,F90 USE  [$3] $$<)$(FORTRAN_CPP) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $($p_CPPFLAGS) $(CPPFLAGS) -o /dev/stdout $$< | \
+	$(call _f90_verbose,F90 USE  [$3] $$<)$(FORTRAN_CPP) $(DEFS) $(DEFAULT_INCLUDES) -I$(abs_builddir) $(INCLUDES) $($p_CPPFLAGS) $(CPPFLAGS) -o /dev/stdout $$< | \
 		grep -i -o '^ *use [^ ,!:]*' | sed 's/^[[:space:]]*//;' | tr '[:upper:]' '[:lower:]' | sort -u > $$@
 
 $(eval _$(3)_def_mods += $(call modinfo_name,$1,$2,$3,def))
 $(call modinfo_name,$1,$2,$3,def): $1 $(dir $1)$(am__dirstamp)
-	$(call _f90_verbose,F90 MOD  [$3] $$<)$(FORTRAN_CPP) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $($p_CPPFLAGS) $(CPPFLAGS) -o /dev/stdout $$< | \
+	$(call _f90_verbose,F90 MOD  [$3] $$<)$(FORTRAN_CPP) $(DEFS) $(DEFAULT_INCLUDES) -I$(abs_builddir) $(INCLUDES) $($p_CPPFLAGS) $(CPPFLAGS) -o /dev/stdout $$< | \
 		grep -i -o '^ *module [^!]*' | sed 's/^[[:space:]]*//;' | tr '[:upper:]' '[:lower:]' | grep -v "\<procedure\>\|\<intrinsic\>" > $$@ || true
 
 endef
