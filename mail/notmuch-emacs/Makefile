# $FreeBSD$

PORTREVISION=	1
CATEGORIES=	mail elisp
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

COMMENT=	Emacs major-mode for the Notmuch email search and tagging application

LICENSE=	GPLv3

RUN_DEPENDS=	notmuch:mail/notmuch

USES=		emacs gmake

INSTALL_TARGET=	install-emacs
MASTERDIR=	${.CURDIR}/../notmuch
NO_ARCH=	yes

OPTIONS_DEFINE=	DESKTOP DOCS MANPAGES
OPTIONS_DEFAULT=	MANPAGES
OPTIONS_SUB=	yes

DESKTOP_DESC=	Install .desktop file for notmuch-emacs-mua

DESKTOP_CONFIGURE_ON=	WITH_DESKTOP=1
DESKTOP_USES=	desktop-file-utils
DOCS_ALL_TARGET=	build-info
DOCS_BUILD_DEPENDS=	sphinx-build:textproc/py-sphinx
DOCS_CONFIGURE_ON=	HAVE_INSTALL_INFO=1 HAVE_MAKEINFO=1 HAVE_SPHINX=1
DOCS_INFO=	notmuch-emacs
DOCS_INSTALL_TARGET=	install-info
DOCS_USES=	makeinfo
MANPAGES_ALL_TARGET=	build-man
MANPAGES_BUILD_DEPENDS=	sphinx-build:textproc/py-sphinx
MANPAGES_CONFIGURE_ON=	HAVE_SPHINX=1
MANPAGES_INSTALL_TARGET=	install-man

# fake ./configure to avoid unneeded dependencies
do-configure:
	@${CP} ${WRKSRC}/version ${WRKSRC}/version.stamp
	@${ECHO_CMD} 'quiet=$$($$(word 1, $$(1)))' > ${WRKSRC}/Makefile.local
	@${PRINTF} \
		'%s\n' \
		BASH_ABSOLUTE=/bin/sh \
		desktop_dir=${PREFIX}/share/applications \
		emacsetcdir=${PREFIX}/${EMACS_SITE_LISPDIR} \
		emacslispdir=${PREFIX}/${EMACS_SITE_LISPDIR} \
		HAVE_BASH=1 \
		HAVE_EMACS=1 \
		infodir=${PREFIX}/${INFO_PATH} \
		mandir=${MANPREFIX}/man \
		NOTMUCH_SRCDIR=${WRKSRC} \
		prefix=${PREFIX} \
		srcdir=. \
		subdirs='doc emacs' \
		WITH_EMACS=1 \
		${CONFIGURE_ARGS} \
		> ${WRKSRC}/Makefile.config

post-install:
	@${GZIP_CMD} ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/*.el

# keep poudriere testport happy
post-install-DOCS-on:
	@${FIND} ${STAGEDIR}${PREFIX}/${INFO_PATH} ! -type d ! -name notmuch-emacs.info -delete

post-install-MANPAGES-on:
	@${FIND} ${STAGEDIR}${MANPREFIX}/man ! -type d ! -name notmuch-emacs-mua.1.gz -delete

# modify what Mk/Uses/emacs.mk set
MAKE_ARGS+=	EMACS+=--quick

.include "${MASTERDIR}/Makefile"
