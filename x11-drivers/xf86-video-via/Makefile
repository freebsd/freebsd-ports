# $FreeBSD$

PORTNAME=	xf86-video-via
PORTVERSION=	0.2.2
PORTREVISION=	10
CATEGORIES=	x11-drivers

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org via display driver

BROKEN=		Does not build, requires pciVideoPtr typedef
DEPRECATED=	Broken, not supported upstream.
EXPIRATION_DATE=2014-01-31

USE_GL=		gl
XORG_CAT=	driver
USE_XORG=	xvmc xf86driproto xextproto x11 glproto

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
IGNORE=		does not install on sparc64
.endif

.include <bsd.port.post.mk>
