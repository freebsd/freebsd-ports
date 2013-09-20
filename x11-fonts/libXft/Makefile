# $FreeBSD$

PORTNAME=	libXft
PORTVERSION=	2.3.1
CATEGORIES=	x11-fonts

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Client-sided font API for X applications

LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2
BUILD_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig
RUN_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig

XORG_CAT=	lib
USE_XORG=	xproto:both xrender

MAN3=		Xft.3

NO_STAGE=	yes
post-extract:
	@${CP} ${FILESDIR}/xft-config.in \
		${WRKSRC}/xft-config.in

post-patch:
	@${REINPLACE_CMD} -e '/ac_config_files/s|xft\.pc|xft\.pc xft-config|' \
	    	${WRKSRC}/configure

post-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/xft-config \
		${PREFIX}/bin/

.include <bsd.port.mk>
