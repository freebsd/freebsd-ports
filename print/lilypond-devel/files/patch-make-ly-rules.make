--- make/ly-rules.make.orig	Tue Sep 23 20:50:18 2003
+++ make/ly-rules.make	Thu Sep 25 10:37:07 2003
@@ -33,7 +33,7 @@
 
 # nfo: info from non-lily texi
 $(outdir)/%.info: $(outdir)/%.nexi
-	$(MAKEINFO) --output=$(outdir)/$(*F).info $<
+	$(MAKEINFO) --no-split --output=$(outdir)/$(*F).info $<
 
 # nfo: info from non-lily texi
 #$(outdir)/%.nfo: $(outdir)/%.nexi
