# $FreeBSD$

PORTNAME=	libXft
PORTVERSION=	2.3.1
CATEGORIES=	x11-fonts

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Client-sided font API for X applications

LIB_DEPENDS=	libfreetype.so:${PORTSDIR}/print/freetype2 \
		libfontconfig.so:${PORTSDIR}/x11-fonts/fontconfig

XORG_CAT=	lib
USE_XORG=	xproto:both xrender

post-extract:
	@${CP} ${FILESDIR}/xft-config.in \
		${WRKSRC}/xft-config.in

post-patch:
	@${REINPLACE_CMD} -e '/ac_config_files/s|xft\.pc|xft\.pc xft-config|' \
	    	${WRKSRC}/configure

post-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/xft-config \
		${STAGEDIR}${PREFIX}/bin/
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libXft.so.2

.include <bsd.port.mk>
