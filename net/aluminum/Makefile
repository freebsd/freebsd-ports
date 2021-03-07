# $FreeBSD$

PORTNAME=	Aluminum
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.0
CATEGORIES=	net

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Generic interface to high-performance communication libraries

LICENSE=	APACHE20

LIB_DEPENDS=	libhwloc.so:devel/hwloc2 \
		libmpi.so:net/openmpi

USES=		cmake compiler:c11
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	LLNL

LDFLAGS+=	-lexecinfo

.include <bsd.port.mk>
