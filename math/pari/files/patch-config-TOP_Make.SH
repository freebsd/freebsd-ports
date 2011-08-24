$FreeBSD$

--- config/TOP_Make.SH.orig	2011-07-12 17:57:15.000000000 +0900
+++ config/TOP_Make.SH	2011-07-12 17:57:33.000000000 +0900
@@ -42,7 +42,6 @@
 
 all::
 	@\$(MAKE) gp
-	@-cd doc && \$(MAKE) doc
 
 gp bench test-kernel test-all $top_test_extra $top_dotest_extra install cleanall cleanobj cleantest install-bin install-doc install-docpdf install-data install-lib-sta install-bin-sta dobench dyntest-all statest-all tune::
 	@dir=\`config/objdir\`; echo "Making \$@ in \$\$dir";\\
