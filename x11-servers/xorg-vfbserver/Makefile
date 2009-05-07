# New ports collection makefile for:    xorg-vfbserver
# Date created:		17 June 2004
# Whom:			anholt@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	xorg-vfbserver
PORTVERSION=	1.6.1
PORTEPOCH=	1
CATEGORIES=	x11-servers

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X virtual framebuffer server from X.Org

CONFLICTS=	XFree86-VirtualFramebufferServer-*

XORG_CAT=	xserver

LIB_DEPENDS=	drm:${PORTSDIR}/graphics/libdrm

USE_GL=		gl
USE_XORG=	x11 xf86driproto glproto randrproto renderproto fixesproto \
		damageproto xcmiscproto xextproto xf86miscproto inputproto \
		xf86vidmodeproto xf86bigfontproto scrnsaverproto bigreqsproto \
		dri2proto resourceproto fontsproto xf86dgaproto videoproto \
		compositeproto trapproto recordproto resourceproto \
		xineramaproto xinerama evieproto xkbfile xfont fontenc \
		xkbui xxf86misc xxf86vm xaw7 xmu xpm xext pixman xtrans

USE_OPENSSL=	yes
CONFIGURE_ARGS=	--disable-dmx --disable-xnest --disable-xorg \
		--localstatedir=/var --without-dtrace

PLIST_FILES=	bin/Xvfb
MAN1=		Xvfb.1

do-install:
	cd ${WRKSRC}/hw/vfb; ${MAKE} install

.include <bsd.port.pre.mk>

.if defined(WITH_OPENSSL_BASE)
# The reason why I use this is cause openssl from base doesn't install a .pc file
# and configure will fail trying to find it. Setting both of those variables to
# a *non-empty* value by-passes the pkg-config check.
CONFIGURE_ENV=	SHA1_LIB="-L/usr/lib -lcrypto" SHA1_CFLAGS="-I/usr/include"
.endif

.include <bsd.port.post.mk>
