# $FreeBSD$

PORTNAME=	xf86-video-ati
PORTVERSION=	${ATI_VERSION}
PORTREVISION=	${ATI_REVISION}
CATEGORIES=	x11-drivers

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org ati display driver

USE_GL=		gl
XORG_CAT=	driver
USE_XORG=	xf86driproto xineramaproto xf86miscproto glproto

.include <bsd.port.options.mk>

.if ${OSVERSION} < 1000051 || !defined(WITH_NEW_XORG)
ATI_VERSION=	6.14.6
ATI_REVISION=	1
CONFIGURE_ARGS+=--disable-kms
PLIST_SUB+=	OLD=""
.else
ATI_VERSION=	7.2.0
ATI_REVISION=	1
CONFIGURE_ARGS+=--disable-udev
EXTRA_PATCHES+=	${FILESDIR}/extra-src__radeon_kms.c
PLIST_SUB+=	OLD="@comment "
.endif

.include <bsd.port.mk>
