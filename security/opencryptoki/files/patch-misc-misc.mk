--- misc/misc.mk.orig	2018-11-16 14:53:03 UTC
+++ misc/misc.mk
@@ -39,14 +39,5 @@ ${srcdir}/misc/tmpfiles.conf: ${srcdir}/misc/tmpfiles.
 	$(foreach TOK,$(TOKENS),\
 		echo "D $(lockdir)/$(TOK) 0770 root pkcs11 -" >> $@-t;)
 	mv $@-t $@
-else
-initddir = $(sysconfdir)/rc.d/init.d
-initd_SCRIPTS = misc/pkcsslotd
-
-CLEANFILES += misc/pkcsslotd
-${srcdir}/misc/pkcsslotd: ${srcdir}/misc/pkcsslotd.in
-	@SED@ -e s!\@sbindir\@!"@sbindir@"!g < $< > $@-t
-	@CHMOD@ a+x $@-t
-	mv $@-t $@
 endif
 endif
