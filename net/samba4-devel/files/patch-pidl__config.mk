--- ./pidl/config.mk.orig	2010-01-11 05:35:28.000000000 +0000
+++ ./pidl/config.mk	2010-01-24 21:49:26.000000000 +0000
@@ -6,18 +6,6 @@
 pidl-testcov: $(pidldir)/Makefile
 	cd $(pidldir) && cover -test
 
-installpidl:: $(pidldir)/Makefile
-	@$(MAKE) -C $(pidldir) install_vendor VENDORPREFIX=$(prefix) \
-		                           INSTALLVENDORLIB=$(datarootdir)/perl5 \
-								   INSTALLVENDORBIN=$(bindir) \
-								   INSTALLVENDORSCRIPT=$(bindir) \
-								   INSTALLVENDORMAN1DIR=$(mandir)/man1 \
-								   INSTALLVENDORMAN3DIR=$(mandir)/man3
-
-ifeq ($(HAVE_PERL_EXTUTILS_MAKEMAKER),1)
-install:: installpidl
-endif
-
 $(pidldir)/lib/Parse/Pidl/IDL.pm: $(pidldir)/idl.yp
 	-$(YAPP) -m 'Parse::Pidl::IDL' -o $(pidldir)/lib/Parse/Pidl/IDL.pm $(pidldir)/idl.yp ||\
 		touch $(pidldir)/lib/Parse/Pidl/IDL.pm 
