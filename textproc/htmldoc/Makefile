PORTNAME=	htmldoc
PORTVERSION=	1.9.16
DISTVERSIONPREFIX=	v
CATEGORIES=	textproc

MAINTAINER=	fuz@fuz.su
COMMENT=	Converts HTML to PDF and/or PostScript

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_mips=	complains about expecting ) before png_ptr

LIB_DEPENDS=	libpng.so:graphics/png

USES=		compiler:c11 cpe jpeg pkgconfig
CPE_VENDOR=	${PORTNAME}_project
USE_GITHUB=	yes
GH_ACCOUNT=	michaelrsweet

HAS_CONFIGURE=	yes

OPTIONS_DEFINE=		GNUTLS HTMLDOCGUI
OPTIONS_DEFAULT=	GNUTLS

HTMLDOCGUI_DESC=	Build GUI front-end

GNUTLS_LIB_DEPENDS=		libgnutls.so:security/gnutls
GNUTLS_CONFIGURE_ENABLE=	gnutls

HTMLDOCGUI_LIB_DEPENDS=		libfltk.so:x11-toolkits/fltk \
				libfontconfig.so:x11-fonts/fontconfig
HTMLDOCGUI_USES=		xorg
HTMLDOCGUI_USE=			XORG=x11,xcursor,xext,xfixes,xft,xinerama,xrender
HTMLDOCGUI_CONFIGURE_WITH=	gui=yes

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/htmldoc

.include <bsd.port.mk>
