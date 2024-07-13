PORTNAME=	meshoptimizer
DISTVERSIONPREFIX=	v
DISTVERSION=	0.21
CATEGORIES=	misc python

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Mesh optimization library
WWW=		https://github.com/zeux/meshoptimizer

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		cmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	zeux

CMAKE_ON=	MESHOPT_BUILD_SHARED_LIBS

.include <bsd.port.mk>
