PORTNAME=	htmldoc
DISTVERSIONPREFIX=	v
DISTVERSION=	1.9.21
CATEGORIES=	textproc

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	Converts HTML to PDF and/or PostScript
WWW=		https://michaelrsweet.github.io/htmldoc

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_mips=	complains about expecting ) before png_ptr

LIB_DEPENDS=	libcups.so:print/cups \
		libpng16.so:graphics/png

USES=		compiler:c11 cpe jpeg pkgconfig
CPE_VENDOR=	htmldoc_project
USE_GITHUB=	yes
GH_ACCOUNT=	michaelrsweet

HAS_CONFIGURE=	yes

OPTIONS_DEFINE=		HTMLDOCGUI
HTMLDOCGUI_DESC=	Build GUI front-end
HTMLDOCGUI_LIB_DEPENDS=		libfltk.so:x11-toolkits/fltk \
				libfontconfig.so:x11-fonts/fontconfig
HTMLDOCGUI_USES=		xorg
HTMLDOCGUI_USE=			XORG=x11,xcursor,xext,xfixes,xft,xinerama,xpm,xrender
HTMLDOCGUI_CONFIGURE_WITH=	gui=yes

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/htmldoc

.include <bsd.port.mk>
