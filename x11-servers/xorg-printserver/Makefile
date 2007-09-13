# New ports collection makefile for:    xorg-printserver
# Date created:		17 June 2004
# Whom:			anholt@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	xorg-printserver
PORTVERSION=	1.2.0
PORTEPOCH=	1
CATEGORIES=	x11-servers

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X Print server from X.Org

CONFLICTS=	XFree86-PrintServer-*

DEPRECATED=	is obsolete
EXPIRATION_DATE=	2007-12-25
IGNORE=		${DEPRECATED}

XORG_CAT=	xserver

LIB_DEPENDS=	drm:${PORTSDIR}/graphics/libdrm
BUILD_DEPENDS=	mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale

USE_XORG=	x11 xf86driproto glproto randrproto renderproto fixesproto \
		damageproto xcmiscproto xextproto xf86miscproto \
		xf86vidmodeproto xf86bigfontproto scrnsaverproto bigreqsproto \
		resourceproto fontsproto xf86dgaproto videoproto \
		compositeproto trapproto recordproto resourceproto \
		xineramaproto evieproto xkbfile xfont fontenc xkbui \
		xxf86misc xxf86vm xaw7 xmu xpm xext

CONFIGURE_ARGS=	--disable-dmx --disable-xvfb --disable-xorg --disable-xnest \
		--localstatedir=/var

MAN1=		Xprt.1

do-install:
	cd ${WRKSRC}/hw/xprint; ${MAKE} install

.include <bsd.port.mk>
