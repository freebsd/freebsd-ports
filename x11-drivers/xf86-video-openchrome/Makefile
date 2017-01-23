# $FreeBSD$

PORTNAME=	xf86-video-openchrome
PORTVERSION=	0.5.0
CATEGORIES=	x11-drivers

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org openChrome display driver

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libdrm.so:graphics/libdrm

USE_GL=		gl

XORG_CAT=	driver
USE_XORG=	x11 xext xv

MAKE_ARGS+=	drivermandir=${LOCALBASE}/man/man4

.include <bsd.port.options.mk>

# XvMC is only supported by this driver on x86
.if ${ARCH} == "i386" || ${ARCH} == "amd64"
USE_XORG+=	xvmc
PLIST_SUB+=	XVMC=""
.else
PLIST_SUB+=	XVMC="@comment "
.endif

.include <bsd.port.mk>
