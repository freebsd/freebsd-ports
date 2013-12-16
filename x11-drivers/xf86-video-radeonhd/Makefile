# Created by: Rene Ladan <r.c.ladan@gmail.com>
# $FreeBSD$

PORTNAME=	xf86-video-radeonhd
PORTVERSION=	1.3.0
PORTREVISION=	6
CATEGORIES=	x11-drivers

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org ati RadeonHD display driver

OPTIONS_DEFINE=	UTILS
UTILS_DESC=	Install rhd_conntest and rhd_dump utilities

XORG_CAT=	driver
USE_XORG=	damageproto glproto videoproto xextproto xf86driproto
CONFIGURE_ARGS=	--enable-exa
CONFLICTS=	xf86-video-radeonhd-devel-[0-9]*

IGNORE=		Reports of issues with KMS, unsupported, use xf86-video-ati.
DEPRECATED=	Abandond upstream since 2010
EXPIRATION_DATE=2014-02-28

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
	${INSTALL_PROGRAM} ${WRKSRC}/utils/conntest/rhd_conntest ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/utils/conntest/rhd_dump ${STAGEDIR}${PREFIX}/sbin
.endif

.include <bsd.port.mk>
