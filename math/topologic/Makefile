PORTNAME=	topologic
DISTVERSIONPREFIX=	v
DISTVERSION=	6.0.3
PORTREVISION=	4
CATEGORIES=	math
PKGNAMESUFFIX=	-space-modeling-library

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for topological representations of architectural spaces
WWW=		https://topologic.app/

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libtbb.so:devel/onetbb \
		libTKernel.so:cad/opencascade \
		libuuid.so:misc/libuuid

USES=		cmake compiler:c++14-lang localbase:ldflags
USE_LDCONFIG=	${PREFIX}/lib/TopologicCore

USE_GITHUB=	yes
GH_ACCOUNT=	wassimj
GH_PROJECT=	Topologic

CMAKE_ARGS=	-DOCC_INCLUDE_DIR=${LOCALBASE}/include/OpenCASCADE

.include <bsd.port.mk>
