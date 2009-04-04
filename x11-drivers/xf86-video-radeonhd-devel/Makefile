# New ports collection makefile for:	xf86-video-radeonhd-devel
# Date Created:				2008-09-07
# Whom:					nork@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	xf86-video-radeonhd
PORTVERSION=	1.2.4.20090301
PORTREVISION=	1
CATEGORIES=	x11-drivers
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	nork
PKGNAMESUFFIX=	-devel

MAINTAINER=	nork@FreeBSD.org
COMMENT=	X.Org ati RadeonHD display driver development version

BUILD_DEPENDS=	${LOCALBASE}/share/aclocal/xorg-macros.m4:${PORTSDIR}/devel/xorg-macros \
		${LOCALBASE}/libdata/pkgconfig/gl.pc:${PORTSDIR}/graphics/libGL

BROKEN=		does not compile

.if !exists(${LOCALBASE}/lib/libpci.so.2)
OPTIONS=	UTILS "Install rhd_conntest and rhd_dump utilities" off
.else
WITH_UTILS=	yes
.endif

XORG_CAT=	driver
USE_XORG=	damageproto videoproto xextproto xf86driproto
USE_AUTOTOOLS=	aclocal:19 autoconf:262 libtool:15

CONFLICTS=	xf86-video-radeonhd-[0-9]* xf86-video-ati-[0-9]*

MAN4=		radeonhd.4x

ACLOCAL_ARGS=	--acdir=${LOCALBASE}/share/aclocal

pre-configure:
	cd ${WRKSRC} && ${AUTORECONF} -i

.include <bsd.port.pre.mk>

.if defined(WITH_UTILS)
LIB_DEPENDS+=	pci.2:${PORTSDIR}/devel/libpci
PLIST_SUB=	UTILS=""
CONFIGURE_ENV+=	PCIUTILS_CFLAGS="-I${LOCALBASE}/include" \
		PCIUTILS_LIBS="-L${LOCALBASE}/lib -lpci -lz"
.else
PLIST_SUB=	UTILS="@comment "
.endif

.if defined(WITH_UTILS)
post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/utils/conntest/rhd_conntest ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/utils/conntest/rhd_dump ${PREFIX}/sbin
.endif

.include <bsd.port.post.mk>
