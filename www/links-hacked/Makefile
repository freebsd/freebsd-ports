# Created by: Peter Vereshagin <peter@vereshagin.org>
# $FreeBSD$

PORTNAME=	links-hacked
DISTVERSION=	101110
PORTREVISION=	4
CATEGORIES?=	www
MASTER_SITES=	http://xray.sai.msu.ru/~karpov/links-hacked/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Hacked version of a Links WWW browser

LICENSE=	GPLv2

USES=		autoreconf execinfo
USE_OPENSSL=	yes
USE_CSTD=	gnu89
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-ssl --without-pmshell --without-atheos --without-fb

CFLAGS+=	-Wno-error=return-type
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lexecinfo

CONFLICTS=	links-[0-9]*

PLIST_FILES=	bin/links man/man1/links.1.gz

OPTIONS_DEFINE=		FORMSAVE FREETYPE JS
OPTIONS_RADIO=		GRAPHICS
OPTIONS_RADIO_GRAPHICS=	DIRECTFB SVGALIB X11
OPTIONS_DEFAULT=	FORMSAVE FREETYPE JS X11

DIRECTFB_DESC=		DirectFB driver support
DIRECTFB_LIB_DEPENDS=	libdirectfb-1.4.so:devel/directfb
DIRECTFB_CONFIGURE_WITH=	directfb
FORMSAVE_DESC=		Form saving/loading support
FORMSAVE_LIB_DEPENDS=	libgdbm.so:databases/gdbm
FORMSAVE_CONFIGURE_ENABLE=	form-saving
FREETYPE_LIB_DEPENDS=	libfreetype.so:print/freetype2
FREETYPE_CONFIGURE_WITH=	freetype
JS_DESC=		Javascript interpreter support (very basic)
JS_CONFIGURE_ENABLE=	javascript
SVGALIB_LIB_DEPENDS=	libvga.so:graphics/svgalib
SVGALIB_CONFIGURE_WITH=	svgalib
X11_USE=		xorg=x11,xproto
X11_CONFIGURE_WITH=	x

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDIRECTFB} || ${PORT_OPTIONS:MSVGALIB} || ${PORT_OPTIONS:MX11}
LIB_DEPENDS+=	libpng.so:graphics/png \
		libtiff.so:graphics/tiff
USES+=		jpeg
CONFIGURE_ARGS+=	--enable-graphics
.else
CONFIGURE_ARGS+=	--disable-graphics --without-libjpeg --without-libtiff
.endif

.if ${PORT_OPTIONS:MX11}
DESKTOP_ENTRIES="Links" \
		"Lynx-like hacked WWW browser" \
		"${PREFIX}/share/pixmaps/links.xpm" \
		"links -g" \
		"Network;WebBrowser;" \
		false
PLIST_FILES+=	share/pixmaps/links.xpm
.endif

post-install:
.if ${PORT_OPTIONS:MX11}
	(cd ${WRKSRC}/graphics && ${INSTALL_DATA} links.xpm \
		${STAGEDIR}${PREFIX}/share/pixmaps)
.endif

.include <bsd.port.mk>
