# $FreeBSD$

PORTNAME=	xf86-video-vmware
PORTVERSION=	13.2.1
PORTREVISION=	1
CATEGORIES=	x11-drivers

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org vmware display driver

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

XORG_CAT=	driver

ONLY_FOR_ARCHS=	i386 amd64
ONLY_FOR_ARCHS_REASON=	The vmware gfx protocol is only supported on x86-compatible architectures.

.include <bsd.port.mk>
