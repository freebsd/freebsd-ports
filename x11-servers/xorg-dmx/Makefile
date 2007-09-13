# New ports collection makefile for:    xorg-dmx
# Date created:		13 Mar 2005
# Whom:			lesi@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	xorg-dmx
PORTVERSION=	1.4
PORTEPOCH=	1
CATEGORIES=	x11-servers

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Distributed Multihead X from X.Org

CONFLICTS=	XFree86-dmx-[0-9]*

XORG_CAT=	xserver

LIB_DEPENDS=	drm:${PORTSDIR}/graphics/libdrm
USE_XORG=	x11 xf86driproto glproto randrproto renderproto fixesproto \
		damageproto xcmiscproto xextproto xf86miscproto \
		xf86vidmodeproto xf86bigfontproto scrnsaverproto bigreqsproto \
		resourceproto fontsproto xf86dgaproto videoproto \
		compositeproto trapproto recordproto resourceproto \
		xineramaproto evieproto xkbfile xfont fontenc xkbui \
		xxf86misc xxf86vm xaw7 xmu xpm xext xrender xfixes xi dmxproto \
		xau dmx xtst xres pixman
		
CONFIGURE_ARGS=	--disable-xprint --disable-xvfb --disable-xorg --disable-xnest \
		--enable-dmx --localstatedir=/var

MAN1=		Xdmx.1 dmxtodmx.1 vdltodmx.1 xdmxconfig.1

do-install:
	cd ${WRKSRC}/hw/dmx; ${MAKE} install

.include <bsd.port.mk>
