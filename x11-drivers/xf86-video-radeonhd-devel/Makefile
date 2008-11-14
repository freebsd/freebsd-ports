# New ports collection makefile for:	xf86-video-radeonhd-devel
# Date Created:				2008-09-07
# Whom:					nork@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	xf86-video-radeonhd
PORTVERSION=	1.2.3.20081114
CATEGORIES=	x11-drivers
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	nork
PKGNAMESUFFIX=	-devel

MAINTAINER=	nork@FreeBSD.org
COMMENT=	X.Org ati RadeonHD display driver development version

BUILD_DEPENDS=	${LOCALBASE}/share/aclocal/xorg-macros.m4:${PORTSDIR}/devel/xorg-macros

OPTIONS=	UTILS "Install rhd_conntest and rhd_dump utilities" off

XORG_CAT=	driver
USE_XORG=	damageproto videoproto xextproto xf86driproto
USE_AUTOTOOLS=	aclocal:19 autoconf:262 libtool:15

CONFLICT=	xf86-video-radeonhd-[0-9]*

MAN4=		radeonhd.4x

# EXA is usable rather than XAA.  DRI is not usable in this time.
CONFIGURE_ARGS=	--enable-exa --disable-dri
ACLOCAL_ARGS=   --acdir=${LOCALBASE}/share/aclocal

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
