# Created by: Rene Ladan <r.c.ladan@gmail.com>
# $FreeBSD$

PORTNAME=	xf86-video-radeonhd
PORTVERSION=	1.3.0
PORTREVISION=	5
CATEGORIES=	x11-drivers

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org ati RadeonHD display driver

OPTIONS_DEFINE=	UTILS
UTILS_DESC=	Install rhd_conntest and rhd_dump utilities

XORG_CAT=	driver
USE_XORG=	damageproto glproto videoproto xextproto xf86driproto
CONFIGURE_ARGS=	--enable-exa
CONFLICTS=	xf86-video-radeonhd-devel-[0-9]*

MAN4=	radeonhd.4x

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MUTILS}
LIB_DEPENDS+=	pci:${PORTSDIR}/devel/libpci
PLIST_SUB=	UTILS=""
CONFIGURE_ENV+=	PCIUTILS_CFLAGS="-I${LOCALBASE}/include -lpci -lz" \
		PCIUTILS_LIBS="-L${LOCALBASE}/lib"
.else
PLIST_SUB=	UTILS="@comment "
.endif

.if ${PORT_OPTIONS:MUTILS}
post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/utils/conntest/rhd_conntest ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/utils/conntest/rhd_dump ${PREFIX}/sbin
.endif

.include <bsd.port.mk>
