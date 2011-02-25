# New ports collection makefile for:    xorg-dmx
# Date created:		13 Mar 2005
# Whom:			lesi@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	xorg-dmx
PORTVERSION=	1.7.7
PORTEPOCH=	1
CATEGORIES=	x11-servers

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Distributed Multihead X from X.Org

XORG_CAT=	xserver

LIB_DEPENDS=	drm:${PORTSDIR}/graphics/libdrm

USE_GL=		gl
USE_XORG=	x11 xf86driproto glproto randrproto renderproto fixesproto \
		dri2proto damageproto xcmiscproto xextproto xf86miscproto \
		xf86vidmodeproto xf86bigfontproto scrnsaverproto bigreqsproto \
		resourceproto fontsproto xf86dgaproto videoproto \
		compositeproto trapproto recordproto resourceproto \
		xineramaproto xinerama evieproto xkbfile xfont fontenc xkbui \
		xxf86misc xxf86vm xaw7 xmu xpm xext xrender xfixes xi dmxproto \
		xau dmx xtst xres pixman xtrans

USE_OPENSSL=	yes
CONFIGURE_ARGS=	--disable-xvfb --disable-xorg --disable-xnest \
		--enable-dmx --localstatedir=/var --without-dtrace

MAN1=		Xdmx.1 dmxtodmx.1 vdltodmx.1 xdmxconfig.1

do-install:
	cd ${WRKSRC}/hw/dmx; ${MAKE} install

OPTIONS=	HAL     "Compile with HAL config support" on

.include <bsd.port.pre.mk>

.if defined(WITH_OPENSSL_BASE)
# The reason why I use this is cause openssl from base doesn't install a .pc file
# and configure will fail trying to find it. Setting both of those variables to
# a *non-empty* value by-passes the pkg-config check.
CONFIGURE_ENV=	SHA1_LIB="-L/usr/lib -lcrypto" SHA1_CFLAGS="-I/usr/include"
.endif

.if !defined(WITHOUT_HAL)
LIB_DEPENDS+=		hal.1:${PORTSDIR}/sysutils/hal
CONFIGURE_ARGS+=	--enable-config-hal=yes
.else
CONFIGURE_ARGS+=	--enable-config-hal=no
.endif

.include <bsd.port.post.mk>
