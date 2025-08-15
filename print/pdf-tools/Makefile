PORTNAME=	pdf-tools
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.0
PORTREVISION=	14
CATEGORIES=	print elisp
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Emacs support library for PDF files
WWW=		https://github.com/vedang/pdf-tools

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	cask${EMACS_PKGNAMESUFFIX}>0:devel/cask@${EMACS_FLAVOR} \
		tablist${EMACS_PKGNAMESUFFIX}>=0.70.4:devel/tablist@${EMACS_FLAVOR}
LIB_DEPENDS=	libpng.so:graphics/png \
		libpoppler-glib.so:graphics/poppler-glib \
		libpoppler.so:graphics/poppler
RUN_DEPENDS=	tablist${EMACS_PKGNAMESUFFIX}>=0.70:devel/tablist@${EMACS_FLAVOR}

USES=		autoreconf:build emacs gettext-runtime gmake gnome magick:7
USE_GITHUB=	yes
GH_ACCOUNT=	vedang
USE_GNOME=	cairo glib20

EMACS_FLAVORS_EXCLUDE=	devel_nox nox

CONFLICTS_INSTALL=	pdf-tools pdf-tools-emacs_* # bin/epdfinfo

do-build:
	cd ${WRKSRC}/server && ./autogen.sh && ./configure -q && make
	${EMACS_CMD} -q --batch -L ${WRKSRC}/lisp -f batch-byte-compile \
		${WRKSRC}/lisp/*.el
	 ${EMACS_CMD} -q --batch -f loaddefs-generate-batch \
		${WRKSRC}/lisp/${PORTNAME}-loaddefs.el ${WRKSRC}/lisp

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/${PORTNAME}
	${INSTALL_PROGRAM} ${WRKSRC}/server/epdfinfo ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/lisp/* ${FILESDIR}/${PORTNAME}-init.el \
		${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/${PORTNAME}

.include <bsd.port.mk>
