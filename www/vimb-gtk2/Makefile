# $FreeBSD$

PORTNAME?=	vimb-gtk2
PORTVERSION=	2.12
CATEGORIES=	www

MAINTAINER=	mike.d.ft402@gmail.com
COMMENT=	Vim like browser

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS?=	libwebkitgtk-1.0.so:www/webkit-gtk2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libsoup-2.4.so:devel/libsoup

DEPRECATED=	Uses webkit-gtk2 which has security issues
EXPIRATION_DATE=2019-03-24

USES=		gmake pkgconfig
USE_GNOME?=	gtk20 cairo gdkpixbuf2

USE_GITHUB=	yes
GH_ACCOUNT=	fanglingsu
GH_PROJECT=	vimb
PLIST_FILES=	bin/vimb man/man1/vimb.1.gz

MAKE_ENV?=	GTK="2"

CONFLICTS?=	vimb-gtk3-*

OPTIONS_DEFINE=	HTML5 NOSCROLLBARS
OPTIONS_DEFAULT=	HTML5

HTML5_DESC=	HTML5 support
NOSCROLLBARS_DESC=	Disable scrollbars

HTML5_RUN_DEPENDS=	gstreamer1-libav>=1.6.3:multimedia/gstreamer1-libav\
	gstreamer1-plugins-good>=1.6.3:multimedia/gstreamer1-plugins-good

NOSCROLLBARS_CFLAGS+=	-DFEATURE_NO_SCROLLBARS

post-extract:
	${MV} ${WRKSRC}/src/config.def.h ${WRKSRC}/src/config.h

do-install:
	${INSTALL_MAN} ${WRKSRC}/doc/vimb.1 ${STAGEDIR}${MANPREFIX}/man/man1/
	${INSTALL_PROGRAM} ${WRKSRC}/src/vimb ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
