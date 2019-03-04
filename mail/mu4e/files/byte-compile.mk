# $FreeBSD$
.el.elc:
	if test '$(EMACS)' != no; then \
	  am__dir=. am__subdir_includes=''; \
	  case $@ in */*) \
	    am__dir=`echo '$@' | sed 's,/[^/]*$$,,'`; \
	    am__subdir_includes="-L $$am__dir -L $(srcdir)/$$am__dir"; \
	  esac; \
	  test -d "$$am__dir" || $(MKDIR_P) "$$am__dir" || exit 1; \
	  $(EMACS) --batch \
	    $(AM_ELCFLAGS) $(ELCFLAGS) \
	    $$am__subdir_includes -L $(builddir) -L $(srcdir) \
	    --eval '(setq byte-compile-dest-file-function (lambda (_) "/tmp/$@"))' \
	    -f batch-byte-compile '$<'; \
	    if [ -f "/tmp/$@" ]; then \
		cp /tmp/$@ $@ && rm -f /tmp/$@; \
	    fi; \
	else :; fi
