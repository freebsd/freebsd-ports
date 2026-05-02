PORTNAME=	pdf-tools
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.0
PORTREVISION=	2
CATEGORIES=	print elisp
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Emacs support library for PDF files
WWW=		https://github.com/vedang/pdf-tools

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpng16.so:graphics/png \
		libpoppler-glib.so:graphics/poppler-glib \
		libpoppler.so:graphics/poppler
RUN_DEPENDS=	tablist>=0.70:devel/tablist

USES=		autoreconf:build emacs:build gettext-runtime gmake gnome \
		magick:7,build,run pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	vedang
USE_GNOME=	cairo glib20

CONFLICTS_INSTALL=	pdf-tools-emacs_*

do-build:
	cd ${WRKSRC}/server && ./autogen.sh && \
		${CONFIGURE_ENV} ./configure -q && ${MAKE_CMD}
	${EMACS_CMD} -q --batch -f loaddefs-generate-batch \
		${WRKSRC}/lisp/${PORTNAME}-loaddefs.el ${WRKSRC}/lisp

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/${PORTNAME}
	${INSTALL_PROGRAM} ${WRKSRC}/server/epdfinfo ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/lisp/* ${FILESDIR}/${PORTNAME}-init.el \
		${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/${PORTNAME}

.include <bsd.port.mk>
