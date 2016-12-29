--- man/pod2man.mk.orig	2016-08-15 17:36:10 UTC
+++ man/pod2man.mk
@@ -36,7 +36,6 @@ RELEASE         ?= $(PACKAGE)
 
 # Optional variables to set
 MANSECT		?= 1
-PODCENTER	?= $$(date "+%Y-%m-%d")
 
 # Directories
 MANSRC		=
@@ -46,7 +45,6 @@ MANPOD		= $(MANSRC)$(PACKAGE).$(MANSECT)
 MANPAGE		= $(MANDEST)$(PACKAGE).$(MANSECT)
 
 POD2MAN		= pod2man
-POD2MAN_FLAGS	= --utf8
 
 makeman: $(MANPAGE)
 
@@ -54,12 +52,9 @@ $(MANPAGE): $(MANPOD)
 	# make target - create manual page from a *.pod page
 	podchecker $(MANPOD)
 	LC_ALL=C $(POD2MAN) $(POD2MAN_FLAGS) \
-		--center="$(PODCENTER)" \
+		--center=" " \
 		--name="$(PACKAGE)" \
 		--section="$(MANSECT)" \
                 --release="$(RELEASE)" \
 		$(MANPOD) \
-	        > $(MANPAGE) && \
-	rm -f pod*.tmp
-
-# End of of Makefile part
+	        > $(MANPAGE)
