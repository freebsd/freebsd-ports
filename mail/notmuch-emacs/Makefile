# $FreeBSD$

CATEGORIES=	mail elisp
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

COMMENT=	Emacs major-mode for the Notmuch email search and tagging application

RUN_DEPENDS=	notmuch:mail/notmuch

USES=		emacs gmake

INSTALL_TARGET=	install-emacs
MAKE_ARGS+=	subdirs+=emacs
MASTERDIR=	${.CURDIR}/../notmuch
NO_ARCH=	yes

OPTIONS_DEFINE=	DESKTOP DOCS MANPAGES
OPTIONS_DEFAULT=	MANPAGES
OPTIONS_SUB=	yes

DESKTOP_DESC=	Install .desktop file for notmuch-emacs-mua

DESKTOP_MAKE_ARGS=	WITH_DESKTOP=1
DESKTOP_USES=	desktop-file-utils
DOCS_BUILD_DEPENDS=	sphinx-build:textproc/py-sphinx
DOCS_INFO=	notmuch-emacs
DOCS_USES=	makeinfo
MANPAGES_ALL_TARGET=	build-man
MANPAGES_BUILD_DEPENDS=	sphinx-build:textproc/py-sphinx
MANPAGES_INSTALL_TARGET=	install-man
MANPAGES_MAKE_ARGS=	subdirs+=doc

# fake ./configure to avoid unneeded dependencies
do-configure:
	@${CP} ${WRKSRC}/version ${WRKSRC}/version.stamp
	@${ECHO_CMD} 'quiet=$$($$(word 1, $$(1)))' > ${WRKSRC}/Makefile.local
	@${PRINTF} \
		'%s\n' \
		desktop_dir=${PREFIX}/share/applications \
		emacsetcdir=${PREFIX}/${EMACS_SITE_LISPDIR} \
		emacslispdir=${PREFIX}/${EMACS_SITE_LISPDIR} \
		HAVE_EMACS=1 \
		HAVE_SPHINX=1 \
		mandir=${MANPREFIX}/man \
		prefix=${PREFIX} \
		srcdir=. \
		WITH_EMACS=1 \
		> ${WRKSRC}/Makefile.config

do-build-DOCS-on:
	@${MAKE_CMD} -C ${WRKSRC} subdirs=doc sphinx-texinfo
	@${MAKE_CMD} -C ${WRKSRC}/doc/_build/texinfo MAKEINFO='${MAKEINFO} --no-split' info

do-install-DOCS-on:
	${INSTALL_MAN} ${WRKSRC}/doc/_build/texinfo/notmuch-emacs.info ${STAGEDIR}${PREFIX}/${INFO_PATH}

post-install:
	@${GZIP_CMD} ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/*.el

# keep poudriere testport happy
post-install-MANPAGES-on:
	@${FIND} ${STAGEDIR}${MANPREFIX}/man ! -type d ! -name notmuch-emacs-mua.1.gz -delete

.include "${MASTERDIR}/Makefile"

# modify what Mk/Uses/emacs.mk set
MAKE_ARGS+=	EMACS+=--quick
