# $FreeBSD$

PORTNAME=	xf86-video-ati
PORTVERSION=	${ATI_VERSION}
CATEGORIES=	x11-drivers

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org ati display driver

USE_GL=		gl
XORG_CAT=	driver
USE_XORG=	xf86driproto xineramaproto xf86miscproto glproto
MAN4=		ati.4x radeon.4x

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${OSVERSION} < 1000051
ATI_VERSION=	6.14.6
CONFIGURE_ARGS+=--disable-kms
PLIST_SUB+=	OLD=""
.else
ATI_VERSION=	7.2.0
CONFIGURE_ARGS+=--disable-udev
EXTRA_PATCHES+=	${FILESDIR}/extra-src__radeon_kms.c
PLIST_SUB+=	OLD="@comment "
.endif

.include <bsd.port.post.mk>
