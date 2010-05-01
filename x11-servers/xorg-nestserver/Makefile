# New ports collection makefile for:    xorg-nestserver
# Date created:		21 July 2004
# Whom:			anholt@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	xorg-nestserver
PORTVERSION=	1.7.5
PORTEPOCH=	1
CATEGORIES=	x11-servers

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Nesting X server from X.Org

CONFLICTS=	XFree86-NestServer-*

XORG_CAT=	xserver

LIB_DEPENDS=	drm:${PORTSDIR}/graphics/libdrm

USE_GL=		gl
USE_XORG=	x11 xf86driproto glproto randrproto renderproto fixesproto \
		damageproto xcmiscproto xextproto xf86miscproto inputproto \
		xf86vidmodeproto xf86bigfontproto scrnsaverproto bigreqsproto \
		dri2proto resourceproto fontsproto xf86dgaproto videoproto \
		compositeproto trapproto recordproto resourceproto \
		xineramaproto xinerama evieproto xkbfile xfont fontenc xkbui \
		xxf86misc xxf86vm xaw7 xmu xpm xext pixman xtrans

USE_OPENSSL=	yes
CONFIGURE_ARGS=	--disable-dmx --disable-xvfb --disable-xorg \
		--localstatedir=/var --without-dtrace

PLIST_FILES=	bin/Xnest
MAN1=		Xnest.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hw/xnest/Xnest ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/hw/xnest/Xnest.1 ${PREFIX}/man/man1/

.include <bsd.port.pre.mk>

.if defined(WITH_OPENSSL_BASE)
# The reason why I use this is cause openssl from base doesn't install a .pc file
# and configure will fail trying to find it. Setting both of those variables to
# a *non-empty* value by-passes the pkg-config check.
CONFIGURE_ENV=	SHA1_LIB="-L/usr/lib -lcrypto" SHA1_CFLAGS="-I/usr/include"
.endif

.include <bsd.port.post.mk>
