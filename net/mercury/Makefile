PORTNAME=	mercury
DISTVERSIONPREFIX=	v
DISTVERSION=	2.3.1
CATEGORIES=	net
PKGNAMESUFFIX=	-rpc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C library for implementing RPC, optimized for HPC
WWW=		https://mercury-hpc.github.io/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libjson-c.so:devel/json-c

USES=		cmake:testing
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	mercury-hpc
GH_TUPLE=	mercury-hpc:kwsys:ee35b49:kwsys/Testing/driver/kwsys \
		mercury-hpc:mchecksum:a4c489d:mchecksum/src/mchecksum \
		mercury-hpc:preprocessor:749783c:preprocessor/src/boost

CMAKE_ON=	BUILD_SHARED_LIBS

.if !exists(/usr/include/byteswap.h)
BROKEN=		needs /usr/include/byteswap.h
.endif

.include <bsd.port.mk>
