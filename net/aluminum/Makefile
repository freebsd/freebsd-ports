# $FreeBSD$

PORTNAME=	Aluminum
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.0
CATEGORIES=	net

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Generic interface to high-performance communication libraries

LICENSE=	APACHE20

LIB_DEPENDS=	libhwloc.so:devel/hwloc \
		libmpi.so:net/openmpi

USES=		cmake compiler:c11
USE_GITHUB=	yes
GH_ACCOUNT=	LLNL
USE_LDCONFIG=	yes

LDFLAGS+=	-lexecinfo

.include <bsd.port.mk>
