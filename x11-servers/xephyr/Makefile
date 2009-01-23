# New ports collection makefile for:	xephyr
# Date created:				2008-05-18
# Whom:					Max Brazhnikov <makc@issp.ac.ru>
#
# $FreeBSD$
#

PORTNAME=	xephyr
PORTVERSION=	1.5.3
CATEGORIES=	x11-servers

MAINTAINER=	x11@FreeBSD.org
COMMENT=	A kdrive based X server from X.Org

XORG_CAT=	xserver

LIB_DEPENDS=	drm:${PORTSDIR}/graphics/libdrm

USE_GL=		gl
USE_XORG=	x11 xf86driproto glproto randrproto renderproto fixesproto \
		damageproto xcmiscproto xtrans inputproto \
		xf86bigfontproto scrnsaverproto bigreqsproto \
		resourceproto fontsproto videoproto \
		compositeproto trapproto recordproto \
		xineramaproto evieproto xkbfile xfont \
		xau xdmcp xext fontenc xv pixman

CONFIGURE_ARGS=	--enable-kdrive --enable-xephyr	--disable-dmx --disable-xvfb \
		--disable-xorg --disable-xnest --disable-xprint \
		--localstatedir=/var --without-dtrace

PLIST_FILES=	bin/Xephyr

OPTIONS=	HAL	"Compile with HAL config support" on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_HAL)
LIB_DEPENDS+=	hal.1:${PORTSDIR}/sysutils/hal
CONFIGURE_ARGS+=	--enable-config-hal=yes
.else
CONFIGURE_ARGS+=	--enable-config-hal=no
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hw/kdrive/ephyr/Xephyr ${PREFIX}/bin/

.include <bsd.port.post.mk>
