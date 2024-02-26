PORTNAME=	xf86-input-vmmouse
PORTVERSION=	13.1.0
PORTREVISION=	7
CATEGORIES=	x11-drivers

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org vmmouse input driver
WWW=		https://www.x.org/

USES=		gmake xorg-cat:driver

GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

ONLY_FOR_ARCHS=	i386 amd64
ONLY_FOR_ARCHS_REASON=	vmmouse protocol is only supported on x86-compatible architectures

.include <bsd.port.mk>
