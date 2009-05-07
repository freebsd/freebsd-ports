# New ports collection makefile for:	xephyr
# Date created:				2008-05-18
# Whom:					Max Brazhnikov <makc@issp.ac.ru>
#
# $FreeBSD$
#

PORTNAME=	xephyr
PORTVERSION=	1.6.1
CATEGORIES=	x11-servers

MAINTAINER=	x11@FreeBSD.org
COMMENT=	A kdrive based X server from X.Org

XORG_CAT=	xserver

LIB_DEPENDS=	drm:${PORTSDIR}/graphics/libdrm

USE_GL=		gl
USE_XORG=	x11 xf86driproto glproto randrproto renderproto fixesproto \
		dri2proto damageproto xcmiscproto xtrans inputproto \
		xf86bigfontproto scrnsaverproto bigreqsproto \
		resourceproto fontsproto videoproto \
		compositeproto trapproto recordproto \
		xineramaproto xinerama evieproto xkbfile xfont \
		xau xdmcp xext fontenc xv pixman

USE_OPENSSL=	yes
CONFIGURE_ARGS=	--enable-kdrive --enable-xephyr	--disable-dmx --disable-xvfb \
		--disable-xorg --disable-xnest \
		--localstatedir=/var --without-dtrace

PLIST_FILES=	bin/Xephyr

OPTIONS=	HAL	"Compile with HAL config support" on

.include <bsd.port.pre.mk>

.if defined(WITH_OPENSSL_BASE)
# The reason why I use this is cause openssl from base doesn't install a .pc file
# and configure will fail trying to find it. Setting both of those variables to
# a *non-empty* value by-passes the pkg-config check.
CONFIGURE_ENV=	SHA1_LIB="-L/usr/lib -lcrypto" SHA1_CFLAGS="-I/usr/include"
.endif

.if !defined(WITHOUT_HAL)
LIB_DEPENDS+=	hal.1:${PORTSDIR}/sysutils/hal
CONFIGURE_ARGS+=	--enable-config-hal=yes
.else
CONFIGURE_ARGS+=	--enable-config-hal=no
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hw/kdrive/ephyr/Xephyr ${PREFIX}/bin/

.include <bsd.port.post.mk>
