# $FreeBSD$

PORTNAME=	libXft
PORTVERSION=	2.3.2
PORTREVISION=	1
CATEGORIES=	x11-fonts

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Client-sided font API for X applications

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig

XORG_CAT=	lib
USE_XORG=	xproto:both xrender
INSTALL_TARGET=	install-strip

post-extract:
	@${CP} ${FILESDIR}/xft-config.in \
		${WRKSRC}/xft-config.in

post-patch:
	@${REINPLACE_CMD} -e '/ac_config_files/s|xft\.pc|xft\.pc xft-config|' \
		${WRKSRC}/configure

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/xft-config \
		${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
