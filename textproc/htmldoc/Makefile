# Created by: Glenn Trewitt <glenn@trewitt.org>
# $FreeBSD$

PORTNAME=		htmldoc
PORTVERSION=		1.9.3
DISTVERSIONPREFIX=	v
CATEGORIES=		textproc

MAINTAINER=	jose@diasfernandes.pt
COMMENT=	Converts HTML to PDF and/or PostScript

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_mips=	Complains of expecting ) before png_ptr

LIB_DEPENDS=	libpng.so:graphics/png

USES=		compiler:c11
USE_GITHUB=	yes
GH_ACCOUNT=	michaelrsweet

HAS_CONFIGURE=	yes
MAKE_ARGS=	mandir="${MANDIRS}"

OPTIONS_DEFINE=		HTMLDOCGUI GNUTLS
OPTIONS_DEFAULT=	GNUTLS

HTMLDOCGUI_DESC=	Build GUI front-end
HTMLDOCGUI_CONFIGURE_WITH=	gui=yes
HTMLDOCGUI_LIB_DEPENDS=		libfltk.so:x11-toolkits/fltk \
				libfontconfig.so:x11-fonts/fontconfig
HTMLDOCGUI_USE=			XORG=x11,xrender,xcursor,xfixes \
				xext,xft,xinerama jpeg
GNUTLS_CONFIGURE_ENABLE=	gnutls
GNUTLS_USES=			pkgconfig
GNUTLS_LIB_DEPENDS=		libgnutls.so:security/gnutls

.include <bsd.port.pre.mk>

# Fix arm64 build
.if ${ARCH} == "aarch64"
pre-build:
	${REINPLACE_CMD} -e '/PNG_FILTER_OPTIMIZATIONS(pp, bpp);/d' ${WRKSRC}/png/pngrutil.c
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/htmldoc

.include <bsd.port.post.mk>
