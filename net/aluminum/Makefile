# $FreeBSD$

PORTNAME=	Aluminum
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.3
PORTREVISION=	1
CATEGORIES=	net

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Generic interface to high-performance communication libraries

LICENSE=	APACHE20

LIB_DEPENDS=	libhwloc.so:devel/hwloc \
		libmpi.so:net/openmpi

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	LLNL
USE_LDCONFIG=	yes

LDFLAGS+=	-lexecinfo

.include <bsd.port.mk>
