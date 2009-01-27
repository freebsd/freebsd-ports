# New ports collection makefile for:    xorg-dmx
# Date created:		13 Mar 2005
# Whom:			lesi@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	xorg-dmx
PORTVERSION=	1.5.3
PORTEPOCH=	1
PORTREVISION=	1
CATEGORIES=	x11-servers

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Distributed Multihead X from X.Org

CONFLICTS=	XFree86-dmx-[0-9]*

XORG_CAT=	xserver

LIB_DEPENDS=	drm:${PORTSDIR}/graphics/libdrm

USE_GL=		gl
USE_XORG=	x11 xf86driproto glproto randrproto renderproto fixesproto \
		dri2proto damageproto xcmiscproto xextproto xf86miscproto \
		xf86vidmodeproto xf86bigfontproto scrnsaverproto bigreqsproto \
		resourceproto fontsproto xf86dgaproto videoproto \
		compositeproto trapproto recordproto resourceproto \
		xineramaproto evieproto xkbfile xfont fontenc xkbui \
		xxf86misc xxf86vm xaw7 xmu xpm xext xrender xfixes xi dmxproto \
		xau dmx xtst xres pixman xtrans
		
CONFIGURE_ARGS=	--disable-xprint --disable-xvfb --disable-xorg --disable-xnest \
		--enable-dmx --localstatedir=/var --without-dtrace

MAN1=		Xdmx.1 dmxtodmx.1 vdltodmx.1 xdmxconfig.1

do-install:
	cd ${WRKSRC}/hw/dmx; ${MAKE} install

OPTIONS=        HAL     "Compile with HAL config support" on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_HAL)
LIB_DEPENDS+=   hal.1:${PORTSDIR}/sysutils/hal
CONFIGURE_ARGS+=	--enable-config-hal=yes
.else
CONFIGURE_ARGS+=	--enable-config-hal=no
.endif

.include <bsd.port.post.mk>
