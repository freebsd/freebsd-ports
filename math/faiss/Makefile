PORTNAME=	faiss
DISTVERSIONPREFIX=	v
DISTVERSION=	1.7.1
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for efficient similarity search & clustering of dense vectors

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	openblas>0:math/openblas # faiss links with libopenblasp-rN.N.N.so (installed by default only on amd64,i386), so use non-filename-specific DEPENDS commands
RUN_DEPENDS=	openblas>0:math/openblas

USES=		cmake:testing compiler:c++11-lang

USE_GITHUB=	yes
GH_ACCOUNT=	facebookresearch

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	BUILD_TESTING FAISS_ENABLE_GPU FAISS_ENABLE_PYTHON

.include <bsd.port.mk>
