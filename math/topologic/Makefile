PORTNAME=	topologic
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.0-21
DISTVERSIONSUFFIX=	-gae5ad5d
CATEGORIES=	math
PKGNAMESUFFIX=	-space-modeling-library

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for topological representations of architectural spaces

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libTKernel.so:cad/opencascade \
		libuuid.so:misc/e2fsprogs-libuuid

USES=		cmake localbase:ldflags
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	wassimj
GH_PROJECT=	Topologic

CMAKE_ARGS=	-DOCC_INCLUDE_DIR=${LOCALBASE}/include/OpenCASCADE

.include <bsd.port.mk>
