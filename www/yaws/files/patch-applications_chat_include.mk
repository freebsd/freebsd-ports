
$FreeBSD$

--- applications/chat/include.mk.orig
+++ applications/chat/include.mk
@@ -33,7 +33,7 @@
 
 
 # Hmm, don't know if you are supposed to like this better... ;-)
-APPSCRIPT = '$$vsn=shift; $$mods=""; while(@ARGV){ $$_=shift; s/^([A-Z].*)$$/\'\''$$1\'\''/; $$mods.=", " if $$mods; $$mods .= $$_; } while(<>) { s/\{vsn, git\}/\{vsn, $$vsn\}/; s/\{modules,\[\]\}/\{modules,\[$$mods\]\}/; print; }'
+APPSCRIPT = '$$vsn=shift; $$mods=""; while(@ARGV){ $$_=shift; s/^([A-Z].*)$$/\'\''$$1\'\''/; $$mods.=", " if $$mods; $$mods .= $$_; } while(<>) { s/\{vsn, git\}/\{vsn, "$$vsn"\}/; s/\{modules,\[\]\}/\{modules,\[$$mods\]\}/; print; }'
 
 # Targets
 
