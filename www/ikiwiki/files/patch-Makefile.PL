--- Makefile.PL.orig	2025-06-15 07:46:52 UTC
+++ Makefile.PL
@@ -62,24 +62,20 @@ perl_shebangs: pm_to_blib
 	$(PERL) -Iblib/lib $(extramodules) $(tflag) ikiwiki.in --setup docwiki.setup --refresh
 
 perl_shebangs: pm_to_blib
-ifneq "$(PERL)" "/usr/bin/perl"
 	set -e; \
 	for file in $(shebang_scripts); do \
 		$(PERL) -pe "s|^#!/usr/bin/perl\b|#!$(PERL)| if 1" < $$file > "$$file.new"; \
 		[ -x $$file ] && chmod +x "$$file.new"; \
 		mv -f "$$file.new" $$file; \
 	done
-endif
 
 perl_shebangs_clean:
-ifneq "$(PERL)" "/usr/bin/perl"
 	set -e; \
 	for file in $(shebang_scripts); do \
 		$(PERL) -pe "s|^#!$(PERL)\b|#!/usr/bin/perl| if 1" < $$file > "$$file.new"; \
 		[ -x $$file ] && chmod +x "$$file.new"; \
 		mv -f "$$file.new" $$file; \
 	done
-endif
 
 sysconfdir:
 	$(PERL) -pi -e "s|\"/etc/ikiwiki|\"$(SYSCONFDIR)|g" $(sysconfdir_scripts)
