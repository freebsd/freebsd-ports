# $FreeBSD$

PORTNAME=	xf86-video-via
PORTVERSION=	0.2.2
PORTREVISION=	9
CATEGORIES=	x11-drivers

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org via display driver

IGNORE=		requires pciVideoPtr typedef

USE_GL=		gl
XORG_CAT=	driver
USE_XORG=	xvmc xf86driproto xextproto x11 glproto

MAN4=		via.4x

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
IGNORE=		does not install on sparc64
.endif

.include <bsd.port.post.mk>
